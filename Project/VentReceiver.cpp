#include "VentReceiver.h"

#include "VentComponent.h"

VentReceiver::VentReceiver(VentComponent* actor) : vent_(actor) {}

int VentReceiver::Sequential()
{ return 100; }

bool VentReceiver::PowerJoinCondition()
{ return true; }

void VentReceiver::OnPowerEnter(TransmitterComponent* transmitter)
{
  vent_->SetElectric(true);
}

void VentReceiver::OnPowerChanged(TransmitterComponent* transmitter)
{
      
}

void VentReceiver::OnPowerExit(TransmitterComponent* transmitter)
{
  vent_->SetElectric(false);
}

bool VentReceiver::IsWireless()
{ return false; }
