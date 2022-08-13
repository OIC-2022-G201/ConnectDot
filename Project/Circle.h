#pragma once
#include <Collision/Circle.h>

#include "IShape.h"
namespace base_engine {

class Circle final : public Mof::CCircle, public IShape {

 public:
  Mof::CCircle fix_;

  explicit Circle(const CCircle& pObj);

  Circle(float cx, float cy, float cr);

  void Draw(const ShapeRenderComponent& drawable) override;

  bool Collision(const IShape* shape) const override;

  bool Collision(const Rect& rect) const override;

  bool Collision(const Circle& circle) const override;

  bool Collision(const Point& point) const override;

  void ChangeNotification() override;
  Mof::CRectangle AABB() const override;
};
}  // namespace base_engine
