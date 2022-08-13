#include "PlayerIdle.h"

#include "PlayerComponent.h"
player::PlayerIdle::PlayerIdle(PlayerComponent* player) : player_(player) {}

void player::PlayerIdle::Start() {
  is_jump_ = false;
  is_move_ = false;
  is_sneak_ = false;
}

void player::PlayerIdle::Update() {}

void player::PlayerIdle::ProcessInput() {
  is_jump_ = player_->IsJumpKey();
  is_move_ = player_->GetHorizontal() != 0 || player_->GetVelocity().x != 0;
  is_sneak_ = player_->IsSneakKey();
}

void player::PlayerIdle::End() {}
