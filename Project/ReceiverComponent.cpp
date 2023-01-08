#include "ReceiverComponent.h"

#include "ElectricEffect.h"
#include "Game.h"
#include "ResourceContainer.h"
#include "SparkEffectActor.h"
#include "TransmitterComponent.h"
constexpr size_t kMaxWaitFrame = 10;
using RC = ResourceContainer;
ReceiverComponent::~ReceiverComponent() {
  owner_->GetGame()->RemoveActor(effect_.lock().get());
}

void ReceiverComponent::OnPowerExit() {
  current_state_ = PowerState::kDisconnect;
  prev_state_ = PowerState::kDisconnect;
  wait_frame_++;
  receiver_->OnPowerExit(sender_.lock().get());
  sender_.reset();
  if (effect_.expired()) return;
  const auto effect = std::dynamic_pointer_cast<ElectricEffect>(effect_.lock());
  effect->Hide();
}

void ReceiverComponent::OnPowerEnter() {
  if (receiver_->IsWireless()) {
    if (effect_.expired()) {
      ECreate();
    } else {
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

void ReceiverComponent::OnPowerChanged() const {
  receiver_->OnPowerChanged(sender_.lock().get());
}

bool ReceiverComponent::CanConnectCheck(
    const std::weak_ptr<TransmitterComponent>& sender_weak) const {
  if (!sender_.expired() && !sender_weak.expired()) return false;
  if (sender_.lock().get() != sender_weak.lock().get()) return false;
  return IsConnect();
}

bool ReceiverComponent::IsWireless() const { return receiver_->IsWireless(); }

int ReceiverComponent::Sequential() const { return receiver_->Sequential(); }

base_engine::Vector2 ReceiverComponent::GetPosition() const {
  return owner_->GetPosition() + receiver_->GetPosition();
}

bool ReceiverComponent::IsConnect() const {
  if (current_state_ != PowerState::kDisconnect || wait_frame_ != 0)
    return true;
  return false;
}

bool ReceiverComponent::EqualSender(
    const std::weak_ptr<TransmitterComponent>& sender_weak) const {
  if (sender_.expired() || sender_weak.expired()) return false;
  return sender_.lock().get() == sender_weak.lock().get();
}

int ReceiverComponent::Level() const { return level_; }

void ReceiverComponent::SetLevel(const int level) { level_ = level; }

ReceiverComponent::ReceiverComponent(base_engine::Actor* owner,
                                     int update_order)
    : Component(owner, update_order) {}

void ReceiverComponent::Start() {
  //    flow_spark_animation_->Load();
}

void ReceiverComponent::Update() {
  if (current_state_ == PowerState::kConnecting &&
      prev_state_ == PowerState::kDisconnect) {
    prev_state_ = PowerState::kDisconnected;
  }
  if (current_state_ == PowerState::kDisconnect && wait_frame_ != 0) {
    wait_frame_++;
    if (wait_frame_ > kMaxWaitFrame) {
      prev_state_ = PowerState::kDisconnect;
      wait_frame_ = 0;
    }
    return;
  }
  if (wait_frame_ != 0) {
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

bool ReceiverComponent::Disconnect() {
  if (sender_.expired()) return false;
  current_state_ = PowerState::kDisconnect;
  prev_state_ = PowerState::kDisconnect;
  receiver_->OnPowerExit(sender_.lock().get());
  sender_.reset();
  if (effect_.expired()) return true;
  const auto effect = std::dynamic_pointer_cast<ElectricEffect>(effect_.lock());
  effect->Hide();
  return true;
}

void ReceiverComponent::Connecting(
    const std::weak_ptr<TransmitterComponent> sender_weak) {
  if (sender_weak.expired()) return;
  const auto sender = sender_weak.lock();
  if (sender_.expired()) {
    sender_ = sender;
  }

  if (sender_.lock()->GetOwner().expired()) return;
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

std::weak_ptr<base_engine::Actor> ReceiverComponent::GetSenderActor() const {
  if (sender_.expired()) {
    return {};
  }
  return sender_.lock()->GetOwner();
}

void ReceiverComponent::FlowSparkEffect() const {
  const auto effect = new SparkEffectActor(owner_->GetGame());
  effect->Create(GetPosition(), "SparkEffect");
  effect->Play();
}
