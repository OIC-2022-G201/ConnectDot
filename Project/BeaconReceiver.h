// @file BeaconReceiver.h
// @brief 
// @author ICE
// @date 2022/08/08
// 
// @details

#pragma once
#include "IReceivablePower.h"

class BeaconReceiver : public IReceivablePower {
public:
    bool PowerJoinCondition() override;
    void OnPowerEnter() override;
    void OnPowerChanged() override;
    void OnPowerExit() override;
    BeaconReceiver(class TransmitterComponent* transmitter);

   private:
    TransmitterComponent* transmitter_;
};
