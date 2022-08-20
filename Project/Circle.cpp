#include "Circle.h"

#include "Geometry2D.h"
#include "Point.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"

namespace base_engine {

Circle::Circle(const CCircle& pObj) : CCircle(pObj) { ChangeNotification(); }

Circle::Circle(float cx, float cy, float cr) : CCircle(cx, cy, cr) {
  ChangeNotification();
}

void Circle::Draw(const ShapeRenderComponent& drawable) {
  drawable.Draw(*this);
}

bool Circle::Collision(const Vector2& transform, const IShape* shape,
                       const Vector2& to_transform) const {
  return shape->Collision(to_transform, *this, transform);
}

bool Circle::Collision(const Vector2& transform, const Rect& rect,
                       const Vector2& rect_transform) const {
  return Geometry2D::Intersect((*this) + transform, rect + rect_transform);
}

bool Circle::Collision(const Vector2& transform, const Circle& circle,
                       const Vector2& circle_transform) const {
  return Geometry2D::Intersect((*this) + transform, circle + circle_transform);
}

bool Circle::Collision(const Vector2& transform, const Point& point,
                       const Vector2& point_transform) const {
  return Geometry2D::Intersect((*this) + transform, point + point_transform);
}
void Circle::ChangeNotification() {}

Mof::CRectangle Circle::AABB() const {
  const Mof::Vector2 pos(this->Position.x, this->Position.y);
  return Mof::CRectangle(pos - Mof::Vector2(1, 1) * r,
                         pos + Mof::Vector2(1, 1) * r);
}

Vector2 Circle::GetFarthestPoint(InVector2 transform, Vector2 direction) const
{
    return transform + VectorUtilities::Normalize(direction) * r;
}
}  // namespace base_engine