#pragma once

#include <Math/Vector2.h>

#include "IShape.h"

namespace base_engine {

class Point : public Mof::Vector2, public IShape {

 public:
  Point(float vx, float vy);

  explicit Point(const Vector2& pObj);

  void Draw(const ShapeRenderComponent& drawable) override;
  bool Collision(const Vector2&transform, const IShape* shape, const Vector2&to_transform) const override;

  [[nodiscard]] bool Collision(const base_engine::Vector2& transform, const Rect& rect, const base_engine::Vector2& rect_transform) const override;

  [[nodiscard]] bool Collision(const base_engine::Vector2& transform, const Circle& circle, const base_engine::Vector2& circle_transform) const override;

  [[nodiscard]] bool Collision(const base_engine::Vector2& transform, const Point& point, const base_engine::Vector2& point_transform) const override;

  void ChangeNotification() override;
  Mof::CRectangle AABB() const override { return {*this, *this}; }
  [[nodiscard]] Vector2 GetFarthestPoint(InVector2 transform, Vector2 direction) const override;

  ShapeType GetType() const override { return ShapeType::kPoint; }
};
}  // namespace base_engine
