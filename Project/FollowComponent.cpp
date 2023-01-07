#include "FollowComponent.h"

#include "VectorUtilities.h"
FollowComponent::FollowComponent(base_engine::Actor* owner) : Component(owner) {
  offset_ = base_engine::Vector2{0, -64 - 32};
}

void FollowComponent::Update() {
  if (actor_weak_.expired()) return;

  const auto actor = actor_weak_.lock();
  const auto actor_pos = actor->GetPosition() + offset_;
  base_engine::Vector2 current_pos = owner_->GetPosition();
  base_engine::Vector2 targetDirection = (actor_pos - current_pos);

  interp_velocity_ =
      base_engine::VectorUtilities::Length(targetDirection) * 5.0f;

  target_pos_ =
      current_pos + (base_engine::VectorUtilities::Normalize(targetDirection) *
                     interp_velocity_ * 0.017f);

  const auto move_pos = base_engine::Vector2{
      std::lerp(current_pos.x, target_pos_.x, 0.6f),
      std::lerp(current_pos.y, target_pos_.y,
                current_pos.y > target_pos_.y ? 0.2f : 0.6f)};
  owner_->SetPosition(move_pos);
}
