#include "PlayerMove.h"

#include "Player.h"
#include "PlayerComponent.h"
player::PlayerMove::PlayerMove(PlayerComponent* player) : player_(player) {}

void player::PlayerMove::Start() {
  body_ = player_->PhysicsBody();
  is_idle_ = false;
  is_jump_ = false;
  is_sneak_ = false;
  is_fall_ = false;
  player_->GetAnimator()->ChangeMotion("Move");
  player_->MovedLookAt();
  player_->PlaySoundEffect();
}

void player::PlayerMove::Update() {
  if (body_->GetForce().x == 0.0f) is_idle_ = true;
  if (body_->GetForce().y > 4) is_fall_ = true;
}

void player::PlayerMove::ProcessInput() {
  body_->SetForceX(player_->GetHorizontal() * kSpeed);

  is_sneak_ = player_->IsSneakKey();
  is_jump_ = player_->IsJumpKey();
}

void player::PlayerMove::End()
{ player_->StopSoundEffect(); }
