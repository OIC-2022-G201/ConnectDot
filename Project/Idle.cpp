#include "Idle.h"

#include "PlayerComponent.h"
player::Idle::Idle(PlayerComponent* player): player_(player)
{
      
}

void player::Idle::Start()
{}

void player::Idle::Update()
{}

void player::Idle::ProcessInput() {
  is_jump_ = player_->input_manager_->JumpFire();
}

void player::Idle::End()
{}

