#include "BeaconReceiver.h"
#include "BeaconActor.h"
#include "TransmitterComponent.h"


bool BeaconReceiver::PowerJoinCondition()
{
    return true;
}

void BeaconReceiver::OnPowerEnter()
{
    transmitter_->SetCanSending(true);
}

void BeaconReceiver::OnPowerChanged()
{
    int n = 3;
}

void BeaconReceiver::OnPowerExit()
{
    transmitter_->SetCanSending(false);
}

BeaconReceiver::BeaconReceiver(TransmitterComponent* transmitter) :transmitter_(transmitter) {}
