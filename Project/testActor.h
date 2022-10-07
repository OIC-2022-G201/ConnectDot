#pragma once
#include "Actor.h"

class testActor : public base_engine::Actor {
public:
	explicit testActor(base_engine::Game* game);	//explicit‚ÍˆÃ–Ù‚ÌŒ^•ÏŠ·‚ª‹N‚«‚È‚­‚È‚é
	~testActor() override;
	void Start() override;
	void Update() override;
};

