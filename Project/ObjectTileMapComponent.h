// @ObjectTileMapComponent.h
// @brief
// @author ICE
// @date 2022/12/20
//
// @details

#pragma once
#include "Component.h"
#include "GridPosition.h"
#include "TileMap.h"
namespace tile_map {
constexpr Layer::CellType kCanOnPlace = 10;

class ObjectTileMapComponent : public base_engine::Component {
 public:
  explicit ObjectTileMapComponent(base_engine::Actor* owner)
      : Component(owner) {}

  void Start() override {}

  void Update() override {}

  [[nodiscard]] Layer::CellType GetCell(const GridPosition& pos) const {
    return GetCell(pos.x, pos.y);
  }

  [[nodiscard]] Layer::CellType GetCell(const size_t x, const size_t y) const {
    if (map_.GetXCount() <= x) {
      return kEmptyCell;
    }
    if (map_.GetYCount() <= y) {
      return kEmptyCell;
    }

    return map_.GetCell(x, y);
  }

  void SetCell(const size_t x, const size_t y, const Layer::CellType type) {
    if (map_.GetXCount() <= x) {
      return;
    }
    if (map_.GetYCount() <= y) {
      return;
    }
    map_.SetCell(x, y, type);
  }
  void SetCell(const GridPosition& pos, const Layer::CellType type) {
    SetCell(pos.x, pos.y, type);
  }

 private:
  Layer map_{200, 200};
};
}  // namespace tile_map
