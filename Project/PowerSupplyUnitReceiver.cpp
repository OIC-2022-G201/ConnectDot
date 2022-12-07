#include "PowerSupplyUnitReceiver.h"

#include "Actor.h"
#include "ElectronicsPower.h"
#include "PowerSupplyUnitActor.h"
#include "ReceiverComponent.h"
#include "TransmitterComponent.h"

int PowerSupplyUnitReceiver::Sequential() { return sequential_; }

bool PowerSupplyUnitReceiver::PowerJoinCondition() { return true; }

void PowerSupplyUnitReceiver::OnPowerEnter(TransmitterComponent* transmitter) {
  if (!target_) {
    target_ = actor_->GetTarget();
  }
  if (!target_) return;
  receiver_ = target_->GetComponent<ReceiverComponent>();
  if (transmitter) {
    if (const auto receiver =
            transmitter->GetOwner().lock()->GetComponent<ReceiverComponent>();
        !receiver.expired()) {
      sequential_ = receiver.lock()->Sequential();
    }
  }
  actor_->SetElectricPower(true);
  sender_->AddTarget(receiver_);
}

void PowerSupplyUnitReceiver::OnPowerChanged(
    TransmitterComponent* transmitter) {
  if (!target_) return;

  sender_->AddTarget(receiver_);
}

void PowerSupplyUnitReceiver::OnPowerExit(TransmitterComponent* transmitter) {
  sequential_ = -1;
  if (!target_) return;

  actor_->SetElectricPower(false);
  receiver_.reset();
}

bool PowerSupplyUnitReceiver::IsWireless() { return true; }

base_engine::Vector2 PowerSupplyUnitReceiver::GetPosition() const {
  return electronics::psu::kPowerSupplyUnitReceiverOffset;
}
