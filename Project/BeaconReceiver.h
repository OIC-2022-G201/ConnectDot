// @file BeaconReceiver.h
// @brief
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once

#include "IReceivablePower.h"

class BeaconReceiver final : public IReceivablePower {
  class BeaconActor* actor_;

 public:
  explicit BeaconReceiver(class BeaconActor* actor);

  bool PowerJoinCondition() override;
  void OnPowerEnter() override;
  void OnPowerChanged() override;
  void OnPowerExit() override;
};
