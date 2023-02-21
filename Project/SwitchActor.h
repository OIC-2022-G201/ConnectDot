#pragma once
#include "Actor.h"

class SwitchActor final : public base_engine::Actor {
public:
	explicit SwitchActor(base_engine::Game* game)
		: Actor(game) {
	}

	void Start() override;
	void Input() override;
	void Update() override;
};
