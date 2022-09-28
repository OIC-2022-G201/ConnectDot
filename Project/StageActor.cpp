#include "StageActor.h"
#include "TileMapComponent.h"

StageActor::StageActor(base_engine::Game* game): Actor(game)
{
}

void StageActor::Start()
{
    SetName("Stage");
    new tile_map::TileMapComponent(this, 100);
}

void StageActor::Update()
{}
