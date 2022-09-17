#pragma once
#include <Collision/Circle.h>

#include "IShape.h"
#include "VectorUtilities.h"

namespace base_engine {

class Circle final : public Mof::CCircle, public IShape {
 public:
  explicit Circle(const CCircle& pObj);

  Circle(float cx, float cy, float cr);

  void Draw(const class ShapeRenderComponent& drawable) override;

  bool Collision(const Vector2& transform, const IShape* shape,
                 const Vector2& to_transform) const override;

  bool Collision(const Vector2& transform, const class Rect& rect,
                 const Vector2& rect_transform) const override;

  bool Collision(const Vector2& transform, const base_engine::Circle& circle,
                 const Vector2& circle_transform) const override;

  bool Collision(const Vector2& transform, const class Point& point,
                 const Vector2& point_transform) const override;

  void ChangeNotification() override;
  Mof::CRectangle AABB() const override;
  [[nodiscard]] Vector2 GetFarthestPoint(InVector2 transform,
                                         Vector2 direction) const override;
  ShapeType GetType() const override { return ShapeType::kCircle; }
};
}  // namespace base_engine
