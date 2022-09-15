#include "BeaconTransmitter.h"

#include "BeaconActor.h"

BeaconTransmitter::BeaconTransmitter(BeaconActor* actor) : actor_(actor)
{
  actor_->RegistryPart(this);
}


void BeaconTransmitter::Sending(ReceiverComponent*) {
        
}
