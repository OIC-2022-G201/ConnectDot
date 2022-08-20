#include "TileMapComponent.h"

#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "Rect.h"

void tile_map::TileMapComponent::Start() { Load(); }

void tile_map::TileMapComponent::Update() {}

void tile_map::TileMapComponent::Load() {
  tile_shape_.emplace_back(new base_engine::Rect(0, 0, 128, 128));
  for (int y = 0; y < 9; ++y) {
    /*
  map_.SetCell(0, y, 1);
  auto cell = new base_engine::Actor(owner_->GetGame());
  cell->SetPosition({0, static_cast<MofFloat>(y * 128)});
  cell->SetTag("Field");
  auto collision = new base_engine::CollisionComponent(cell,100);
  collision->SetObjectFilter(kFieldObjectFilter);
  collision->SetTargetFilter(kFieldTargetFilter);
    collision->SetShape(tile_shape_[0]);
  */
  }
  for (int x = 0; x < 3; ++x) {
    map_.SetCell(x, 6, 1);
    auto cell = new base_engine::Actor(owner_->GetGame());
    cell->SetTag("Field");
    cell->SetPosition({static_cast<MofFloat>(x * 128), 6 * 128});
    auto collision = new base_engine::CollisionComponent(cell);
    collision->SetObjectFilter(kFieldObjectFilter);
    collision->SetTargetFilter(kFieldTargetFilter);
    collision->SetShape(
        std::make_shared<base_engine::Rect>(*tile_shape_[0].get()));
  }
  for (int x = 0; x < 15; ++x) {
    map_.SetCell(x, 8, 1);
    auto cell = new base_engine::Actor(owner_->GetGame());
    cell->SetTag("Field");
    cell->SetPosition({static_cast<MofFloat>(x * 128), 8 * 128});
    auto collision = new base_engine::CollisionComponent(cell);
    collision->SetObjectFilter(kFieldObjectFilter);
    collision->SetTargetFilter(kFieldTargetFilter);
    collision->SetShape(
        std::make_shared<base_engine::Rect>(*tile_shape_[0].get()));
  }
}

void tile_map::TileMapComponent::CreateBody() {
  new base_engine::Actor(owner_->GetGame());
}

tile_map::TileMapComponent::TileMapComponent(base_engine::Actor* owner,
                                             int update_order)
    : Component(owner, update_order),
      render_(new TileMapRenderComponent(owner, 50, this)) {}
