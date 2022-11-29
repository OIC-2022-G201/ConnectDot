#include "ReceiverComponent.h"

#include "ElectricEffect.h"
#include "TransmitterComponent.h"

void ReceiverComponent::OnPowerEnter() {
  if (receiver_->IsWireless()) {
    effect_->Play(sender_.lock()->GetPosition(), GetPosition());
  }
  receiver_->OnPowerEnter(sender_.lock().get());
  current_state_ = PowerState::kConnecting;
}

ReceiverComponent::ReceiverComponent(base_engine::Actor* owner,
                                     int update_order)
    : Component(owner, update_order) {}

void ReceiverComponent::Start() {
  effect_ = new ElectricEffect(owner_->GetGame());
  effect_->SetReceiver(this);
}

void ReceiverComponent::Connecting(
    const std::weak_ptr<TransmitterComponent> sender_weak) {
  if (sender_weak.expired()) return;
  const auto sender = sender_weak.lock();

  if (!sender_.expired()) {
  } else {
    sender_ = sender;
  }
  if (prev_state_ != PowerState::kDisconnect) return;
  switch (current_state_) {
    case PowerState::kDisconnected:
      break;
    case PowerState::kDisconnect:
      current_state_ = PowerState::kConnect;
      break;
    case PowerState::kConnect:
      current_state_ = PowerState::kConnecting;
    case PowerState::kConnecting:
      break;
    default:;
  }
  prev_state_ = current_state_;
  return;
}
