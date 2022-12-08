#include "TitleSceneFactory.h"

#include "Actor.h"
#include "Button.h"
#include "ButtonSelecter.h"
#include "CameraComponent.h"
#include "IBaseEngineTexture.h"
#include "ImageComponent.h"
#include "InputManager.h"
#include "ResourceContainer.h"
#include "UiPackage.h"
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
auto ButtonCreate(Game* game, InputManager* input,
                  const std::string_view key1) {
  auto button_pack =
      RC::GetResource<ResourceContainer::ButtonResourcePack, ButtonPackage>(
          key1.data());

  const auto button = new Button(game);
  button->SetButtonSprite(button_pack->sprites[0]);
  button->SetChangeButtonSprite(button_pack->sprites[1]);
  const auto selector = new ButtonSelecter(game);

  selector->ButtonRegister(0, 0, button);
  selector->SetInput(input);
  const struct {
    Button* button;
    ButtonSelecter* selector;
  } result = {button, selector};
  return result;
}
auto ButtonCreate(Game* game, ButtonSelecter* selector,
                  const std::string_view key1) {
  auto button_pack =
      RC::GetResource<ResourceContainer::ButtonResourcePack, ButtonPackage>(
          key1.data());
  const auto button = new Button(game);
  button->SetButtonSprite(button_pack->sprites[0]);
  button->SetChangeButtonSprite(button_pack->sprites[1]);
  button->SetPosition({0, 120});
  selector->ButtonRegister(0, 1, button);
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
  {
    const auto [owner, image] = ImageCreate(game_, "TitleLogo");
    owner->SetPosition({300, 300});
  }
  {
    const auto [button, selector] =
        ButtonCreate(game_, input, "StartGameButton");
    button->SetPosition({725, 600});
    const auto button2 = ButtonCreate(game_, selector, "QuitGameButton");

    button2.button->SetPosition({725, 700});
  }
}
