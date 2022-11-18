#include "LeverComponent.h"
#include "TransmitterComponent.h"
void LeverComponent::Action()
{
	transmitter_->AddTarget(target_);
  
}
