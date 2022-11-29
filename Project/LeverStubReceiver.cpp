#include "LeverStubReceiver.h"

#include "LeverStubActor.h"
#include "TransmitterComponent.h"

LeverStubReceiver::LeverStubReceiver(LeverStubActor* actor): actor_(actor)
{}

int LeverStubReceiver::Sequential()
{ return 1000;
}

bool LeverStubReceiver::PowerJoinCondition()
{
    return true;
}

void LeverStubReceiver::OnPowerEnter(TransmitterComponent* transmitter)
{
  actor_->SetElectric(true);
}

void LeverStubReceiver::OnPowerChanged(TransmitterComponent* transmitter)
{
      
}

void LeverStubReceiver::OnPowerExit(TransmitterComponent* transmitter)
{
  actor_->SetElectric(false);
}

bool LeverStubReceiver::IsWireless()
{
    return false;
}

base_engine::Vector2 LeverStubReceiver::GetPosition() const
{ return {};
}

LeverStubTransmitter::LeverStubTransmitter(LeverStubActor* actor): actor_(actor)
{}

const ISendablePower* LeverStubTransmitter::GetPrevious()
{ return previous_; }

void LeverStubTransmitter::SetPrevious(ISendablePower* previous)
{ previous_ = previous; }

bool LeverStubTransmitter::CanSending()
{
    return static_cast<bool>(actor_->GetElectric());
}

base_engine::Vector2 LeverStubTransmitter::GetPosition() const
{ return {};
}

