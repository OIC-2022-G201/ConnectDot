#include "Rect.h"

#include "Geometry2D.h"
#include "ShapeRenderComponent.h"

#include "Circle.h"
#include "Point.h"
namespace base_engine {
    Rect::Rect(const CRectangle& pObj): CRectangle(pObj) { ChangeNotification(); }

    void Rect::ChangeNotification()
    {

    }

    const Mof::CRectangle& Rect::AABB() const
    { return static_cast<CRectangle>(*this); }

    Vector2 Rect::GetFarthestPoint(InVector2 transform, Vector2 direction) const
    {

        return FindFurthestPoint(
            {GetTopLeft() + transform, GetTopRight() + transform,
                GetBottomRight() + transform, GetBottomLeft() + transform},
            direction);
    }

    Rect::Rect(float left, float top, float right, float bottom)
        : Mof::CRectangle(left, top, right, bottom) {
      ChangeNotification();
    }

void Rect::Draw(const ShapeRenderComponent& drawable) {
  drawable.Draw(*this);
}
bool Rect::Collision(const Vector2&transform, const IShape* shape, const Vector2&to_transform) const {

  return shape->Collision(to_transform, *this,transform);
}

bool Rect::Collision(const Vector2& transform, const Rect& rect, const Vector2& rect_transform) const {
  return Geometry2D::Intersect((*this) + transform,rect + rect_transform);
}

bool Rect::Collision(const Vector2& transform, const Circle& circle, const Vector2& circle_transform) const {
  return Geometry2D::Intersect((*this) + transform,
                               circle + circle_transform);
}

bool Rect::Collision(const Vector2& transform, const Point& point, const Vector2& point_transform) const {
  return Geometry2D::Intersect((*this) + transform,
                               point + point_transform);
}


}  // namespace base_engine