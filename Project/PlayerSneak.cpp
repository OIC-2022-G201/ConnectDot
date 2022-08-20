#include "PlayerSneak.h"

#include "Player.h"
#include "PlayerComponent.h"
player::PlayerSneak::PlayerSneak(PlayerComponent* player)
    : player_(player) {}

void player::PlayerSneak::Start() {
  body_ = player_->PhysicsBody();
  is_jump_ = false;
  is_move_ = false;
  is_idle_ = false;
}

void player::PlayerSneak::Update() {}

void player::PlayerSneak::ProcessInput() {
  body_->SetForceX(player_->GetHorizontal() * kSneakSpeed);
  if (!player_->IsSneakKey()) is_idle_ = true;
  is_move_ = (!player_->IsSneakKey()) && (player_->GetHorizontal() != 0.0f);
  is_jump_ = player_->IsJumpKey();
}

void player::PlayerSneak::End() {}
