// @file BeaconReceiver.h
// @brief
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once

#include "AudioStreamComponent.h"
#include "IReceivablePower.h"
#include "OneTimeEffectActor.h"

class BeaconReceiver final : public IReceivablePower {
 public:
  explicit BeaconReceiver(class BeaconActor* actor,
                          base_engine::Vector2 position);
  int Sequential() override;
  bool PowerJoinCondition() override;
  void OnPowerEnter(class TransmitterComponent* transmitter) override;
  void OnPowerChanged(TransmitterComponent* transmitter) override;
  void OnPowerExit(TransmitterComponent* transmitter) override;
  bool IsWireless() override { return true; }
  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

 private:
  base_engine::Vector2 position_;
  std::weak_ptr<base_engine::AudioStreamComponent> connect_se_{};
  class BeaconActor* actor_;
  OneTimeEffectActor* effect_actor_;
};
