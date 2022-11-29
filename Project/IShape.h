#pragma once
#include <Collision/Rectangle.h>
#include <Math/Vector2.h>

#include "Vector.h"
#include "VectorUtilities.h"

namespace base_engine {
class Circle;
class Rect;
class Point;

enum class ShapeType { kNone, kRect, kCircle, kPoint,kTileMap };
class IShape {
 protected:
    static Vector2 FindFurthestPoint(const std::vector<Vector2>& vertices,
                                     const Vector2& direction)
    {
    Vector2 maxPoint;
    float maxDistance = -FLT_MAX;

    for (const Vector2& vertex : vertices) {
        if (const float distance = VectorUtilities::Dot(vertex, direction); distance > maxDistance) {
        maxDistance = distance;
        maxPoint = vertex;
      }
    }

    return maxPoint;
  }

 public:
  virtual ~IShape();

  virtual void Draw(const class ShapeRenderComponent& drawable) = 0;
  [[nodiscard]] virtual bool Collision(const Vector2& transform,
                                       const IShape* shape,
                                       const Vector2& to_transform) const = 0;

  [[nodiscard]] virtual bool Collision(const Vector2& transform,
                                       const base_engine::Rect& rect,
                                       const Vector2& rect_transform) const = 0;

  [[nodiscard]] virtual bool Collision(
      const Vector2& transform, const base_engine::Circle& circle,
      const Vector2& circle_transform) const = 0;

  [[nodiscard]] virtual bool Collision(
      const Vector2& transform, const base_engine::Point& point,
      const Vector2& point_transform) const = 0;
  [[nodiscard]] virtual Vector2 GetFarthestPoint(InVector2 transform,
                                                 Vector2 direction) const = 0;
  void SetOffset(const Mof::Vector2& offset) { ChangeNotification(); }

  [[nodiscard]] virtual const Mof::CRectangle& AABB() const = 0;
  virtual ShapeType GetType() const = 0;
  virtual void ChangeNotification() = 0;
};
}  // namespace base_engine