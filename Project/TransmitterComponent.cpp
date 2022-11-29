#include "TransmitterComponent.h"

#include "Game.h"
#include "ReceiverComponent.h"
#include "SendManifold.h"

TransmitterComponent::TransmitterComponent(base_engine::Actor* owner,
                                           int update_order)
    : Component(owner, update_order) {}

TransmitterComponent::~TransmitterComponent() = default;

void TransmitterComponent::Start() {}

void TransmitterComponent::Update() {
  const auto weak_ptr = owner_->GetComponent<TransmitterComponent>();
  if (!target_.empty()) {
    int n = 3;
  }

    
  std::erase_if(target_, [](const std::weak_ptr<ReceiverComponent>& a) {
    return a.expired();
  });
  std::erase_if(target_, [&weak_ptr](const std::weak_ptr<ReceiverComponent>& a)
  {
    return a.lock()->IsConect() == true && !a.lock()->EqualSender(weak_ptr);
  });
  const auto target = std::ranges::min_element(
      target_, [](const std::weak_ptr<ReceiverComponent>& a,
                  const std::weak_ptr<ReceiverComponent>& b) {
        return a.lock()->Sequential() < b.lock()->Sequential();
      });
  if (target != target_.end()) {
    target->lock()->Connecting(weak_ptr);
  }
  
  
  for (const auto& target : target_) {
    if (target.expired()) continue;

    target.lock()->Connecting(weak_ptr);
  }
  target_.clear();
}

void TransmitterComponent::OnCollision(
    const base_engine::SendManifold& manifold) {
  auto id = manifold.collision_b->GetActor()->GetId();
  if (owner_->GetGame()->GetActor(id).expired()) return;
  AddTarget(
      manifold.collision_b->GetActor()->GetComponent<ReceiverComponent>());
}

bool TransmitterComponent::AddTarget(
    const std::weak_ptr<ReceiverComponent> target_weak) {
  if (target_weak.expired()) return false;
  auto target = target_weak.lock().get();
  if (target != nullptr && target->CanConnect() && transmitter_->CanSending()) {
    target_.emplace_front(target_weak);
    return true;
  }
  return false;
}

base_engine::Vector2 TransmitterComponent::GetPosition() const {
  return owner_->GetPosition() + transmitter_->GetPosition();
}
