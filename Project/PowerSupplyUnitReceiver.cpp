﻿#include "PowerSupplyUnitReceiver.h"

#include "Actor.h"
#include "ElectronicsPower.h"
#include "PowerSupplyUnitActor.h"
#include "ReceiverComponent.h"
#include "ResourceContainer.h"
#include "TransmitterComponent.h"
using RC = ResourceContainer;
using namespace base_engine;
int PowerSupplyUnitReceiver::Sequential() { return sequential_; }

bool PowerSupplyUnitReceiver::PowerJoinCondition() { return true; }

void PowerSupplyUnitReceiver::OnPowerEnter(TransmitterComponent* transmitter) {
  if (targets_.empty()) {
    targets_ = actor_->GetTarget();
  }
  const auto img = *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
      actor_->IsFly() ? "AirPowerSupplyOn" : "PowerSupplyOn");
  actor_->GetComponent<SpriteComponent>().lock()->SetImage(img);
  if (targets_.empty()) return;
  receivers_.clear();

  if (transmitter) {
    if (const auto receiver =
            transmitter->GetOwner().lock()->GetComponent<ReceiverComponent>();
        !receiver.expired()) {
      sequential_ = receiver.lock()->Sequential();
    }
  }
  actor_->SetElectricPower(true);
  std::ranges::transform(targets_, std::back_inserter(receivers_),
                         [](const base_engine::Actor* actor) {
                           return actor->GetComponent<ReceiverComponent>();
                         });

  for (const auto& weak_ptr : receivers_) {
    sender_->AddTarget(weak_ptr);
  }
}

void PowerSupplyUnitReceiver::OnPowerChanged(
    TransmitterComponent* transmitter) {
  if (targets_.empty()) return;

  for (const auto& weak_ptr : receivers_) {
    sender_->AddTarget(weak_ptr);
  }
}

void PowerSupplyUnitReceiver::OnPowerExit(TransmitterComponent* transmitter) {
  sequential_ = -1;
  const auto img = *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
      actor_->IsFly() ? "AirPowerSupplyOff" : "PowerSupplyOff");
  actor_->GetComponent<SpriteComponent>().lock()->SetImage(img);
  if (targets_.empty()) return;

  actor_->SetElectricPower(false);
  receivers_.clear();
}

bool PowerSupplyUnitReceiver::IsWireless() { return true; }

base_engine::Vector2 PowerSupplyUnitReceiver::GetPosition() const {
  return electronics::psu::kPowerSupplyUnitReceiverOffset;
}
