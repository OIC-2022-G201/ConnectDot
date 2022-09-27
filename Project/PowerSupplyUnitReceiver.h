// @file PowerSupplyUnitReceiver.h
// @brief
// @author ICE
// @date 2022/09/22
//
// @details

#pragma once
#include "Actor.h"
#include "IReceivablePower.h"

class PowerSupplyUnitReceiver : public IReceivablePower {
 public:
  PowerSupplyUnitReceiver(class PowerSupplyUnitActor* actor,
                          base_engine::Actor* target,
                          class TransmitterComponent* sender)
      : actor_(actor), target_(target), sender_(sender) {}

  int Sequential() override;
  bool PowerJoinCondition() override;
  void OnPowerEnter(TransmitterComponent* transmitter) override;
  void OnPowerChanged(TransmitterComponent* transmitter) override;
  void OnPowerExit(TransmitterComponent* transmitter) override;
  bool IsWireless() override;
  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

 private:
  class PowerSupplyUnitActor* actor_ = nullptr;
  base_engine::Actor* target_ = nullptr;
  std::weak_ptr<class ReceiverComponent> receiver_;
  class TransmitterComponent* sender_ = nullptr;
};
