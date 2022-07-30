#include "Rect.h"

#include "Geometry2D.h"
#include "ShapeRenderComponent.h"

#include "Circle.h"
#include "Point.h"
namespace base_engine {
    Rect::Rect(const CRectangle& pObj): CRectangle(pObj)
    {}

    void Rect::ChangeNotification()
    {
        fix = static_cast<CRectangle>(*this);
        fix.Translation(offset_);
    }

Rect::Rect(float left, float top, float right, float bottom)
    : Mof::CRectangle(left, top, right, bottom) {}

void Rect::Draw(const ShapeRenderComponent& drawable) {
  drawable.Draw(*this);
}
bool Rect::Collision(const IShape* shape) const {

  return shape->Collision(Rect(fix));
}

bool Rect::Collision(const Rect& rect) const {
  return Geometry2D::Intersect(fix,
                               static_cast<Mof::CRectangle>(rect));
}

bool Rect::Collision(const Circle& circle) const {
  return Geometry2D::Intersect(fix,
                               static_cast<Mof::CCircle>(circle));
}

bool Rect::Collision(const Point& point) const {
  return Geometry2D::Intersect(fix,
                               static_cast<Mof::Vector2>(point));
}


}  // namespace base_engine