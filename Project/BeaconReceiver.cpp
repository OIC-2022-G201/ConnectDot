#include "BeaconReceiver.h"

#include "BeaconActor.h"

BeaconReceiver::BeaconReceiver(BeaconActor* actor): actor_(actor)
{
  actor_->RegistryPart(this);
}

bool BeaconReceiver::PowerJoinCondition()
{ return true; }

void BeaconReceiver::OnPowerChanged()
{  }

void BeaconReceiver::OnPowerExit()
{
    actor_->SetElectricPower(false);
}

void BeaconReceiver::OnPowerEnter()
{
    actor_->SetElectricPower(true);
}

