#include "Circle.h"

#include "Geometry2D.h"
#include "Point.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"

namespace base_engine {

Circle::Circle(const CCircle& pObj) : CCircle(pObj) {}

Circle::Circle(float cx, float cy, float cr) : CCircle(cx, cy, cr) {}

void Circle::Draw(const ShapeRenderComponent& drawable) {
  drawable.Draw(*this);
}

bool Circle::Collision(const IShape* shape) const {
  return shape->Collision(this);
}

bool Circle::Collision(const Rect& rect) const {
  return Geometry2D::Intersect(static_cast<Mof::CCircle>(*this),
                               static_cast<Mof::CRectangle>(rect));
}

bool Circle::Collision(const Circle& circle) const {
  return Geometry2D::Intersect(static_cast<Mof::CCircle>(*this),
                               static_cast<Mof::CCircle>(circle));
}

bool Circle::Collision(const Point& point) const {
  return Geometry2D::Intersect(static_cast<Mof::CCircle>(*this),
                               static_cast<Mof::Vector2>(point));
}
}  // namespace base_engine