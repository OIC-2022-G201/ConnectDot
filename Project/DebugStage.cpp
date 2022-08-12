#include "DebugStage.h"

#include "TileMapComponent.h"

DebugStage::DebugStage(base_engine::Game* game): Actor(game)
{
}

void DebugStage::Start() {
  SetName("Stage");
  new tile_map::TileMapComponent(this, 100);
}

void DebugStage::Update()
{}
