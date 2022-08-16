#include "PlayerJump.h"

#include "Player.h"
#include "PlayerComponent.h"
#include <numbers>
#include "CollisionComponent.h"

namespace player::detail {

constexpr uint16_t kMaxFrame = 60;

template <std::floating_point Floating>
constexpr Floating kJumpCoefficient = static_cast<Floating>(
    -1.0 / 12.0 * std::numbers::pi_v<Floating> * std::numbers::pi_v<Floating>);

template <std::floating_point Floating>
constexpr Floating kTimeCoefficient =
    static_cast<Floating>(std::numbers::pi_v<Floating> / kMaxFrame);
}  // namespace player::detail

player::PlayerJump::PlayerJump(PlayerComponent* player) : player_(player) {}

void player::PlayerJump::Start() {
  is_idle_ = false;
  frame_ = 0;
  player_->AddVelocityY(-16);
}

void player::PlayerJump::Update() {
  frame_++;

  if (frame_ > detail::kMaxFrame) {
    frame_ = detail::kMaxFrame;
  }
  Acceleration();
}

void player::PlayerJump::ProcessInput() {
  player_->SetVelocityX(player_->GetHorizontal() * kSpeed);
}

void player::PlayerJump::End() {}

void player::PlayerJump::OnEvent(base_engine::CollisionComponent* collision) {
  if (collision->GetActor()->GetTag() == "Field") {
    auto block_top = collision->AABB().Top;
    auto p_bottom = player_->GetCollision()->AABB().Bottom;
    auto diff = block_top - p_bottom;
    if (player_->GetVelocity().y > 0 && diff < 0) is_idle_ = true;
  }
}

void player::PlayerJump::Acceleration() const {
  const float velocity = detail::kJumpCoefficient<float> *
                         sin(frame_ * detail::kTimeCoefficient<float>);
  if (frame_==60)
  {
    int n = 3;
  }
  player_->AddVelocityY(-kGravity - velocity);
}
