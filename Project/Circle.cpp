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
  return shape->Collision(Circle(fix));
}

bool Circle::Collision(const Rect& rect) const {
  return Geometry2D::Intersect(fix_,
                               static_cast<Mof::CRectangle>(rect));
}

bool Circle::Collision(const Circle& circle) const {
  return Geometry2D::Intersect(fix_,
                               static_cast<Mof::CCircle>(circle));
}

bool Circle::Collision(const Point& point) const {
  return Geometry2D::Intersect(fix_,
                               static_cast<Mof::Vector2>(point));
}
void Circle::ChangeNotification(){
  fix_ = static_cast<CCircle>(*this);
  fix_.Translation(offset_);
}
}  // namespace base_engine