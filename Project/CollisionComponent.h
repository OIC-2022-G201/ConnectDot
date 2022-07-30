#pragma once
#include <bitset>
#include <complex>
#include <memory>

#include "Component.h"
#include "Pow.h"
namespace base_engine {
constexpr size_t kCollisionFilterSize = 32;
constexpr std::bitset<kCollisionFilterSize> kCollisionFilterAllMask(
    (1ul << kCollisionFilterSize) - 1);
class CollisionComponent final : public Component {
  std::shared_ptr<class IShape> shape_;
  std::bitset<kCollisionFilterSize> target_layer_;
  std::bitset<kCollisionFilterSize> object_layer_;

 public:
  CollisionComponent(class Actor* owner, int update_order);
  [[nodiscard]] IShape* GetShape() const;
  void SetShape(const std::shared_ptr<class IShape>& shape);
  bool Collision(CollisionComponent* target) const;
  void SetTargetFilter(const std::bitset<kCollisionFilterSize>& layer);
  [[nodiscard]] const std::bitset<kCollisionFilterSize>& GetTargetFilter() const;
  void SetObjectFilter(const std::bitset<kCollisionFilterSize>& layer);
  [[nodiscard]] const std::bitset<kCollisionFilterSize>& GetObjectFilter() const;;

  bool IsMatch(CollisionComponent* target) const;
  void CollisionSender(CollisionComponent* target);
  ~CollisionComponent() override;
  void Update() override;
  [[nodiscard]] Actor* GetActor() const
  { return owner_;
  }
};
inline bool CollisionComponent::IsMatch(CollisionComponent* target) const {
  return ((target_layer_ & target->object_layer_) != 0) ||
         ((object_layer_ & target->target_layer_) != 0);
}
}  // namespace base_engine
