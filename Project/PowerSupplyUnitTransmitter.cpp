#include "PowerSupplyUnitTransmitter.h"

#include "ElectronicsPower.h"
#include "PowerSupplyUnitActor.h"

base_engine::Vector2 PowerSupplyUnitTransmitter::GetPosition() const {
  return electronics::psu::kPowerSupplyUnitTransmitterOffset;
}
bool PowerSupplyUnitTransmitter::CanSending() {
  return static_cast<bool>(actor_->ElectricPowerTrigger());
}

