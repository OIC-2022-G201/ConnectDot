#include "TitleSceneFactory.h"

#include <fstream>

#include "Actor.h"
#include "BinaryArchive.h"
#include "Button.h"
#include "ButtonListener.h"
#include "ButtonPressEvent.h"
#include "ButtonSelecter.h"
#include "CameraComponent.h"
#include "EventBus.h"
#include "Frozen.h"
#include "GoalEffectActor.h"
#include "IBaseEngineTexture.h"
#include "ImageComponent.h"
#include "InputManager.h"
#include "MofSpriteAnimationComponent.h"
#include "NinePatchImageComponent.h"
#include "Rect.h"
#include "ResourceContainer.h"
#include "SpriteComponent.h"
#include "TitleListener.h"
#include "UiFrozen.h"
#include "UiPackage.h"
#include "VariantFrozen.h"
#include "VectorFrozen.h"
using namespace base_engine;
using RC = ResourceContainer;
auto ImageCreate(Game* game, std::string_view key, const size_t order = 100) {
  const auto actor = new Actor(game);
  const auto image = new ImageComponent(actor, order);
  const auto sprite_resource =
      RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(key.data());
  image->SetImage(*sprite_resource);
  const struct {
    Actor* owner;
    ImageComponent* image;
  } result = {actor, image};
  return result;
}
auto NinePatchCreate(Game* game, std::string_view key, const Vector2& lt,
                     const Vector2& rb, const size_t order = 100) {
  const auto actor = new Actor(game);
  const auto image = new NinePatchImageComponent(actor, order);
  const auto sprite_resource =
      RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(key.data());
  image->SetImage(*sprite_resource, lt, rb);
  const struct {
    Actor* owner;
    NinePatchImageComponent* image;
  } result = {actor, image};
  return result;
}
auto ButtonCreate(Game* game, ButtonSelecter* selector,
                  const ButtonFrozenPack& button_data) {
  const auto button_pack =
      RC::GetResource<ResourceContainer::ButtonResourcePack,
                      ButtonResourcePackage>(button_data.path);
  const auto button = new Button(game);
  button->SetButtonSprite(button_pack->sprites[0]);
  button->SetChangeButtonSprite(button_pack->sprites[1]);
  button->SetPosition({button_data.x, button_data.y});
  selector->ButtonRegister(button_data.tx, button_data.ty, button);
  const struct {
    Button* button;
    ButtonSelecter* selector;
  } result = {button, selector};
  return result;
}

void TitleSceneFactory::CreatePopup(
    InputManager* const input, const Rect& rect,
    const std::vector<std::tuple<Vector2, std::string, std::function<void()>>>
        main_pack,
    TitleComponent::Popup* const popup,bool enable) {
  const auto selector = new ButtonSelecter(game_);
  selector->SetInput(input);
  selector->CreateCursor(
      *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("Arrow"), 120,
      {-55, -2});
  selector->SetEnable(enable);
  popup->elements.emplace("selector", selector);
  const auto [actor, panel] =
      NinePatchCreate(game_, "Panel", {2, 2}, {126, 126}, 110);
  const Vector2 lt = rect.GetTopLeft();
  const Vector2 rb = rect.GetBottomRight();
  actor->SetPosition(lt);
  popup->size = {rb - lt};
  panel->SetClipRect({{0, 0},popup->size });
  popup->popup_actor = actor;
  panel->SetEnabled(enable);
  for (int i = 0; i < main_pack.size(); ++i) {
    const auto& [pos, name, action] = main_pack[i];
    const auto [button, _] = ButtonCreate(
        game_, selector, ButtonFrozenPack{pos.x, pos.y, name, 0, i});
    popup->elements.emplace(name, button);
    button->SetEvent(action);
    button->SetEnable(enable);
  }
}

// TODO ボタンパッケージの管理方法をタグ付けなどにする
void TitleSceneFactory::Factory() {
  const auto camera = new Actor(game_);
  new CameraComponent(camera);

  const auto title = new TitleComponent(new Actor(game_));
  const auto input_actor = new InputActor(game_);
  const auto input = new InputManager(input_actor);
  new ButtonListener(new Actor(game_));
  ImageCreate(game_, "TitleHaikei");
  {
    const auto actor = new Actor(game_);
    const auto sprite = new ImageComponent(actor, 110);

    const auto pack =
        RC::GetPack<RC::AnimationResourcePack>("TitleLightAnimation");
    const auto image = pack->Get<RC::Sprite>()->Get(0);
    sprite->SetImage(*image);

    const auto clip = pack->Get<RC::AnimationClips>()->Get(0);
    const auto animation = new MofSpriteAnimationComponent(actor);
    animation->Load(sprite, *clip);

    actor->SetPosition({1236, 258});
  }

  // MainPopup
  {
    const std::vector<std::tuple<Vector2, std::string, std::function<void()>>>
        main_pack = {
            {{212, 649}, "NewGameButton", {[title] {
               title->stage_select_popup_.Hide();
             }}},
            {{212, 737}, "StageSelectButton", {[title] {
               title->OpenStageSelectPopup();
             }}},
            {{212, 824}, "KeyGuideButton", {}},
            {{212, 913}, "TitleExitButton", {}},
        };
    const auto popup = &title->main_popup_;
    CreatePopup(input, {125, 570, 543, 1011}, main_pack, popup);
  }

  {
    const std::vector<std::tuple<Vector2, std::string, std::function<void()>>>
        main_pack = {{{670, 737}, "Stage1Button", {}},
                     {{670, 824}, "Stage2Button", {}},
                     {{670, 913}, "Stage3Button", {}}};
    const auto popup = &title->stage_select_popup_;
    CreatePopup(input, {583, 656, 891, 1011}, main_pack, popup,false);
  }
  return;
}
