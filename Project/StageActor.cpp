#include "StageActor.h"

#include "ObjectTileMapComponent.h"
#include "TileMapComponent.h"

StageActor::StageActor(base_engine::Game* game): Actor(game)
{
}

void StageActor::Start()
{
    SetName("Stage");
    new tile_map::TileMapComponent(this, 100);
    new tile_map::ObjectTileMapComponent(this);
}

void StageActor::Update()
{}
