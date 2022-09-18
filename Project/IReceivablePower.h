#pragma once

class IReceivablePower {
 public:
  virtual ~IReceivablePower() = default;
  virtual int Sequential() = 0;
  bool virtual PowerJoinCondition() = 0;
  void virtual OnPowerEnter(class TransmitterComponent* transmitter) = 0;
  void virtual OnPowerChanged(TransmitterComponent* transmitter) = 0;
  void virtual OnPowerExit(TransmitterComponent* transmitter) = 0;
};