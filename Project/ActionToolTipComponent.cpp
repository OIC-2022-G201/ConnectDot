#include "ActionToolTipComponent.h"

#include "PositionYTween.h"
#include "ResourceContainer.h"
#include "SpriteAlphaTween.h"
#include "SpriteComponent.h"
#include "StageConstitution.h"
using RC = ResourceContainer;
using namespace base_engine;
std::weak_ptr<ActionToolTipComponent> ActionToolTipComponent::Create(
    Actor* owner, const std::weak_ptr<IMachineActionable>& machine) {
  if (const auto tooltip = owner->GetComponent<ActionToolTipComponent>();
      !tooltip.expired()) {
    return tooltip;
  }
  const auto tooltip_component = new ActionToolTipComponent(owner);

  const auto tooltip = new Actor(owner->GetGame());
  owner->AddChild(tooltip->GetId());
  
  tooltip_component->panel_ = owner->GetGame()->GetActor(tooltip->GetId());
  tooltip_component->sprite_ = new SpriteComponent(tooltip, 200);
  const auto img =
      *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("ActionTooltip");
  tooltip->SetPosition(owner->GetPosition() + Vector2{64, -32});
  tooltip_component->sprite_->SetAlignment(Mof::TEXALIGN_CENTERCENTER)
      .SetColor(MOF_ARGB(0, 255, 255, 255))
      .SetImage(img);
  return owner->GetComponent<ActionToolTipComponent>();
}

constexpr float kFadeInTime = 0.25f;
constexpr float kFadeOutTime = 0.25f;

void ActionToolTipComponent::Show() {
  open_ = true;
  if (play_animation_) return;
  if (is_show_) return;
  if (panel_.expired()) return;

  play_animation_ = true;
  ma_tween::PositionYTween::Tween(
      panel_.lock().get(), owner_->GetPosition().y - stage::kStageCellSize<float>.y * 0.5f,
      kFadeInTime)
      .SetEase(EaseType::kInsine);
  ma_tween::SpriteAlphaTween::Tween(panel_.lock().get(), 255, kFadeInTime)
      .SetOnComplete([this]
      {
        is_show_ = true;
      	play_animation_ = false;
      });
}

void ActionToolTipComponent::Hide() {
  if (play_animation_) return;
  if (!is_show_) return;
  if (panel_.expired())return;
  play_animation_ = true;
  ma_tween::PositionYTween::Tween(
      panel_.lock().get(), owner_->GetPosition().y + 32,
      kFadeOutTime)
      .SetEase(EaseType::kInsine);
  ma_tween::SpriteAlphaTween::Tween(panel_.lock().get(), 0, kFadeOutTime)
      .SetOnComplete([this] {
        is_show_ = false;
	      play_animation_ = false;
      });
}

void ActionToolTipComponent::Update() {
  if (open_ == false) {
    count_frame_++;
    if (count_frame_ > 5) {
      Hide();
    }
  } else {
    count_frame_ = 0;
  }
  open_ = false;
}
