#include "Point.h"

#include "Circle.h"
#include "Geometry2D.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
namespace base_engine {
Point::Point(float vx, float vy) : Vector2(vx, vy) {}

Point::Point(const Vector2& pObj) : Vector2(pObj) {}

void Point::Draw(const ShapeRenderComponent& drawable) { drawable.Draw(*this); }

bool Point::Collision(const IShape* shape) const {
  return shape->Collision(this);
}

bool Point::Collision(const Rect& rect) const {
  return Geometry2D::Intersect(static_cast<Mof::Vector2>(*this),
                               static_cast<Mof::CRectangle>(rect));
}

bool Point::Collision(const Circle& circle) const {
  return Geometry2D::Intersect(static_cast<Mof::Vector2>(*this),
                               static_cast<Mof::CCircle>(circle));
}

bool Point::Collision(const Point& point) const {
  return Geometry2D::Intersect(static_cast<Mof::Vector2>(*this),
                               static_cast<Mof::Vector2>(point));
}
}  // namespace base_engine
