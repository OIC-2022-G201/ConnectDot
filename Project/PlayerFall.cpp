#include "PlayerFall.h"

#include <Mof.h>

#include "OneTimeEffectActor.h"
#include "Player.h"
#include "PlayerComponent.h"
#include "PlayerStateConst.h"
#include "PlayerStateUtility.h"

using namespace player::jump;
player::PlayerFall::PlayerFall(PlayerComponent* player) : player_(player) {}

void player::PlayerFall::Start() {
  body_ = player_->PhysicsBody();
  is_ground_ = false;
  is_sneak_ = false;

  // 加速度計算式で使用するがジャンプの中間時点から再生するため最大値を２で割る
  frame_ = player_->GetJumpTime() / 2;
  player_->GetAnimator()->ChangeMotion("Jump", false);
}

void player::PlayerFall::Update() {
  frame_++;

  if (frame_ > player_->GetJumpTime()) {
    frame_ = player_->GetJumpTime();
  }
  Acceleration();
  player_->MovedLookAt();
  is_ground_ = player_->IsGround();
}

void player::PlayerFall::ProcessInput() {
  body_->SetForceX(player_->GetHorizontal() * kSpeed);
  if (player_->IsSneakKey()) is_sneak_ = true;
}

void player::PlayerFall::End() {


  if (player_->IsRight())
  {
    const auto effect =
        OneTimeEffectActor::Create(player_->GetOwner()->GetGame(),
                                   player_->GetOwner()->GetPosition() +
                                       base_engine::Vector2{128-16, 256 - 32},
                                   "Dust", 160);
      effect->GetComponent<base_engine::SpriteComponent>().lock()->SetFlip(
          base_engine::Flip::kHorizontal);
  }else
  {
    const auto effect =
        OneTimeEffectActor::Create(player_->GetOwner()->GetGame(),
                                   player_->GetOwner()->GetPosition() +
                                       base_engine::Vector2{128+16, 256 - 32},
                                   "Dust", 160);
  }
}

void player::PlayerFall::Acceleration() const {
  float velocity = CalculationJumpAcceleration(
      player_->GetJumpHeight(), player_->GetJumpTime(), frame_);
  if (frame_ == kMaxFrame && body_->GetForce().y > 10) {
    if (body_->GetForce().v < 15) return;
  }
  if (frame_ >= player_->GetJumpTime() && velocity > -0.1)
  {
    velocity = -0.2f;
  }
  body_->AddForce({0, -kGravity - velocity});
}
