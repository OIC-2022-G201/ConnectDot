// @file LeverStubReceiver.h
// @brief 
// @author ICE
// @date 2022/11/21
// 
// @details

#pragma once
#include "IReceivablePower.h"
#include "ISendablePower.h"

class LeverStubReceiver : public IReceivablePower 
  {
public:
  LeverStubReceiver(class LeverStubActor* actor);

  int Sequential() override;

  bool PowerJoinCondition() override;

  void OnPowerEnter(TransmitterComponent* transmitter) override;

  void OnPowerChanged(TransmitterComponent* transmitter) override;

  void OnPowerExit(TransmitterComponent* transmitter) override;

  bool IsWireless() override;

  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

private:
  class LeverStubActor* actor_ = nullptr;
};

class LeverStubTransmitter : public ISendablePower {
 public:
  explicit LeverStubTransmitter(class LeverStubActor* actor);

  const ISendablePower* GetPrevious() override;
  void SetPrevious(ISendablePower* previous) override;

  bool CanSending() override;

  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

  int Sequential() override;

private:
  base_engine::Vector2 position_;
  ISendablePower* previous_ = nullptr;
  class LeverStubActor* actor_ = nullptr;
};
