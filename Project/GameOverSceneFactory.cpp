﻿#include "GameOverSceneFactory.h"

#include <fstream>

#include "BinaryArchive.h"
#include "ButtonListener.h"
#include "ButtonPressEvent.h"
#include "ButtonSelecter.h"
#include "CameraComponent.h"
#include "EventBus.h"
#include "GameoverComponent.h"
#include "InputManager.h"
#include "ResourceContainer.h"
#include "SceneManager.h"
#include "UiFactoryUtilities.h"
#include "UiFrozen.h"
#include "UiPackage.h"
#include "VariantFrozen.h"
#include "VectorFrozen.h"

using namespace base_engine;
using RC = ResourceContainer;

auto ButtonCreateA(Game* game, ButtonSelecter* selector,
    const ButtonFrozenPack& button_data) {
    const auto button_pack =
        RC::GetResource<ResourceContainer::ButtonResourcePack,
        ButtonResourcePackage>(button_data.path);
    const auto button = new Button(game);
    button->SetButtonSprite(button_pack->sprites[0]);
    button->SetChangeButtonSprite(button_pack->sprites[1]);
    button->SetPosition({ button_data.x, button_data.y });
    selector->ButtonRegister(button_data.tx, button_data.ty, button);
    const struct {
        Button* button;
        ButtonSelecter* selector;
    } result = { button, selector };
    return result;
}

void GameOverSceneFactory::Factory() {
  const auto actor = new Actor(game_);
  new CameraComponent(actor);

  const auto input_actor = new InputActor(game_);
  const auto input = new InputManager(input_actor);

  new ButtonListener(actor);
  const auto selector = new ButtonSelecter(game_);
  selector->SetInput(input);
  
  const auto image = new ImageComponent(actor);
  const auto sprite_resource =
      RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("Gameover");
  image->SetImage(*sprite_resource);

  const std::vector<std::tuple<Vector2, std::string, std::function<void()>>>
      main_pack = {
        {{475, 732}, "RetryButton", [] {scene::LoadScene(scene::kGame); }},
  	    {{1039, 732}, "GiveupButton", [] {scene::LoadScene(scene::kTitle); }},
      };
  for (int i = 0; i < main_pack.size(); ++i) {
      const auto& [pos, name, action] = main_pack[i];
      const auto [button, _] = ButtonCreateA(
          game_, selector, ButtonFrozenPack{ pos.x, pos.y, name, i, 0 });
      button->SetEvent(action);
  }

  const auto component = new GameoverComponent(new Actor(game_));
}