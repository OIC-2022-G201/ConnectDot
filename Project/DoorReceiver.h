// @DoorReceiver.h
// @brief
// @author ICE
// @date 2022/12/02
//
// @details

#pragma once
#include "Actor.h"
#include "IReceivablePower.h"

class DoorReceiver final : public IReceivablePower {
 public:
  explicit DoorReceiver(class DoorComponent* door, base_engine::Actor* actor);

  int Sequential() override { return 1000; }
  bool PowerJoinCondition() override { return true; }
  void OnPowerEnter(TransmitterComponent* transmitter) override;
  void OnPowerChanged(TransmitterComponent* transmitter) override;
  void OnPowerExit(TransmitterComponent* transmitter) override;
  bool IsWireless() override { return false; }
  [[nodiscard]] base_engine::Vector2 GetPosition() const override { return {}; }

 private:
  class DoorComponent* door_ = nullptr;
  base_engine::Actor* owner_ = nullptr;

};
