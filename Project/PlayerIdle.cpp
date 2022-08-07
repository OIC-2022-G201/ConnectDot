#include "PlayerIdle.h"

#include "PlayerComponent.h"
player::PlayerIdle::PlayerIdle(PlayerComponent* player): player_(player)
{
      
}

void player::PlayerIdle::Start()
{}

void player::PlayerIdle::Update()
{}

void player::PlayerIdle::ProcessInput() {
  is_jump_ = player_->input_manager_->JumpFire();
}

void player::PlayerIdle::End()
{}

