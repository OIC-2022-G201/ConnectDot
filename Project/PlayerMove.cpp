#include "PlayerMove.h"

#include "Player.h"
#include "PlayerComponent.h"
player::PlayerMove::PlayerMove(PlayerComponent* player) : player_(player) {}

void player::PlayerMove::Start() {
  is_idle_ = false;
  is_jump_ = false;
  is_sneak_ = false;
}

void player::PlayerMove::Update() {
  if (player_->GetVelocity().x == 0.0f) is_idle_ = true;
}

void player::PlayerMove::ProcessInput() {
  player_->SetVelocityX(player_->GetHorizontal() * kSpeed);

  is_sneak_ = player_->IsSneakKey();
  is_jump_ = player_->IsJumpKey();
}

void player::PlayerMove::End() {}
