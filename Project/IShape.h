#pragma once
namespace base_engine {
class IShape {
 public:
    virtual ~IShape();

    virtual void Draw(const class ShapeRenderComponent& drawable) = 0;
};
}  // namespace base_engine