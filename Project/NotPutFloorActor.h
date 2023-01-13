#pragma once

#include "Actor.h"
#include "LoadObjectParameter.h"

class NotPutFloorActor final:public base_engine::Actor
{
public:
	NotPutFloorActor(base_engine::Game* game) :Actor(game) {};
	void Create(const LoadObject& object);
};