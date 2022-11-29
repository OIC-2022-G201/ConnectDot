#include "PlayerSneak.h"

#include "PlayerComponent.h"
player::PlayerSneak::PlayerSneak(PlayerComponent* player) : player_(player) {}

void player::PlayerSneak::Start() {
  body_ = player_->PhysicsBody();
  body_->SetForceX(0);
  is_jump_ = false;
  is_move_ = false;
  is_idle_ = false;
  player_->GetAnimator()->ChangeMotion("Crouching");
  player_->MovedLookAt();
}

void player::PlayerSneak::Update() {}

void player::PlayerSneak::ProcessInput() {
  if (!player_->IsSneakKey()) is_idle_ = true;
  is_move_ = player_->GetHorizontal() != 0.0f;
  is_jump_ = player_->IsJumpKey();
}

void player::PlayerSneak::End() {}
