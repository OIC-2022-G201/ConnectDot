#include "PlayerJump.h"

#include <numbers>

#include "CollisionComponent.h"
#include "Player.h"
#include "PlayerComponent.h"
#include "PlayerStateConst.h"
#include "PlayerStateUtility.h"

using namespace player::jump;
player::PlayerJump::PlayerJump(PlayerComponent* player) : player_(player) {}

void player::PlayerJump::Start() {
  body_ = player_->PhysicsBody();
  is_ground_ = false;
  is_sneak_ = false;
  frame_ = 0;
  body_->AddForce({0, -16});
  player_->GetAnimator()->ChangeMotion("Jump");

}

void player::PlayerJump::Update() {
  frame_++;

  if (frame_ > player_->GetJumpTime()) {
    frame_ = player_->GetJumpTime();
  }
  if (frame_>3)
  {
    is_ground_ = player_->IsGround();
  }
  is_fall_ = frame_ > player_->GetJumpTime() / 2;
  Acceleration();
  player_->MovedLookAt();
}

void player::PlayerJump::ProcessInput() {
  body_->SetForceX(player_->GetHorizontal() * kSpeed);
  if (player_->IsSneakKey()) is_sneak_ = true;
}

void player::PlayerJump::End() {}

void player::PlayerJump::Acceleration() const {
  const float velocity =
      CalculationJumpAcceleration(player_->GetJumpHeight(),player_->GetJumpTime(),frame_);
  if (frame_ == player_->GetJumpTime()) {
    if (body_->GetForce().v < 3) return;
  }
  body_->AddForce({0, -kGravity - velocity});
}
