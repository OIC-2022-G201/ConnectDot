#include "PlayerJump.h"

#include "Player.h"
#include "PlayerComponent.h"

#include <numbers>
player::PlayerJump::PlayerJump(PlayerComponent* player) : player_(player) {}

void player::PlayerJump::Start() {
  is_idle_ = false;
  frame_ = 0;
  player_->AddVelocityY(-2);
}

void player::PlayerJump::Update() {
  //d/dx(sin((ƒÎ x)/60)~45) = 3/4 ƒÎ cos((ƒÎ x)/60)
  frame_++;

  if (frame_ > 60) {
    frame_ = 60;
  }
  JumpSetVelocity();
}

void player::PlayerJump::ProcessInput()
{
  player_->SetVelocityX(player_->GetHorizontal() * kSpeed);
}

void player::PlayerJump::End() {}

void player::PlayerJump::OnEvent(base_engine::CollisionComponent* collision)
{
    if (collision->GetActor()->GetTag() == "Field")
    {
        auto block_top = collision->AABB().Top;
        auto p_bottom = player_->GetCollision()->AABB().Bottom;
        auto diff = block_top - p_bottom;
        if (player_->GetVelocity().y > 0&&diff<0)      is_idle_ = true;
    }
}

void player::PlayerJump::JumpSetVelocity()
{
    const float velocity = 5 * std::numbers::pi_v<float> *
                           cos((std::numbers::pi_v<float> * frame_) / 60);
    player_->SetVelocityY(-velocity - kGravity);
  
}
