#pragma once

class IReceivablePower {
 public:
  virtual ~IReceivablePower() = default;
  bool virtual PowerJoinCondition() = 0;
  void virtual OnPowerEnter() = 0;
  void virtual OnPowerChanged() = 0;
  void virtual OnPowerExit() = 0;
};