// @TileMapShape.h
// @brief
// @author ICE
// @date 2022/10/20
// 
// @details

#pragma once
#include "IShape.h"

class TileMapShape : public base_engine::IShape
{
public:
    void Draw(const base_engine::ShapeRenderComponent& drawable) override
    {
        
    }
    [[nodiscard]] bool Collision(const base_engine::Vector2& transform, const IShape* shape,
        const base_engine::Vector2& to_transform) const override
    {
        
    }
    [[nodiscard]] bool Collision(const base_engine::Vector2& transform, const base_engine::Rect& rect,
        const base_engine::Vector2& rect_transform) const override
    {
      assert(false,"Not Implementation");

      return false;
    }
    [[nodiscard]] bool Collision(const base_engine::Vector2& transform, const base_engine::Circle& circle,
        const base_engine::Vector2& circle_transform) const override {
      assert(false, "Not Implementation");
      return false;
    }
    [[nodiscard]] bool Collision(const base_engine::Vector2& transform, const base_engine::Point& point,
        const base_engine::Vector2& point_transform) const override {
      assert(false, "Not Implementation");
      return false;
    }
    [[nodiscard]] base_engine::Vector2 GetFarthestPoint(base_engine::InVector2 transform,
        base_engine::Vector2 direction) const override {
      assert(false, "Not Implementation");
      return {};
    }
    [[nodiscard]] const Mof::CRectangle& AABB() const override {
      assert(false, "Not Implementation");
      return {};
    }
    base_engine::ShapeType GetType() const override
    {
      return base_engine::ShapeType::kTileMap;
    }
    void ChangeNotification() override
    {
        
    }
};
