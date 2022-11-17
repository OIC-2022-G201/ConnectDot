#include "TileMapComponent.h"

#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "Rect.h"

void tile_map::TileMapComponent::Start() { Load(); }

void tile_map::TileMapComponent::Update() {}

void tile_map::TileMapComponent::Load() {

    map_.Load("out.bin");
  tile_shape_.emplace_back(new base_engine::Rect(0, 0, 128, 128));

  for (int x = 0; x < map_.GetXCount(); ++x) {
    for (int y = 0; y < map_.GetYCount(); ++y) {
      if (map_.GetCell(x,y)==0)continue;
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

void tile_map::TileMapComponent::Load(std::string_view path)
{
      
}

void tile_map::TileMapComponent::CreateBody() {
  new base_engine::Actor(owner_->GetGame());
}

tile_map::TileMapComponent::TileMapComponent(base_engine::Actor* owner,
                                             int update_order)
    : Component(owner, update_order),
      render_(new TileMapRenderComponent(owner, 50, this)) {}
