#include "PlayerMove.h"

#include "Player.h"
#include "PlayerComponent.h"
player::PlayerMove::PlayerMove(PlayerComponent* player)
    : player_(player) {}

void player::PlayerMove::Start() {
  body_ = player_->PhysicsBody();
  is_idle_ = false;
  is_jump_ = false;
  is_sneak_ = false;
  if(player_->GetAnimator()->ChangeMotion("Move"))
  {
    int n = 3;
  }
}

void player::PlayerMove::Update() {
  if (body_->GetForce().x == 0.0f) is_idle_ = true;
}

void player::PlayerMove::ProcessInput() {
  body_->SetForceX(player_->GetHorizontal() * kSpeed);

  is_sneak_ = player_->IsSneakKey();
  is_jump_ = player_->IsJumpKey();
}

void player::PlayerMove::End() {}
