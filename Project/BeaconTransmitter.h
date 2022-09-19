// @file BeaconTransmitter.h
// @brief ビーコン送電機
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once
#include "ISendablePower.h"
#undef max

class BeaconTransmitter : public ISendablePower {
 public:
  explicit BeaconTransmitter(class BeaconActor* actor,
                             base_engine::Vector2 position);


  const ISendablePower* GetPrevious() override { return previous_; }
  void SetPrevious(ISendablePower* previous) override { previous_ = previous; }

  bool CanSending() override;
  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

  int Sequential() override;
private:
  base_engine::Vector2 position_;
  ISendablePower* previous_ = nullptr;
  
  BeaconActor* actor_ = nullptr;
};
