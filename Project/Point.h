#pragma once

#include <Math/Vector2.h>

#include "IShape.h"

namespace base_engine {

class Point : public Mof::Vector2, public IShape {
  Mof::Vector2 fix_;

 public:
  Point(float vx, float vy);

  explicit Point(const Vector2& pObj);

  void Draw(const ShapeRenderComponent& drawable) override;
  bool Collision(const IShape* shape) const override;

  [[nodiscard]] bool Collision(const Rect& rect) const override;
  
  [[nodiscard]] bool Collision(const Circle& circle) const override;

  [[nodiscard]] bool Collision(const Point& point) const override;

  void ChangeNotification() override;
};
}  // namespace base_engine
