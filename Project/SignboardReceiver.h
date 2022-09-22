// @file SignboardReceiver.h
// @brief 
// @author ICE
// @date 2022/09/22
// 
// @details

#pragma once
#include "IReceivablePower.h"

class SignboardReceiver : public IReceivablePower {
public:
    SignboardReceiver() = default;
    int Sequential() override { return 10; }
 bool PowerJoinCondition() override { return true; }
    void OnPowerEnter(TransmitterComponent* transmitter) override
    {
        int n = 0;
    }
    void OnPowerChanged(TransmitterComponent* transmitter) override{}
    void OnPowerExit(TransmitterComponent* transmitter) override{}
    bool IsWireless() override { return true; }

  [[nodiscard]] base_engine::Vector2 GetPosition() const override
  {
      return {64, 64};
  }
};
