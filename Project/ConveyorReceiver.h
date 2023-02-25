// @ConveyorReceiver.h
// @brief
// @author ICE
// @date 2023/02/24
// 
// @details

#pragma once
#include "TransmitterComponent.h"

class ConveyorReceiver final : public IReceivablePower {
 public:
	ConveyorReceiver(class ConveyorComponent* component, base_engine::Actor* owner)
		: component_(component),
		  owner_(owner)
	{
	}

	int Sequential() override;
  bool PowerJoinCondition() override;
  void OnPowerEnter(TransmitterComponent* transmitter) override;
  void OnPowerChanged(TransmitterComponent* transmitter) override;
  void OnPowerExit(TransmitterComponent* transmitter) override;
  bool IsWireless() override;
  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

 private:
  class ConveyorComponent* component_ = nullptr;
  base_engine::Actor* owner_ = nullptr;
};
