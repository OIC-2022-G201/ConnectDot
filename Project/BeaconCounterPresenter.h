#pragma once
#include "BeaconCounterModel.h"
#include "BeaconCounterView.h"

class BeaconCounterPresenter{
	std::shared_ptr<BeaconCounterModel> beacon_counter_model_;
	BeaconCounterView* beacon_counter_view_ = nullptr;
public:
	void Bind() const{
		beacon_counter_model_->GetBeaconCount().Subscribe([this](int beacon_count) {
			beacon_counter_view_->SetBeaconCount(beacon_count);
		});
	}
	void SetBeaconCounterView(BeaconCounterView* beacon_counter_view){ beacon_counter_view_ = beacon_counter_view; }
	void SetBeaconCounterModel(std::shared_ptr<BeaconCounterModel> beacon_counter_model){ beacon_counter_model_ = beacon_counter_model; }
};
