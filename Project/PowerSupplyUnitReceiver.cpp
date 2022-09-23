#include "PowerSupplyUnitReceiver.h"
#include "ReceiverComponent.h"
#include "ElectronicsPower.h"
#include "PowerSupplyUnitActor.h"
#include "Actor.h"
#include "TransmitterComponent.h"

int PowerSupplyUnitReceiver::Sequential()
{ return 1000; }

bool PowerSupplyUnitReceiver::PowerJoinCondition()
{ return true; }

void PowerSupplyUnitReceiver::OnPowerEnter(TransmitterComponent* transmitter) {
  receiver_ = target_->GetComponent<ReceiverComponent>();
  actor_->SetElectricPower(true);
  sender_->AddTarget(receiver_);
  actor_->SetSequential(transmitter->Sequential()+5);
}

void PowerSupplyUnitReceiver::OnPowerChanged(TransmitterComponent* transmitter)
{
  sender_->AddTarget(receiver_);
}

void PowerSupplyUnitReceiver::OnPowerExit(TransmitterComponent* transmitter)
{
  actor_->SetElectricPower(false);
  receiver_ = nullptr;
}

bool PowerSupplyUnitReceiver::IsWireless()
{ return true; }

base_engine::Vector2 PowerSupplyUnitReceiver::GetPosition() const
{
    return electronics::psu::kPowerSupplyUnitReceiverOffset;
}
