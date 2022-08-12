﻿// @file TileMapComponent.h
// @brief マップチップを読み込んでマップを描画する
// @author ICE
// @date 2022/08/12
//
// @details

#pragma once
#include <Utilities/GraphicsUtilities.h>

#include <vector>

#include "Component.h"
#include "IShape.h"
#include "RenderComponent.h"
#include "TileMap.h"

namespace tile_map {

class TileMapComponent : public base_engine::Component {
  class TileMapRenderComponent : public base_engine::RenderComponent {
    TileMapComponent* tile_map_;

   public:
    TileMapRenderComponent(base_engine::Actor* owner, int draw_order,
                           TileMapComponent* tile_map)
        : RenderComponent(owner, draw_order), tile_map_(tile_map) {}

    void Draw() override {
      Mof::Vector2 p = owner_->GetPosition();
      Mof::CRectangle rect;
      for (int y = 0; y < tile_map_->map_.GetYCount(); ++y) {
        for (int x = 0; x < tile_map_->map_.GetXCount(); ++x) {
          if (tile_map_->map_.GetCell(x, y) == kEmptyCell) continue;
          Mof::CGraphicsUtilities::RenderRect(
              Mof::CRectangle{
                  static_cast<MofFloat>(x), static_cast<MofFloat>(y),
                  static_cast<MofFloat>(x + 1), static_cast<MofFloat>(y + 1)} *
                  128,
              MOF_COLOR_WHITE);
          rect.Translation({128, 0});
        }
        rect.Translation({0, 128});
      }
    }

   private:
  };

 public:
  void Start() override;
  void Update() override;

  void Load();

 public:
  void CreateBody();
  TileMapComponent(base_engine::Actor* owner, int update_order);

private:
  Layer map_{15, 9};
 std::vector<std::shared_ptr<base_engine::Rect>> tile_shape_;
  TileMapRenderComponent* render_ = nullptr;
};
}  // namespace tile_map