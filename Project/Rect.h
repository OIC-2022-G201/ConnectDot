#pragma once
#include <Collision/Rectangle.h>

#include "IShape.h"
#include "TileMapComponent.h"

namespace base_engine {

class Rect final : public Mof::CRectangle, public IShape {
  
 public:
  explicit Rect(const CRectangle& pObj);

  Rect(const Rect& other)
      : Mof::CRectangle(other), IShape(other) {}

  Rect& operator=(const Rect& other) {
    if (this == &other) return *this;
    Mof::CRectangle::operator=(other);
    IShape::operator=(other);
    return *this;
  }

  Rect(float left, float top, float right, float bottom);
  void Draw(const ShapeRenderComponent& drawable) override;
  bool Collision(const Vector2&transform, const IShape* shape, const Vector2&to_transform) const override;

  bool Collision(const Vector2& transform, const class Rect& rect, const Vector2& rect_transform) const override;

  bool Collision(const Vector2& transform, const class Circle& circle, const Vector2& circle_transform) const override;

  bool Collision(const Vector2& transform, const Point& point, const Vector2& point_transform) const override;
  void ChangeNotification() override;
  Mof::CRectangle AABB() const override;
  
  /**
   * @todo 四角形用に最適化を行う
   */
  [[nodiscard]] Vector2 GetFarthestPoint(InVector2 transform, Vector2 direction) const override;
};
}  // namespace base_engine
