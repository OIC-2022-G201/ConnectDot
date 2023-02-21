#pragma once
#include "Actor.h"

class DoorGoalActor final : public base_engine::Actor {
public:
	explicit DoorGoalActor(base_engine::Game* game)
		: Actor(game) {
	}

	void Start() override;
	void Input() override;
	void Update() override;
};