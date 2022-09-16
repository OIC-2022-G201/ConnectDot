#include "BeaconTransmitter.h"

#include "BeaconActor.h"

BeaconTransmitter::BeaconTransmitter(BeaconActor* actor) : actor_(actor)
{
  actor_->RegistryPart(this);
}


bool BeaconTransmitter::CanSending() {
  return static_cast<bool>(actor_->ElectricPowerTrigger());
}
