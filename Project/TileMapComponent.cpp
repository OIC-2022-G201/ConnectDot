#include "TileMapComponent.h"

#include <fstream>

#include "BinaryArchive.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "Frozen.h"
#include "IBaseEngineTexture.h"
#include "Rect.h"
#include "StringFrozen.h"
#include "VectorFrozen.h"
namespace tile_map {
struct FrozenMapData {
  std::string back_ground_path{};
  std::string map_chip_path{};
  int chip_size = 0;
  int map_max_x{};
  int map_max_y{};
  std::vector<std::vector<char>> tile_data{};
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(back_ground_path, map_chip_path, chip_size, map_max_x, map_max_y,
            tile_data);
  }
};

TileMapComponent::TileMapRenderComponent::TileMapRenderComponent(
    base_engine::Actor* owner, int draw_order, TileMapComponent* tile_map)
    : RenderComponent(owner, draw_order), tile_map_(tile_map) {}

void TileMapComponent::TileMapRenderComponent::Draw() {
  Mof::CRectangle rect;
  for (int y = 0; y < tile_map_->map_.GetYCount(); ++y) {
    for (int x = 0; x < tile_map_->map_.GetXCount(); ++x) {
      const auto cell = tile_map_->map_.GetCell(x, y);
      if (cell == kEmptyCell) continue;
      if (cell > tile_map_->s_rectangles_.size()) continue;
      
      BASE_ENGINE(Render)->AddTexture(
          tile_map_->texture_, {x * 128.0f, y * 128.0f}, {1, 1}, 0,
          tile_map_->s_rectangles_[cell - 1], MOF_COLOR_WHITE,
          Mof::TextureAlignment::TEXALIGN_TOPLEFT);
      rect.Translation({128, 0});
    }
    rect.Translation({0, 128});
  }
}

void TileMapComponent::Start() { Load(stage_name_); }

void TileMapComponent::Update() {}

void TileMapComponent::SetStage(const std::string_view path)
{
	stage_name_ = path;
}

void TileMapComponent::Load(std::string_view path)
{
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
    {
      texture_ = BASE_ENGINE(Texture)->Get(map_data.map_chip_path);
      const auto tx = texture_->GetWidth() / cell_width_;
      const auto ty = texture_->GetHeight() / cell_height_;
      for (int y = 0; y < ty; ++y) {
        for (int x = 0; x < tx; ++x) {
          s_rectangles_.emplace_back(x * cell_size_, y * cell_size_,
                                     (x + 1) * cell_size_,
                                     (y + 1) * cell_size_);
        }
      }
    }
  }

    
  tile_shape_.emplace_back(new base_engine::Rect(0, 0, 128, 128));

  for (int x = 0; x < map_.GetXCount(); ++x) {
    for (int y = 0; y < map_.GetYCount(); ++y) {
      if (map_.GetCell(x, y) == 0) continue;
      const auto cell = new base_engine::Actor(owner_->GetGame());
      cell->SetTag("Field");
      cell->SetPosition({static_cast<MofFloat>(x * 128), y * 128.0f});
      const auto collision = new base_engine::CollisionComponent(cell);
      collision->SetObjectFilter(kFieldObjectFilter);
      collision->SetTargetFilter(kFieldTargetFilter);
      collision->SetShape(tile_shape_[0]);
    }
  }
}

void TileMapComponent::CreateBody() {
  new base_engine::Actor(owner_->GetGame());
}

TileMapComponent::TileMapComponent(base_engine::Actor* owner, int update_order)
    : Component(owner, update_order),
      render_(new TileMapRenderComponent(owner, 50, this)) {}

}  // namespace tile_map