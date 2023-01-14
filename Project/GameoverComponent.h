#pragma once
#include "Component.h"
#include "ImageComponent.h"

class GameoverComponent:base_engine::Component
{
	base_engine::ImageComponent* logo_;
	float slide_;

public:
	GameoverComponent(base_engine::Actor* owner) :Component(owner) {}
	void Start() override;
	void Update() override;
};

