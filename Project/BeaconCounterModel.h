#pragma once
#include <cstdint>
#include "ReactiveProperty.h"

class BeaconCounterModel{
	observable::ReactiveProperty<int> beacon_count_ = 99;
public:
	[[nodiscard]] auto&& GetBeaconCount() {
		return beacon_count_.ToReadOnly();
	}
	void SetBeaconLimit(int beacon_limit) { beacon_count_ = beacon_limit; }
	void IncrementBeaconCount() {beacon_count_ = static_cast<int>(beacon_count_) + 1;}
	void DecrementBeaconCount() {beacon_count_ = static_cast<int>(beacon_count_) - 1;}
};