// @file BeaconReceiver.h
// @brief
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once

#include "IReceivablePower.h"
#include "SpriteComponent.h"
class BeaconReceiver final : public IReceivablePower {

 public:
  explicit BeaconReceiver(class BeaconActor* actor);
  int Sequential() override;
  bool PowerJoinCondition() override;
  void OnPowerEnter(class TransmitterComponent* transmitter) override;
  void OnPowerChanged(TransmitterComponent* transmitter) override;
  void OnPowerExit(TransmitterComponent* transmitter) override;
private:
  class BeaconActor* actor_;
  class ElectricEffect* effect_;
};
