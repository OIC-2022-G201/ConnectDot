#include "PlayerFall.h"

#include "Player.h"
#include "PlayerComponent.h"
#include "PlayerStateConst.h"

using namespace player::jump;
player::PlayerFall::PlayerFall(PlayerComponent* player) : player_(player) {}

void player::PlayerFall::Start() {
  body_ = player_->PhysicsBody();
  is_ground_ = false;
  is_sneak_ = false;

  // 加速度計算式で使用するがジャンプの中間時点から再生するため最大値を２で割る
  frame_ = kMaxFrame / 2;
  player_->GetAnimator()->ChangeMotion("Jump", false);
}

void player::PlayerFall::Update() {
  frame_++;

  if (frame_ > kMaxFrame) {
    frame_ = kMaxFrame;
  }
  Acceleration();
  player_->MovedLookAt();
  is_ground_ = player_->IsGround();
}

void player::PlayerFall::ProcessInput() {
  body_->SetForceX(player_->GetHorizontal() * kSpeed);
  if (player_->IsSneakKey()) is_sneak_ = true;
}

void player::PlayerFall::End() {}

void player::PlayerFall::Acceleration() const {
  const float velocity =
      kJumpCoefficient<float> * sin(frame_ * jump::kTimeCoefficient<float>);
  if (frame_ == kMaxFrame) {
    if (body_->GetForce().v < 15) return;
  }
  body_->AddForce({0, -kGravity - velocity});
}
