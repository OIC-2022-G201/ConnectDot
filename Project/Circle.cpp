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

bool Circle::Collision(const IShape* shape) const {
  return shape->Collision(Circle(fix_));
}

bool Circle::Collision(const Rect& rect) const {
  return Geometry2D::Intersect(fix_,
                               static_cast<Mof::CRectangle>(rect.fix_));
}

bool Circle::Collision(const Circle& circle) const {
  return Geometry2D::Intersect(fix_, static_cast<Mof::CCircle>(circle.fix_));
}

bool Circle::Collision(const Point& point) const {
  return Geometry2D::Intersect(fix_, static_cast<Mof::Vector2>(point.fix_));
}
void Circle::ChangeNotification(){
  fix_ = static_cast<CCircle>(*this);
  fix_.Translation(offset_);
}

Mof::CRectangle Circle::AABB() const
{
    const Mof::Vector2 pos(fix_.Position.x,fix_.Position.y);
    return 
        Mof::CRectangle(pos - Mof::Vector2(1, 1) * r,
                        pos + Mof::Vector2(1, 1) * r);
}
}  // namespace base_engine