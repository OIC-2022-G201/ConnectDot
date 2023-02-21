#pragma once
#include "Actor.h"
#include "IReceivablePower.h"

class DoorGoalReceiver : public IReceivablePower {
public:
	DoorGoalReceiver(class DoorGoalActor* actor, base_engine::Actor* owner);
	int Sequential() override;
	bool PowerJoinCondition() override;
	void OnPowerEnter(TransmitterComponent* transmitter) override;
	void OnPowerChanged(TransmitterComponent* transmitter) override;
	void OnPowerExit(TransmitterComponent* transmitter) override;
	bool IsWireless() override { return false; }
	[[nodiscard]] base_engine::Vector2 GetPosition() const override;
private:
	class DoorGoalActor* actor_ = nullptr;
	base_engine::Actor* owner_ = nullptr;
};