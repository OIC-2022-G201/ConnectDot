#include "BeaconPowerUpCounterView.h"

BeaconPowerUpCounterView::BeaconPowerUpCounterView(base_engine::Game* game):Actor(game) {
	counter_component_ = new base_engine::CounterComponent(this, "BeaconQuantity_Number");
	SetPosition({ 1066,94 });
	SetEnable(true);
	counter_component_->SetEnable(true);
	counter_component_->SetSpace(5);
}

BeaconPowerUpCounterView::~BeaconPowerUpCounterView() {
}

void BeaconPowerUpCounterView::SetBeaconPowerUpCount(const int beacon_power_up_count) const{
	if (beacon_power_up_count < 0)return;
	counter_component_->SetNumber(beacon_power_up_count);
}