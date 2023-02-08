#include "GameOverSceneFactory.h"

#include <fstream>

#include "AudioStreamComponent.h"
#include "BinaryArchive.h"
#include "ButtonListener.h"
#include "ButtonPressEvent.h"
#include "ButtonSelecter.h"
#include "CameraComponent.h"
#include "ComponentServiceLocator.h"
#include "EventBus.h"
#include "GameOverComponent.h"
#include "ITransitionFadeSystem.h"
#include "ImageAlphaTween.h"
#include "InputManager.h"
#include "PositionYTween.h"
#include "ResourceContainer.h"
#include "SceneManager.h"
#include "TransitionParameter.h"
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
  button->GetComponent<ImageComponent>().lock()->SetColor(uint32_t(0x00ffffff));
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

  const struct {
    Button* button;
    ButtonSelecter* selector;
  } result = {button, selector};
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

  const auto component = new GameOverComponent(actor);

  const auto logo = new Actor(game_);
  logo->SetPosition({356, 0});
  const auto logo_image = new ImageComponent(logo);
  const auto logo_resource =
      RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("GameoverLogo");
  logo_image->SetImage(*logo_resource);
  component->SetLogo(logo);

  {
    const auto haikei = new ImageComponent(new Actor(game_), 10);
    const auto haike_imgi =
        RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("GameoverHaikei");
    haikei->SetImage(*haike_imgi);
  }

  const std::vector<std::tuple<Vector2, std::string, std::function<void()>>>
      main_pack = {
          {{475, 732},
           "RetryButton",
           [] {
             ServiceLocator::Instance()
                 .Resolve<ITransitionFadeSystem>()
                 ->SceneTransition(scene::kGame, kGameOverToGameFadeIn,
                                   kGameOverToGameFadeOut);
           }},
          {{1039, 732},
           "GiveupButton",
           [] {
             ServiceLocator::Instance()
                 .Resolve<ITransitionFadeSystem>()
                 ->SceneTransition(scene::kTitle, kGameOverToTitleFadeIn,
                                   kGameOverToTitleFadeOut);
           }},
      };
  for (int i = 0; i < main_pack.size(); ++i) {
    const auto& [pos, name, action] = main_pack[i];
    const auto [button, _] = ButtonCreateA(
        game_, selector, ButtonFrozenPack{pos.x, pos.y, name, i, 0});
    button->SetEvent(action);
    component->SetButton(button);
  }
}