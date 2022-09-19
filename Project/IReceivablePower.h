#pragma once
#include "Vector.h"

class IReceivablePower {
 public:
  virtual ~IReceivablePower() = default;
  virtual int Sequential() = 0;
  bool virtual PowerJoinCondition() = 0;
  void virtual OnPowerEnter(class TransmitterComponent* transmitter) = 0;
  void virtual OnPowerChanged(TransmitterComponent* transmitter) = 0;
  void virtual OnPowerExit(TransmitterComponent* transmitter) = 0;

  [[nodiscard]] virtual base_engine::Vector2 GetPosition() const = 0;
};
