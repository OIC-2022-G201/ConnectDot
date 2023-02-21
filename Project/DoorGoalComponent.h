#pragma once
#include "Component.h"

class DoorGoalComponent final : public base_engine::Component {
public:
	explicit DoorGoalComponent(base_engine::Actor* owner, int update_order)
		: Component(owner, update_order) {
	}

	void Start() override;
	void Update() override;
};
