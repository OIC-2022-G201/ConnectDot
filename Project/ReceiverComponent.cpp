#include "ReceiverComponent.h"

#include "ElectricEffect.h"
#include "Game.h"
#include "TransmitterComponent.h"

ReceiverComponent::~ReceiverComponent()
{
  owner_->GetGame()->RemoveActor(effect_.lock().get());
}

void ReceiverComponent::OnPowerExit()
{
	current_state_ = PowerState::kDisconnect;
	prev_state_ = PowerState::kDisconnect;
	receiver_->OnPowerExit(sender_.lock().get());
        if (effect_.expired())return;
	const auto effect = std::dynamic_pointer_cast<ElectricEffect>(effect_.lock());
	effect->OffSprite();
}

void ReceiverComponent::OnPowerEnter() {
  if (receiver_->IsWireless()) {
    if (effect_.expired())
    {
      ECreate();
    }
    const auto effect =
        std::dynamic_pointer_cast<ElectricEffect>(effect_.lock());
    effect->Play(sender_.lock()->GetPosition(), GetPosition());
  }
  receiver_->OnPowerEnter(sender_.lock().get());
  current_state_ = PowerState::kConnecting;
}

ReceiverComponent::ReceiverComponent(base_engine::Actor* owner,
                                     int update_order)
    : Component(owner, update_order) {}

void ReceiverComponent::Start() {
 
  
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

void ReceiverComponent::ECreate()
{
	auto actor = new ElectricEffect(owner_->GetGame());
  effect_ = owner_->GetGame()->GetActor(actor->GetId());
}
