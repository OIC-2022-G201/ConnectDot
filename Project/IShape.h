#pragma once
#include <Math/Vector2.h>

namespace base_engine {
class IShape {
protected:
  Mof::Vector2 offset_;
 public:
    virtual ~IShape();

    virtual void Draw(const class ShapeRenderComponent& drawable) = 0;
    [[nodiscard]] virtual bool Collision(const IShape* shape) const = 0;
    [[nodiscard]] virtual bool Collision(const class Rect& rect) const = 0;
    [[nodiscard]] virtual bool Collision(const class Circle& circle) const = 0;
    [[nodiscard]] virtual bool Collision(const class Point& point) const = 0;
    void SetOffset(const Mof::Vector2& offset)
    {
      offset_ = offset;
      ChangeNotification();
    }
    virtual void ChangeNotification() = 0;
};
}  // namespace base_engine