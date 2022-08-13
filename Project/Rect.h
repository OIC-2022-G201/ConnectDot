#pragma once
#include <Collision/Rectangle.h>

#include "IShape.h"
#include "TileMapComponent.h"

namespace base_engine {

class Rect final : public Mof::CRectangle, public IShape {

 public:
  Mof::CRectangle fix_;
  explicit Rect(const CRectangle& pObj);

  Rect(const Rect& other)
      : Mof::CRectangle(other), IShape(other), fix_(other.fix_) {}

  Rect& operator=(const Rect& other) {
    if (this == &other) return *this;
    Mof::CRectangle::operator=(other);
    IShape::operator=(other);
    fix_ = other.fix_;
    return *this;
  }

  Rect(float left, float top, float right, float bottom);
  void Draw(const ShapeRenderComponent& drawable) override;
  bool Collision(const IShape* shape) const override;

  bool Collision(const class Rect& rect) const override;

  bool Collision(const class Circle& circle) const override;

  bool Collision(const Point& point) const override;
  void ChangeNotification() override;
  Mof::CRectangle AABB() const override { return fix_; }
};
}  // namespace base_engine
