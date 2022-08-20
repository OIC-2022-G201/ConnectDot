#include "TransmitterComponent.h"

#include "SendManifold.h"

TransmitterComponent::TransmitterComponent(base_engine::Actor* owner,
                                           int update_order)
    : Component(owner, update_order) {}

TransmitterComponent::~TransmitterComponent() = default;

void TransmitterComponent::Start() {}

void TransmitterComponent::Update() {
  for (auto target : target_) {
    target->Connecting();
  }
  target_.clear();
}

void TransmitterComponent::OnCollision(
    const base_engine::SendManifold& manifold) {
  auto name = manifold.collision_b->GetActor()->GetName();
  // collision->GetActor()->GetComponent<>()
  int n = 3;
  if (auto target = manifold.collision_b->GetActor()
                        ->GetComponent<ReceiverComponent>();
      target != nullptr && target->CanConnect()) {
    target_.emplace_back(target);
  }
}
