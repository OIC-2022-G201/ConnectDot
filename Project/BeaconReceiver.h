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
    bool PowerJoinCondition() override
    { return true;
    }
    void OnPowerEnter() override
    {
        int n = 3;
    }
    void OnPowerChanged() override
    {
        int n = 3;
    }
    void OnPowerExit() override
    {
        int n = 3;
    }
};
