#include "ElevatorReceiver.h"

#include "ElevatorComponent.h"

ElevatorReceiver::ElevatorReceiver(ElevatorComponent* elevator,
                                   base_engine::Actor* owner)
    : elevator_(elevator), owner_(owner) {}

int ElevatorReceiver::Sequential() { return 1000; }

bool ElevatorReceiver::PowerJoinCondition() { return true; }

void ElevatorReceiver::OnPowerEnter(TransmitterComponent* transmitter)
{
  elevator_->SetElectric(true);
}

void ElevatorReceiver::OnPowerChanged(TransmitterComponent* transmitter)
{
	
}

void ElevatorReceiver::OnPowerExit(TransmitterComponent* transmitter)
{
  elevator_->SetElectric(false);
}

bool ElevatorReceiver::IsWireless() { return false; }

base_engine::Vector2 ElevatorReceiver::GetPosition() const { return {}; }
