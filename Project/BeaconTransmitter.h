// @file BeaconTransmitter.h
// @brief 
// @author ICE
// @date 2022/08/08
// 
// @details

#pragma once
#include "ISendablePower.h"

class BeaconTransmitter :public ISendablePower {
  float r_;
    public:
  BeaconTransmitter(float r)
  { r_ = r;
  }
    std::vector<IReceivablePower*> GetTarget() override
    {
        return {};
    }

    void Sending() override
    {
        
    }
    
};
