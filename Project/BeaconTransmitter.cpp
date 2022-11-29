#include "BeaconTransmitter.h"

#include "BeaconActor.h"

BeaconTransmitter::BeaconTransmitter(BeaconActor* actor,
                                     base_engine::Vector2 position)
    : position_(position), actor_(actor) {
  actor_->RegistryPart(this);
}


bool BeaconTransmitter::CanSending() {
  return static_cast<bool>(actor_->ElectricPowerTrigger());
}

base_engine::Vector2 BeaconTransmitter::GetPosition() const
{
    return position_;
}

