#pragma once

#include "Actor.h"
#include "IBaseEngineTexture.h"
#include "imageComponent.h"
#include "SpriteComponent.h"

class DoorActor final : public  base_engine::Actor
{
public:
	explicit DoorActor(base_engine::Game* game);

	~DoorActor() override = default;

	void Start() override;

	void Update() override;
private:
	base_engine::SpriteComponent* door_ = nullptr;
	base_engine::SpriteComponent* open_door_ = nullptr;
};

