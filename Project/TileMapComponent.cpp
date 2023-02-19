#include "TileMapComponent.h"

#include <fstream>

#include "BinaryArchive.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "Frozen.h"
#include "FrozenMapData.h"
#include "IBaseEngineTexture.h"
#include "IMapDrawer.h"
#include "MiniMapDrawer.h"
#include "Rect.h"
#include "StageDrawer.h"
#include "StringFrozen.h"
#include "VectorFrozen.h"

namespace tile_map {

TileMapComponent::TileMapRenderComponent::TileMapRenderComponent(
    base_engine::Actor* owner, int draw_order, TileMapComponent* tile_map)
    : RenderComponent(owner, draw_order), tile_map_(tile_map) {
    
    drawers_.emplace_back(new StageDrawer());
    drawers_.emplace_back(new MiniMapDrawer());
}

void TileMapComponent::TileMapRenderComponent::Draw() {
    for (auto drawer : drawers_) {
        drawer->Draw(tile_map_);
    }
}

void TileMapComponent::Load() { Load(stage_name_); }

void TileMapComponent::Start() {}

void TileMapComponent::Update() {}

void TileMapComponent::SetStage(const std::string_view path) {
  stage_name_ = path;
}

void TileMapComponent::Load(std::string_view path) {
  {
    FrozenMapData map_data;

    std::ifstream os(path, std::ios::binary);
    {
      frozen::BinaryInputArchive archive(os);
      archive(map_data);
    }
    cell_width_ = map_data.map_max_x;
    cell_height_ = map_data.map_max_y;
    cell_size_ = map_data.chip_size;
    map_ = {static_cast<unsigned>(cell_width_),
            static_cast<unsigned>(cell_height_), map_data.tile_data};
    
    render_->Load(map_data);
  }
  tile_shape_.clear();
  {
    Mof::CReadTextFile reader("mapchip/StageSetTile.txt");
    
    for (int i = 0; i < 50; ++i) {
      Mof::Rectangle rect;
      reader.ReadU16();
      reader.ReadRectangle(rect);
      tile_shape_.emplace_back(std::make_shared<base_engine::Rect>(rect));
    }
  }
  int n = 0;
  for (int x = 0; x < map_.GetXCount(); ++x) {
    for (int y = 0; y < map_.GetYCount(); ++y) {
      if (map_.GetCell(x, y) == 0) continue;
      if (x == 0) continue;
      if (y == 0) continue;
      if (x == map_.GetXCount()) continue;
      if (y == map_.GetYCount()) continue;
      if ((map_.GetCell(x + 1, y) != 0) && (map_.GetCell(x - 1, y) != 0) &&
          (map_.GetCell(x, y + 1) != 0) && (map_.GetCell(x, y - 1) != 0))
        continue;
      n++;
      const auto cell = new base_engine::Actor(owner_->GetGame());
      cell->SetTag("Field");
      cell->SetPosition({static_cast<MofFloat>(x * 128), y * 128.0f});
      const auto collision = new base_engine::CollisionComponent(cell);
      collision->SetObjectFilter(kFieldObjectFilter);
      collision->SetTargetFilter(kFieldTargetFilter);
      collision->SetShape(tile_shape_[map_.GetCell(x, y)-1]);
    }
  }
}

void TileMapComponent::TileMapRenderComponent::Load(FrozenMapData map_data) {
    for (auto drawer : drawers_) {
        drawer->Load(map_data);
    }
}

void TileMapComponent::CreateBody() {
  new base_engine::Actor(owner_->GetGame());
}

TileMapComponent::TileMapComponent(base_engine::Actor* owner, int update_order)
    : Component(owner, update_order),
      render_(new TileMapRenderComponent(owner, 50, this)) {}

}  // namespace tile_map