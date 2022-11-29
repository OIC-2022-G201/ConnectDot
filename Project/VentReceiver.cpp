#include "VentReceiver.h"

#include "VentComponent.h"

VentReceiver::VentReceiver(VentActor* actor): actor_(actor)
{}

int VentReceiver::Sequential()
{ return -1; }

bool VentReceiver::PowerJoinCondition()
{ return true; }

void VentReceiver::OnPowerEnter(TransmitterComponent* transmitter)
{
  actor_->SetElectric(true);
}

void VentReceiver::OnPowerChanged(TransmitterComponent* transmitter)
{
      
}

void VentReceiver::OnPowerExit(TransmitterComponent* transmitter)
{
  actor_->SetElectric(false);
}

bool VentReceiver::IsWireless()
{ return false; }
