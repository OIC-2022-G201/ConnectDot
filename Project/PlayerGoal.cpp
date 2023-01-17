#include "PlayerGoal.h"

#include "Player.h"
#include "PlayerComponent.h"
namespace player {
PlayerGoal::PlayerGoal(PlayerComponent* player) : player_(player) {}

void PlayerGoal::Start() {
  body_ = player_->PhysicsBody();
  player_->GetAnimator()->ChangeMotion("Move");
}

void PlayerGoal::Update()
{
  body_->SetForceX(kSpeed);
  player_->MovedLookAt();
}

void PlayerGoal::ProcessInput() {}

void PlayerGoal::End() {}
}  // namespace player