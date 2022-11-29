#include "PlayerVentAction.h"
#include "CollisionLayer.h"
PlayerVentAction::PlayerVentAction(PlayerComponent* player)
{ player_ = player; }

void PlayerVentAction::Start()
{
  collider_->SetObjectFilter(CollisionLayer::kNone);
}

void PlayerVentAction::Update()
{}

void PlayerVentAction::ProcessInput()
{}

void PlayerVentAction::End()
{}

template <typename Machine>
void PlayerVentAction::Transition(Machine& machine) const
{}
