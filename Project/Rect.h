#pragma once
#include <Collision/Rectangle.h>

#include "IShape.h"

namespace base_engine {

class Rect final : public Mof::CRectangle, public IShape {
  Mof::CRectangle fix_;
 public:
  explicit Rect(const CRectangle& pObj);

  Rect(float left, float top, float right, float bottom);
  void Draw(const ShapeRenderComponent& drawable) override;
  bool Collision(const IShape* shape) const override;

  bool Collision(const class Rect& rect) const override;

  bool Collision(const class Circle& circle) const override;

  bool Collision(const Point& point) const override;
  void ChangeNotification() override;
};
}  // namespace base_engine
