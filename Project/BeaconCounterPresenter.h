#pragma once
#include "BeaconCounterModel.h"
#include "BeaconCounterView.h"
#include "BeaconPowerUpCounterView.h"

class BeaconCounterPresenter{
	std::shared_ptr<BeaconCounterModel> beacon_counter_model_;
	BeaconCounterView* beacon_counter_view_ = nullptr;
	BeaconPowerUpCounterView* beacon_beacon_power_up_counter_view_ = nullptr;
public:
	void Bind() const{
		beacon_counter_view_->SetBeaconCount(static_cast<int>(beacon_counter_model_->GetBeaconCount()));
		beacon_counter_model_->GetBeaconCount().Subscribe([this](int beacon_count) {
			beacon_counter_view_->SetBeaconCount(beacon_count);
		});
		beacon_beacon_power_up_counter_view_->SetBeaconPowerUpCount(static_cast<int>(beacon_counter_model_->GetBeaconPowerUpCount()));
		beacon_counter_model_->GetBeaconPowerUpCount().Subscribe([this](int beacon_power_up_count) {
			beacon_beacon_power_up_counter_view_->SetBeaconPowerUpCount(beacon_power_up_count);
		});
	}
	void SetBeaconCounterView(BeaconCounterView* beacon_counter_view){ beacon_counter_view_ = beacon_counter_view; }
	void SetBeaconPowerUpCounterView(BeaconPowerUpCounterView* beacon_beacon_power_up_counter_view){ beacon_beacon_power_up_counter_view_ = beacon_beacon_power_up_counter_view; }
	void SetBeaconCounterModel(const std::shared_ptr<BeaconCounterModel>& beacon_counter_model){ beacon_counter_model_ = beacon_counter_model; }
	[[nodiscard]] std::shared_ptr<BeaconCounterModel> GetBeaconCounterModel() const {return beacon_counter_model_;}
};
