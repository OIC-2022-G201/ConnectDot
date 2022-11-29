// @file TileMapComponent.h
// @brief マップチップを読み込んでマップを描画する
// @author ICE
// @date 2022/08/12
//
// @details

#pragma once

#include <vector>

#include "BaseEngineCore.h"
#include "Component.h"
#include "GridPosition.h"
#include "IBaseEngineRender.h"
#include "IShape.h"
#include "RenderComponent.h"
#include "TileMap.h"

namespace tile_map {

class TileMapComponent : public base_engine::Component {
  class TileMapRenderComponent final : public base_engine::RenderComponent {
    TileMapComponent* tile_map_;

   public:
    TileMapRenderComponent(base_engine::Actor* owner, int draw_order,
                           TileMapComponent* tile_map);

    void Draw() override;

   private:
  };

 public:
  void Start() override;
  void Update() override;

  void Load(std::string_view path);
  
  void CreateBody();
  TileMapComponent(base_engine::Actor* owner, int update_order);

  [[nodiscard]] Layer::CellType GetCell(const GridPosition& pos) const {
    return GetCell(pos.x, pos.y);
  }

  [[nodiscard]] Layer::CellType GetCell(const size_t x, const size_t y) const {
    return map_.GetCell(x, y);
  }

 private:
  int cell_width_ = 100;
  int cell_height_ = 100;
  int cell_size_ = 128;
  Layer map_{};
  std::vector<std::shared_ptr<base_engine::Rect>> tile_shape_;
  TileMapRenderComponent* render_ = nullptr;

  Mof::LPTexture texture_ = nullptr;
  std::vector<Mof::Rectangle> s_rectangles_{};
};
}  // namespace tile_map