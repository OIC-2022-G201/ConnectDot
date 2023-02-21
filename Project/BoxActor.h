#pragma once
#include "Actor.h"

class BoxActor final : public base_engine::Actor
{
public:
	explicit BoxActor(base_engine::Game* game)
		: Actor(game) {
	}
	void Start() override;
	void Input() override;
	void Update() override;
};