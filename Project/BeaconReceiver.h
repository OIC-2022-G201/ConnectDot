// @file BeaconReceiver.h
// @brief 
// @author ICE
// @date 2022/08/08
// 
// @details

#pragma once
#include "IReceivablePower.h"
#include "BeaconTransmitter.h"


class BeaconReceiver : public IReceivablePower {
public:
    bool PowerJoinCondition() override
    { 
        return true;
    }
    void OnPowerEnter() override
    {
        transmitter_->SetCanSending(true);
    }
    void OnPowerChanged() override
    {
        int n = 3;
    }
    void OnPowerExit() override
    {
        transmitter_->SetCanSending(false);
    }
    BeaconReceiver(BeaconTransmitter* transmitter):transmitter_(transmitter){}
private:
    BeaconTransmitter* transmitter_;
};
