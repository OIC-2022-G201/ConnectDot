#include "UiFactoryUtilities.h"

#include "AudioStreamComponent.h"
#include "ResourceContainer.h"

using namespace base_engine;
using RC = ResourceContainer;

std::pair<base_engine::Actor*, base_engine::ImageComponent*>
UiFactoryUtilities::ImageCreate(base_engine::Game* game, std::string_view key) {
  const auto actor = new Actor(game);
  const auto image = new ImageComponent(actor);
  const auto sprite_resource =
      RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(key.data());
  image->SetImage(*sprite_resource);
  return {actor, image};
}

std::pair<Button*, ButtonSelecter*> UiFactoryUtilities::ButtonCreate(
    base_engine::Game* game, ButtonSelecter* selector,
    const ButtonFrozenPack& button_data,int draw_order)
{
  const auto button_pack =
      RC::GetResource<ResourceContainer::ButtonResourcePack,
                      ButtonResourcePackage>(button_data.path);
  const auto button = new Button(game, draw_order);
  button->SetButtonSprite(button_pack->sprites[0]);
  button->SetChangeButtonSprite(button_pack->sprites[1]);
  button->SetPosition({button_data.x, button_data.y});
  selector->ButtonRegister(button_data.tx, button_data.ty, button);
  {
    const auto audio = new AudioStreamComponent(button);
    audio->AssetLoad("DeterministicSE");
    button->SetEvent([audio] { audio->Play(); });
  }
  {
    const auto audio = new AudioStreamComponent(button);
    audio->AssetLoad("CursorMoveSE");
    button->SetHoverEvent([audio] { audio->Play(); });
  }
  return {button, selector};
}


