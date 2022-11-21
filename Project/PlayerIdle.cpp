#include "PlayerIdle.h"

#include "BeaconActor.h"
#include "PlayerComponent.h"
#include "GridSnapComponent.h"
player::PlayerIdle::PlayerIdle(PlayerComponent* player) : player_(player) {}

void player::PlayerIdle::Start() {
  body_ = player_->PhysicsBody();
  is_jump_ = false;
  is_move_ = false;
  is_sneak_ = false;
}

void player::PlayerIdle::Update() {
  if (player_->IsPlaceBeaconKey() && player_->GetBeacon() > 0) {
    player_->SetBeacon(player_->GetBeacon() - 1);
    const auto beacon = new BeaconActor(player_->GetGame());
    auto grid = beacon->GetComponent<grid::GridSnapComponent>().lock();
    auto pos = GridPosition::VectorTo(player_->GetOwner()->GetPosition());
    pos.x += 1;
    pos.y += 1;
      grid->SetSnapGridPosition(pos);
    beacon->SetSequential((player_->MaxBeacon() - player_->GetBeacon()) * 10);
  }
}

void player::PlayerIdle::ProcessInput() {
  is_jump_ = player_->IsJumpKey();
  is_move_ = player_->GetHorizontal() != 0 || body_->GetForce().x != 0;
  is_sneak_ = player_->IsSneakKey();
}

void player::PlayerIdle::End() {}
