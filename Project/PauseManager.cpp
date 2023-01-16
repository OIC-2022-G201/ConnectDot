#include "PauseManager.h"

#include <ranges>

#include "Actor.h"
#include "ButtonSelecter.h"
#include "EventBus.h"
#include "EventHandler.h"
#include "ImageComponent.h"
#include "InputManager.h"
#include "PauseComponent.h"
#include "PauseEvent.h"
#include "ResourceContainer.h"
#include "UiFactoryUtilities.h"
#include "UiFrozen.h"

using RC = ResourceContainer;
using namespace base_engine;

class PauseManager::PauseListener : public EventHandler<PauseEvent> {
  PauseManager* pause_manager_ = nullptr;
  Game* game_;
  std::unordered_map<std::string, Actor*> elements_;
  Actor* back_;

 public:
  explicit PauseListener(PauseManager* manager, Game* game)
      : pause_manager_(manager), game_(game) {
    CreateView();
  }

  void OnEvent(PauseEvent& e) override {
    pause_manager_->is_open_ = e.IsOpen();
    if (e.IsOpen()) {
      HideView();
    } else {
      ShowView();
    }
  }

 private:
  void CreateView() {
    {
      back_ = new Actor(game_);
      const auto image = new ImageComponent(back_, 3000);
      image->SetImage(
          *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("PauseHaikei"));
      back_->SetEnable(false);
    }
    { CreateButtons(); }
  }
  void ShowView() {
    back_->SetEnable(true);
    for (const auto& element : elements_ | std::views::values) {
      element->SetEnable(true);
    }
  }
  void HideView() {
    back_->SetEnable(false);
    for (const auto& element : elements_ | std::views::values) {
      element->SetEnable(false);
    }
  }

  void CreateButtons() {
    constexpr bool enable = false;
    const std::vector<std::tuple<Vector2, std::string, std::function<void()>>>
        main_pack = {{{796, 394}, "ResumeButton", [] { PostQuitMessage(0); }},
                     {{781, 533}, "RestartButton", [] { PostQuitMessage(0); }},
                     {{828, 671}, "GoTitleButton", [] { PostQuitMessage(0); }}};

    const auto selector = new ButtonSelecter(game_);
    selector->SetInput(InputManager::Instance());
    selector->SetEnable(enable);
    elements_.emplace("selector", selector);

    for (int i = 0; i < main_pack.size(); ++i) {
      const auto& [pos, name, action] = main_pack[i];
      const auto [button, _] = UiFactoryUtilities::ButtonCreate(
          game_, selector, ButtonFrozenPack{pos.x, pos.y, name, 0, i}, 3001);
      elements_.emplace(name, button);
      button->SetEvent(action);
      button->SetEnable(enable);
    }
  }
};
PauseManager::PauseManager(Game* game) : game_(game) {
  new PauseComponent(new Actor(game));
  listener_ = std::make_unique<PauseListener>(this, game);
  event_handlers_.emplace_back(EventBus::AddHandler<PauseEvent>(*listener_));
}

PauseManager::~PauseManager() = default;
