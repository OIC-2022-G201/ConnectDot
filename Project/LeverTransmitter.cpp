#include "LeverTransmitter.h"
#include "LeverActor.h"
#include "ElectronicsPower.h"

base_engine::Vector2 LeverTransmitter::GetPosition()const {
	return electronics::lev::kLeverTransmitterOffset;
}
bool LeverTransmitter::CanSending() {
	return false;
}
int LeverTransmitter::Sequential() { return actor_->Sequential(); }


