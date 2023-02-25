#include "SwitchTransmitter.h"

#include "SwitchActor.h"
bool SwitchTransmitter::CanSending() { return actor_->OnPush(); }
