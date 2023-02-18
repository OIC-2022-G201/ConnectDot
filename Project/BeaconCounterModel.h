#pragma once
#include <cstdint>
#include "ReactiveProperty.h"

class BeaconCounterModel{
	observable::ReactiveProperty<int> beacon_count_ = 20;
	observable::ReactiveProperty<int> beacon_power_up_count_ = 3;
public:
	[[nodiscard]] auto&& GetBeaconCount() {
		return beacon_count_.ToReadOnly();
	}
	void SetBeaconLimit(int beacon_limit) { beacon_count_ = beacon_limit; }
	void IncrementBeaconCount() {beacon_count_ = static_cast<int>(beacon_count_) + 1;}
	void DecrementBeaconCount() {beacon_count_ = static_cast<int>(beacon_count_) - 1;}

	[[nodiscard]] auto&& GetBeaconPowerUpCount() {
		return  beacon_power_up_count_.ToReadOnly();
	}
	void SetBeaconPowerUpLimit(int beacon_power_up_limit) {
		beacon_power_up_count_ = beacon_power_up_limit;
	}
	void DecrementBeaconPowerUpCount() {
		beacon_power_up_count_ = static_cast<int>(beacon_power_up_count_) - 1;
	}
};