#include "GameOverSceneFactory.h"

#include <fstream>

#include "BinaryArchive.h"
#include "ButtonListener.h"
#include "ButtonPressEvent.h"
#include "ButtonSelecter.h"
#include "CameraComponent.h"
#include "EventBus.h"
#include "InputManager.h"
#include "UiFactoryUtilities.h"
#include "UiFrozen.h"
#include "UiPackage.h"
#include "VariantFrozen.h"
#include "VectorFrozen.h"
using namespace base_engine;
void GameOverSceneFactory::Factory() {
  const auto camera = new Actor(game_);
  new CameraComponent(camera);

  const auto input_actor = new InputActor(game_);
  const auto input = new InputManager(input_actor);
  std::vector<PackageVariant> packages;
  {
    std::ifstream stream("Meta/Scene/GameOver.bin", std::ios::binary);
    frozen::BinaryInputArchive archive(stream);
    archive(packages);
  }
  new ButtonListener(new Actor(game_));
  const auto selector = new ButtonSelecter(game_);
  selector->SetInput(input);
  for (const auto& package : packages) {
    if (std::holds_alternative<ImageFrozenPack>(package)) {
      const auto& [x, y, path] = std::get<ImageFrozenPack>(package);
      const auto [owner, image] = UiFactoryUtilities::ImageCreate(game_, path);
      owner->SetPosition({x, y});
    } else {
      const auto& button_pack = std::get<ButtonFrozenPack>(package);
      const auto [button, _] =
          UiFactoryUtilities::ButtonCreate(game_, selector, button_pack);
      button->SetEvent([button_pack, button]() {
        auto any = std::any(button);
        ButtonPressEvent e(any, button_pack.event_name);
        EventBus::FireEvent(e);
      });
    }
  }
}
