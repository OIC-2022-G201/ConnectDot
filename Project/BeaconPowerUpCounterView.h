#pragma once
#include "Actor.h"
#include "CounterComponent.h"

class BeaconPowerUpCounterView:public base_engine::Actor
{
public:
	explicit  BeaconPowerUpCounterView(base_engine::Game* game);
	~BeaconPowerUpCounterView()override;
	void SetBeaconPowerUpCount(int beacon_count)const;
private:
	base_engine::CounterComponent* counter_component_;
};