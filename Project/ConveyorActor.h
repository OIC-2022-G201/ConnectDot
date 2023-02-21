#pragma once
#include "Actor.h"

class ConveyorActor final : public base_engine::Actor {
public:
	explicit ConveyorActor(base_engine::Game* game)
		: Actor(game) {
	}

	void Start() override;
	void Input() override;
	void Update() override;
};