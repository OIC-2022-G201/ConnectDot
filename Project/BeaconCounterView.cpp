#include "BeaconCounterView.h"

BeaconCounterView::BeaconCounterView(base_engine::Game* game) : Actor(game) {
	counter_component_ = new base_engine::CounterComponent(this,"BeaconQuantity_Number");
	SetPosition({930, 94});
	SetEnable(true);
	counter_component_->SetEnable(true);
	counter_component_->SetSpace(5);
}

BeaconCounterView::~BeaconCounterView() {
}

void BeaconCounterView::SetBeaconCount(const int beacon_count) const {
	if (beacon_count < 0)return;
	counter_component_->SetNumber(beacon_count);
}