// @file BeaconReceiver.h
// @brief 
// @author ICE
// @date 2022/08/08
// 
// @details

#pragma once
#include <functional>
#include <vector>

#include "IReceivablePower.h"

class BeaconReceiver : public IReceivablePower {
  class BeaconActor* actor_;
  bool is_energy_;

 public:
  explicit BeaconReceiver(class BeaconActor* actor);

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
private:
    using Action = std::function<void()>;
    std::vector<Action> on_power_enter_events_;
public:
    void SetOnPowerEnterEvent(const Action& action) {
      on_power_enter_events_.emplace_back(action);
    }
};
