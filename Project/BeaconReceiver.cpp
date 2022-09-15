#include "BeaconReceiver.h"

#include "BeaconActor.h"

BeaconReceiver::BeaconReceiver(BeaconActor* actor): actor_(actor)
{
  actor_->RegistryPart(this);
}

