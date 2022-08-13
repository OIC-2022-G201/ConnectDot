#include "Point.h"

#include "Circle.h"
#include "Geometry2D.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
namespace base_engine {
Point::Point(float vx, float vy) : Vector2(vx, vy) { ChangeNotification(); }

Point::Point(const Vector2& pObj) : Vector2(pObj) { ChangeNotification(); }

void Point::Draw(const ShapeRenderComponent& drawable) { drawable.Draw(*this); }

bool Point::Collision(const IShape* shape) const {
  return shape->Collision(Point(fix_));
}

bool Point::Collision(const Rect& rect) const {
  return Geometry2D::Intersect(fix_,
                               static_cast<Mof::CRectangle>(rect.fix_));
}

bool Point::Collision(const Circle& circle) const {
  return Geometry2D::Intersect(fix_, static_cast<Mof::CCircle>(circle.fix_));
}

bool Point::Collision(const Point& point) const {
  return Geometry2D::Intersect(fix_, static_cast<Mof::Vector2>(point.fix_));
}
void Point::ChangeNotification() {
  fix_ = static_cast<Mof::Vector2>(*this);
  fix_ += offset_;
}
}  // namespace base_engine
