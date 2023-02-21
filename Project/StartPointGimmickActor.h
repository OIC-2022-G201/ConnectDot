#pragma once
#include "Actor.h"

class StartPointGimmickActor final : public base_engine::Actor {
public:
	explicit StartPointGimmickActor(base_engine::Game* game)
		: Actor(game) {
	}

	void Start() override;
	void Input() override;
	void Update() override;
};