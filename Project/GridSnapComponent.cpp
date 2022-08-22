#include "GridSnapComponent.h"

#include "Actor.h"
#include "StageConstitution.h"

using base_engine::Vector2;
using namespace grid;

GridSnapComponent& GridSnapComponent::SetSnapGridPosition(
    const GridPosition& position) {
  const auto fix_position = GridPosition::GridTo(position);
  owner_->SetPosition(fix_position);
  return *this;
}

void GridSnapComponent::Update() {
  if (!auto_snap_.getBool()) return;
  SetSnapGridPosition(GridPosition::VectorTo(owner_->GetPosition()));
}

GridSnapComponent::GridSnapComponent(base_engine::Actor* owner,
                                     int update_order)
    : Component(owner, update_order) {}

GridSnapComponent& GridSnapComponent::SetAutoSnap(AutoSnap snap) {
  auto_snap_ = snap;
  return *this;
}
