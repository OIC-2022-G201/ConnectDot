#include "Point.h"

#include "Circle.h"
#include "Geometry2D.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
namespace base_engine {
Point::Point(float vx, float vy) : Vector2(vx, vy) { ChangeNotification(); }

Point::Point(const Vector2& pObj) : Vector2(pObj) { ChangeNotification(); }

void Point::Draw(const ShapeRenderComponent& drawable) { drawable.Draw(*this); }

bool Point::Collision(const Vector2&transform, const IShape* shape, const Vector2&to_transform) const {
  return shape->Collision(to_transform, *this, transform);
}

bool Point::Collision(const Vector2& transform, const Rect& rect, const Vector2& rect_transform) const {
  return Geometry2D::Intersect((*this) + transform,
                               rect + rect_transform);
}

bool Point::Collision(const Vector2& transform, const Circle& circle, const Vector2& circle_transform) const {
  return Geometry2D::Intersect((*this) + transform, circle + circle_transform);
}

bool Point::Collision(const Vector2& transform, const Point& point, const Vector2& point_transform) const {
  return Geometry2D::Intersect((*this) + transform,
                               point + point_transform);
}
void Point::ChangeNotification() {
}

Vector2 Point::GetFarthestPoint(InVector2 transform, Vector2 direction) const
{
    return *this + transform;
}
}  // namespace base_engine
