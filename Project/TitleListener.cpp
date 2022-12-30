#include "TitleListener.h"

#include <ranges>

#include "ButtonPressEvent.h"
#include "ClipSizeXTween.h"
#include "ClipSizeYTween.h"
#include "EventBus.h"
#include "EventHandler.h"
#include "InputManager.h"
#include "NinePatchImageComponent.h"
class TitleComponent::TitleListener final
    : public EventHandler<ButtonPressEvent> {
 public:
  void OnEvent(ButtonPressEvent& press) override;
};
void TitleComponent::TitleListener::OnEvent(ButtonPressEvent& press) {}

TitleComponent::TitleComponent(base_engine::Actor* owner) : Component(owner) {}

void TitleComponent::Start() {
  listener_ = std::make_unique<TitleListener>();
  handle_ = EventBus::AddHandler(*listener_);
}

void TitleComponent::Update() {
  if (current_popup_ > 0) {
    if (InputManager::Instance()->ButtonHorizontal() < 0 && !popups_[current_popup_]->is_animation) {
      popups_[current_popup_]->Hide();
    	current_popup_ = 0;
      main_popup_.elements["selector"]->SetEnable(true);
    }
  }
}

void TitleComponent::Popup::Hide() {
  if (is_animation) return;
  is_animation = true;
  constexpr bool enable = false;

  const auto panel =
      popup_actor->GetComponent<base_engine::NinePatchImageComponent>();
  for (const auto& actor : this->elements | std::views::values) {
    actor->SetEnable(enable);
  }
  ma_tween::ClipSizeXTween::TweenClipSizeX(popup_actor, panel, 0, .5f)
      .SetEase(EaseType::kInoutcirc);
  ma_tween::ClipSizeYTween::TweenClipSizeY(popup_actor, panel, 0, .5f)
      .SetEase(EaseType::kInoutcirc)
      .SetOnComplete([this, panel] {
        is_animation = false;
        panel.lock()->SetEnabled(false);
      });
}

void TitleComponent::Popup::Show() {
  if (is_animation) return;
  is_animation = true;
  constexpr bool enable = true;

  const auto panel =
      popup_actor->GetComponent<base_engine::NinePatchImageComponent>();

  panel.lock()->SetEnabled(enable);
  panel.lock()->SetClipRect({0, 0, 0, 0});
  ma_tween::ClipSizeXTween::TweenClipSizeX(popup_actor, panel, size.x, .5f)
      .SetEase(EaseType::kInoutcirc);
  ma_tween::ClipSizeYTween::TweenClipSizeY(popup_actor, panel, size.y, .5f)
      .SetEase(EaseType::kInoutcirc)
      .SetOnComplete([this] {
        is_animation = false;
        for (const auto& actor : this->elements | std::views::values) {
          actor->SetEnable(enable);
        }
      });
}

void TitleComponent::OpenStageSelectPopup() {
  current_popup_ = 1;
  main_popup_.elements["selector"]->SetEnable(false);
  stage_select_popup_.Show();
}

void TitleComponent::CloseStageSelectPopup() { stage_select_popup_.Hide(); }
