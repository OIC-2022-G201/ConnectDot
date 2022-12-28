#include "ReceiverComponent.h"

#include "ElectricEffect.h"
#include "Game.h"
#include "TransmitterComponent.h"
constexpr size_t kMaxWaitFrame = 10;

ReceiverComponent::~ReceiverComponent() {
  owner_->GetGame()->RemoveActor(effect_.lock().get());
}

void ReceiverComponent::OnPowerExit() {
  current_state_ = PowerState::kDisconnect;
  prev_state_ = PowerState::kDisconnect;
  wait_frame_++;
  sender_.reset();
  receiver_->OnPowerExit(sender_.lock().get());
  if (effect_.expired()) return;
  const auto effect = std::dynamic_pointer_cast<ElectricEffect>(effect_.lock());
  effect->Hide();
}

void ReceiverComponent::OnPowerEnter() {
  if (receiver_->IsWireless()) {
    if (effect_.expired()) {
      ECreate();
    }else
    {
      const auto effect =
          std::dynamic_pointer_cast<ElectricEffect>(effect_.lock());
      effect->Show();

    }
    const auto effect =
        std::dynamic_pointer_cast<ElectricEffect>(effect_.lock());
    effect->SetTransmitter(sender_);
    effect->Play(sender_.lock()->GetPosition(), GetPosition());
  }
  receiver_->OnPowerEnter(sender_.lock().get());
  current_state_ = PowerState::kConnecting;
}

ReceiverComponent::ReceiverComponent(base_engine::Actor* owner,
                                     int update_order)
    : Component(owner, update_order) {}

void ReceiverComponent::Start() {}

void ReceiverComponent::Update() {
  if (current_state_ == PowerState::kConnecting &&
      prev_state_ == PowerState::kDisconnect) {
    prev_state_ = PowerState::kDisconnected;
  }
  if (current_state_ == PowerState::kDisconnect && wait_frame_ != 0) {
    wait_frame_++;
    if (wait_frame_ > kMaxWaitFrame)
    {
      prev_state_ = PowerState::kDisconnect;
        wait_frame_ = 0;
    }
      return;
  }
  if (wait_frame_ != 0)
  {
    prev_state_ = PowerState::kDisconnect;
    return;
  }
  switch (prev_state_) {
    case PowerState::kDisconnected:
      OnPowerExit();
      break;
    case PowerState::kConnect:
      OnPowerEnter();
      break;
    case PowerState::kConnecting:
      OnPowerChanged();
      break;
    case PowerState::kDisconnect:
      return;
      break;
    default:;
  }
  prev_state_ = PowerState::kDisconnect;
}

bool ReceiverComponent::CanConnect() const {
  return (current_state_ != PowerState::kDisconnected) &&
         receiver_->PowerJoinCondition();
}

void ReceiverComponent::Connecting(
    const std::weak_ptr<TransmitterComponent> sender_weak) {

  if (sender_weak.expired()) return;
  const auto sender = sender_weak.lock();

  if (sender_.expired()) {
      sender_ = sender;

  }
  if (prev_state_ != PowerState::kDisconnect) return;
  
  switch (current_state_) {
    case PowerState::kDisconnected:
      break;
    case PowerState::kDisconnect:
      wait_frame_ = 0;
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

void ReceiverComponent::ECreate() {
  auto actor = new ElectricEffect(owner_->GetGame());
  effect_ = owner_->GetGame()->GetActor(actor->GetId());
}
