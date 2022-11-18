#pragma once
#include "DoorActor.h"
#include "IReceivablePower.h"
#include "SpriteComponent.h"
#include "TransmitterComponent.h"
#undef max
class DoorReceiver : public IReceivablePower
{
public:
	int Sequential() override { return std::numeric_limits<int>::max(); }
	bool PowerJoinCondition() override { return true; }
	void OnPowerEnter(TransmitterComponent* transmitter)override{
		
	}
	void OnPowerChanged(TransmitterComponent* transmitter)override{}
	void OnPowerExit(TransmitterComponent* transmitter)override{
		
	}
private:

};
