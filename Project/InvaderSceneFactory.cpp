#include "InvaderSceneFactory.h"

#include "ImageComponent.h"

#include "InputManager.h"

using namespace base_engine;
void InvaderSceneFactory::Factory()
{
	new InputManager(new InputActor(game_));
}
