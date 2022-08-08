#include "BeaconTransmitter.h"

BeaconTransmitter::BeaconTransmitter(const int level): level_(level)
{}

std::vector<IReceivablePower*> BeaconTransmitter::GetTarget()
{
    return {};
}

void BeaconTransmitter::Sending()
{
        
}
