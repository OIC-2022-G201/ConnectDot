#pragma once
#include "IMapDrawer.h"

class StageDrawer:public tile_map::IMapDrawer
{

public:
	void Load(tile_map::FrozenMapData map_data) override;
	void Draw(tile_map::TileMapComponent* tile_map) override;

private:
	Mof::LPTexture texture_ = nullptr;
	std::vector<Mof::Rectangle> s_rectangles_{};
};