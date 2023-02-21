#pragma once
#include "Actor.h"
#include "IReceivablePower.h"

class StartPointGimmickReceiver : public IReceivablePower {
public:
	StartPointGimmickReceiver(class StartPointGimmickActor* actor, base_engine::Actor* owner);
	int Sequential() override { return 1000; }
	bool PowerJoinCondition() override { return true; }
	void OnPowerEnter(TransmitterComponent* transmitter) override;
	void OnPowerChanged(TransmitterComponent* transmitter) override;
	void OnPowerExit(TransmitterComponent* transmitter) override;
	bool IsWireless() override { return false; }
	[[nodiscard]] base_engine::Vector2 GetPosition() const override { return {}; }
private:
	class StartPointGimmickActor* actor_ = nullptr;
	base_engine::Actor* owner_ = nullptr;
};
