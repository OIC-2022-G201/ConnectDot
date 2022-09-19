#include "TransmitterComponent.h"

#include "ReceiverComponent.h"
#include "SendManifold.h"

TransmitterComponent::TransmitterComponent(base_engine::Actor* owner,
                                           int update_order)
    : Component(owner, update_order) {}

TransmitterComponent::~TransmitterComponent() = default;

void TransmitterComponent::Start() {}

void TransmitterComponent::Update() {
  for (const auto target : target_) {
    target->Connecting(this);
  }
  target_.clear();
}

void TransmitterComponent::OnCollision(
    const base_engine::SendManifold& manifold) {

  if (auto target = manifold.collision_b->GetActor()
                        ->GetComponent<ReceiverComponent>();
      target != nullptr && target->CanConnect() && transmitter_->CanSending()) {
    target_.emplace_front(target);
  }
}

base_engine::Vector2 TransmitterComponent::GetPosition() const
{
  return owner_->GetPosition() + transmitter_->GetPosition();
}
