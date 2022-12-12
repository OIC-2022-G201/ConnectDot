﻿#include "FollowCameraComponent.h"

#include "VectorUtilities.h"
FollowCameraComponent::FollowCameraComponent(base_engine::Actor* owner)
    : Component(owner) {}

void FollowCameraComponent::Update() {
  if (actor_weak_->expired()) return;

  const auto actor = actor_weak_->lock();
  const auto actor_pos = actor->GetPosition();
  base_engine::Vector2 current_pos = owner_->GetPosition();
  base_engine::Vector2 targetDirection = (actor_pos - current_pos);

  interp_velocity_ =
      base_engine::VectorUtilities::Length(targetDirection) * 5.0f;

  target_pos_ =
      current_pos + (base_engine::VectorUtilities::Normalize(targetDirection) *
                     interp_velocity_ * 0.017f);

  const auto move_pos =
      Mof::CVector2Utilities::Lerp(current_pos, target_pos_ + offset_, 0.25f);
  owner_->SetPosition(move_pos);
}
