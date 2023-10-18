#include "BeaconCounterView.h"
#include "ResourceContainer.h"
using RC = ResourceContainer;
BeaconCounterView::BeaconCounterView(base_engine::Game* game) : Actor(game) {
	counter_component_ = new base_engine::CounterComponent(this,"BeaconQuantity_Number");
	SetPosition({900, 94});
	SetEnable(true);
	counter_component_->SetEnable(true);
	counter_component_->SetSpace(5);

	{
		auto actor = new Actor(game);
		auto sprite = new base_engine::ImageComponent(actor, 1000);
		actor->SetPosition({ 776 ,0 });
		sprite->SetImage(*RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("BeaconQuantity"));
	}
}

BeaconCounterView::~BeaconCounterView() {
}

void BeaconCounterView::SetBeaconCount(const int beacon_count) const {
	if (beacon_count < 0)return;
	counter_component_->SetNumber(beacon_count);
}
