#pragma once
#include "Actor.h"

class testActor : public base_engine::Actor {
public:
	explicit testActor(base_engine::Game* game);	//explicitは暗黙の型変換が起きなくなる
	~testActor() override;
	void Start() override;
	void Update() override;
};

