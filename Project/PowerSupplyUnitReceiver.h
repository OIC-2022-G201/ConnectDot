// @file PowerSupplyUnitReceiver.h
// @brief
// @author ICE
// @date 2022/09/22
//
// @details

#pragma once
#include "Actor.h"
#include "IReceivablePower.h"
#include "OneTimeEffectActor.h"

class PowerSupplyUnitReceiver : public IReceivablePower {
 public:
  PowerSupplyUnitReceiver(class PowerSupplyUnitActor* actor,
                          base_engine::Actor* target,
                          class TransmitterComponent* sender);

  int Sequential() override;
  bool PowerJoinCondition() override;
  void OnPowerEnter(TransmitterComponent* transmitter) override;
  void OnPowerChanged(TransmitterComponent* transmitter) override;
  void OnPowerExit(TransmitterComponent* transmitter) override;
  bool IsWireless() override;
  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

 private:
  class PowerSupplyUnitActor* actor_ = nullptr;
  std::vector<base_engine::Actor*> targets_;
  std::vector<std::weak_ptr<class ReceiverComponent>> receivers_;
  class TransmitterComponent* sender_ = nullptr;
  OneTimeEffectActor* effect_actor_ = nullptr;

  int sequential_;
};
