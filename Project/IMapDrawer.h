#pragma once
#include "FrozenMapData.h"
#include "TileMapComponent.h"

namespace tile_map{
class IMapDrawer {

public:
	virtual void Load(tile_map::FrozenMapData map_data) {}
	virtual void Draw(tile_map::TileMapComponent* tile_map) {}
};
}