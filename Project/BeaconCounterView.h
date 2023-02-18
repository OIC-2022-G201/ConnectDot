#pragma once
#include "Actor.h"
#include "CounterComponent.h"
class BeaconCounterView:public base_engine::Actor{
	
public:
	explicit  BeaconCounterView(base_engine::Game* game);
	~BeaconCounterView()override;
	void SetBeaconCount(int beacon_count);
private:
	base_engine::CounterComponent* counter_component_;
};
