#include "PlayerSneakMove.h"

#include "Player.h"
#include "PlayerComponent.h"

player::PlayerSneakMove::PlayerSneakMove(PlayerComponent* player) : player_(player)
{
      
}

void player::PlayerSneakMove::Start()
{
  body_ = player_->PhysicsBody();
  is_jump_ = false;
  is_move_ = false;
  is_idle_ = false;
  player_->GetAnimator()->ChangeMotion("CrouchingMove");
  player_->MovedLookAt();
}

void player::PlayerSneakMove::Update()
{
      
}

void player::PlayerSneakMove::ProcessInput()
{
  body_->SetForceX(player_->GetHorizontal() * kSneakSpeed);

  if (!player_->IsSneakKey()) is_idle_ = true;
  is_move_ = player_->GetHorizontal() != 0.0f;
  is_jump_ = player_->IsJumpKey();
}

void player::PlayerSneakMove::End()
{
      
}

