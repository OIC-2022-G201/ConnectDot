#pragma once
#include "IMapDrawer.h"

class MiniMapDrawer:public tile_map::IMapDrawer
{

public:
	void Load(tile_map::FrozenMapData map_data) override;
	void Draw(tile_map::TileMapComponent* tile_map) override;
private:
	Mof::LPTexture texture_ = nullptr;
	std::vector<Mof::Rectangle> s_rectangles_{};

	const float scale_ = 0.1f;

	bool IsDrawCell(tile_map::Layer::CellType type);
	void DrawMap();
	void DrawGimmick();
};