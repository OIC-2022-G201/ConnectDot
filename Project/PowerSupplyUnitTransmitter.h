// @file PowerSupplyUnitTransmitter.h
// @brief 
// @author ICE
// @date 2022/09/22
// 
// @details

#pragma once
#include "ISendablePower.h"

class PowerSupplyUnitTransmitter : public ISendablePower {
public:
    explicit PowerSupplyUnitTransmitter(class PowerSupplyUnitActor* actor)
        : actor_(actor)
    {
    }

    const ISendablePower* GetPrevious() override { return previous_; }
  void SetPrevious(ISendablePower* previous) override { previous_ = previous; }

  bool CanSending() override;
  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

  int Sequential() override;

 private:
  base_engine::Vector2 position_;
  ISendablePower* previous_ = nullptr;
  class PowerSupplyUnitActor* actor_ = nullptr;
};
