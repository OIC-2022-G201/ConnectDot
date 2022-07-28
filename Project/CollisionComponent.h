#pragma once
#include <memory>

#include "Component.h"
namespace base_engine {
class CollisionComponent final : public Component {
  class IShape* shape_;

 public:
  CollisionComponent(class Actor* owner, int update_order);
  [[nodiscard]] IShape* GetShape() const;
  void SetShape(IShape* shape);
  void CollisionSender(CollisionComponent* target);
};
}  // namespace base_engine
