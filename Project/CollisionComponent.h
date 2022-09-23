#pragma once
#include <bitset>
#include <complex>
#include <memory>

#include "Actor.h"
#include "Component.h"
#include "ComponentParameter.h"
#include "SendManifold.h"
#include "Rect.h"

namespace base_engine {
constexpr size_t kCollisionFilterSize = 32;
constexpr std::bitset<kCollisionFilterSize> kCollisionFilterAllMask(
    (1ull << kCollisionFilterSize) - 1);
class CollisionComponent : public Component {
 public:
  CollisionComponent(class Actor* owner,
                     int update_order = kCollisionUpdateOrder);
  [[nodiscard]] IShape* GetShape() const;
  void SetShape(const std::shared_ptr<IShape>& shape);
  physics::Manifold Collision(const CollisionComponent* target) const;
  void SetTargetFilter(const std::bitset<kCollisionFilterSize>& layer);
  [[nodiscard]] const std::bitset<kCollisionFilterSize>& GetTargetFilter()
      const;
  void SetObjectFilter(const std::bitset<kCollisionFilterSize>& layer);
  [[nodiscard]] const std::bitset<kCollisionFilterSize>& GetObjectFilter()
      const;
  void SetTrigger(const bool trigger) { is_trigger_ = trigger; }
  bool GetTrigger() const { return is_trigger_; }
  bool IsMatch(CollisionComponent* target) const;
  void CollisionSender(const SendManifold& manifold);
  ~CollisionComponent() override;
  void Update() override;
  [[nodiscard]] Actor* GetActor() const { return owner_; }
  Mof::CRectangle AABB() const { return GetShape()->AABB() + GetPosition(); }
  void Start() override;

  [[nodiscard]] class PhysicsBodyComponent* GetPhysicsBody() const
  {
    return body_;
  }
    void SetPhysicsBody(class PhysicsBodyComponent* body) { body_ = body; }
 private:
  std::shared_ptr<class IShape> shape_;
  std::bitset<kCollisionFilterSize> target_layer_;
  std::bitset<kCollisionFilterSize> object_layer_;
  class PhysicsBodyComponent* body_ = nullptr;
  bool is_trigger_ = false;

  [[nodiscard]] Vector2 GetPosition() const { return owner_->GetPosition(); }
};
inline bool CollisionComponent::IsMatch(CollisionComponent* target) const {
  return ((target_layer_ & target->object_layer_) != 0) ||
         ((object_layer_ & target->target_layer_) != 0);
}
}  // namespace base_engine
