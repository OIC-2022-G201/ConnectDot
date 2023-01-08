#include "TransmitterComponent.h"

#include "ConnectBind.h"
#include "Game.h"
#include "ReceiverComponent.h"
#include "SendManifold.h"

TransmitterComponent::TransmitterComponent(base_engine::Actor* owner,
                                           int update_order)
    : Component(owner, update_order) {}

TransmitterComponent::~TransmitterComponent() = default;

void TransmitterComponent::Start()
{
  if (!connect_bindable_) {
    CreateConnectBind<ConnectBind>();
  }
}

void TransmitterComponent::Update() {
  const auto weak_ptr = owner_->GetComponent<TransmitterComponent>();

  for (const auto& receiver_weak : target_) {
    if (receiver_weak.expired()) continue;
    if (receiver_weak.lock()->Level() > Level()) continue;
    if (CoercionCondition(receiver_weak)) {
      receiver_weak.lock()->Connecting(weak_ptr);
    }
  }
  ConnectBind bind;
  std::erase_if(target_, [](const std::weak_ptr<ReceiverComponent>& a) {
    return a.expired();
  });
  std::erase_if(target_, [&weak_ptr, this](
                             const std::weak_ptr<ReceiverComponent>& a) {
                  return connect_bindable_->Constraints(a, weak_ptr);
                });
  for (const auto& value : target_) {
    connect_bindable_->BindConnect(value.lock(), weak_ptr);
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

bool TransmitterComponent::CoercionCondition(
    const std::weak_ptr<ReceiverComponent>& receiver_weak) {
  return (!receiver_weak.lock()->IsWireless() ||
          receiver_weak.lock()->Sequential() < 0);
}
