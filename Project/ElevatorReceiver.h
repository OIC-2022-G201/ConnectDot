// @ElevatorReceiver.h
// @brief
// @author ICE
// @date 2022/12/28
// 
// @details

#pragma once
#include "Actor.h"
#include "IReceivablePower.h"

class ElevatorReceiver final : public IReceivablePower {
public:
	ElevatorReceiver(class ElevatorComponent* elevator, base_engine::Actor* owner);

	int Sequential() override;
	bool PowerJoinCondition() override;
	void OnPowerEnter(TransmitterComponent* transmitter) override;
	void OnPowerChanged(TransmitterComponent* transmitter) override;
	void OnPowerExit(TransmitterComponent* transmitter) override;
	bool IsWireless() override;
	[[nodiscard]] base_engine::Vector2 GetPosition() const override;

private:
  class ElevatorComponent* elevator_ = nullptr;
  base_engine::Actor* owner_ = nullptr;
};