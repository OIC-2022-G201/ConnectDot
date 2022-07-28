#pragma once
#include "Component.h"
#include "IReceivablePower.h"
#include "ISendablePower.h"

class Beacon : public base_engine::Component,public IReceivablePower,public ISendablePower
{
public:
    bool PowerJoinCondition() override
    {
        return true;
    }
    void OnPowerEnter() override
    {
        
    }
    void OnPowerChanged() override
    {
        
    }
    void OnPowerExit() override
    {
        
    }
private:
    std::vector<IReceivablePower*> GetTarget() override
    {
        
    }
    void Sending() override
    {
        
    }
};
