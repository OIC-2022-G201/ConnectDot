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
#include "NinePatchImageComponent.h"
#include "ResourceContainer.h"
#include "TitleListener.h"
#include "UiFrozen.h"
#include "UiPackage.h"
#include "VariantFrozen.h"
#include "VectorFrozen.h"
using namespace base_engine;
using RC = ResourceContainer;
auto ImageCreate(Game* game, std::string_view key) {
  const auto actor = new Actor(game);
  const auto image = new ImageComponent(actor);
  const auto sprite_resource =
      RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(key.data());
  image->SetImage(*sprite_resource);
  const struct {
    Actor* owner;
    ImageComponent* image;
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
// TODO ボタンパッケージの管理方法をタグ付けなどにする
void TitleSceneFactory::Factory() {
  const auto camera = new Actor(game_);
  new CameraComponent(camera);

  const auto input_actor = new InputActor(game_);
  const auto input = new InputManager(input_actor);
  std::vector<PackageVariant> packages;
  {
    std::ifstream stream("Meta/Scene/Scene.bin", std::ios::binary);
    frozen::BinaryInputArchive archive(stream);
    archive(packages);
  }
  new ButtonListener(new Actor(game_));
  const auto selector = new ButtonSelecter(game_);
  selector->SetInput(input);
  for (const auto& package : packages) {
    if (std::holds_alternative<ImageFrozenPack>(package)) {
      const auto& [x, y, path] = std::get<ImageFrozenPack>(package);
      const auto [owner, image] = ImageCreate(game_, path);
      owner->SetPosition({x, y});
    } else {
      const auto& button_pack = std::get<ButtonFrozenPack>(package);
      const auto [button, _] = ButtonCreate(game_, selector, button_pack);
      button->SetEvent([button_pack, button]() {
        auto any = std::any(button);
        ButtonPressEvent e(any, button_pack.event_name);
        EventBus::FireEvent(e);
      });
    }
  }

  new TitleComponent(new Actor(game_));
  return;
}
