// @VentReceiver.h
// @brief
// @author ICE
// @date 2022/11/29
//
// @details

#pragma once
#include "IReceivablePower.h"

class VentReceiver final : public IReceivablePower {
 public:
  explicit VentReceiver(class VentComponent* actor);

  int Sequential() override;

  bool PowerJoinCondition() override;

  void OnPowerEnter(TransmitterComponent* transmitter) override;

  void OnPowerChanged(TransmitterComponent* transmitter) override;

  void OnPowerExit(TransmitterComponent* transmitter) override;

  bool IsWireless() override;

  [[nodiscard]] base_engine::Vector2 GetPosition() const override { return {}; }

 private:
  class VentComponent* vent_ = nullptr;
};
