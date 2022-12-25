#pragma once
#include <bitset>
#include <complex>
#include <memory>

#include "Actor.h"
#include "Component.h"
#include "ComponentParameter.h"
#include "PhysicsBody2D.h"
#include "Rect.h"
#include "SendManifold.h"

namespace base_engine {
namespace physics {
class PhysicsBody;
}

constexpr size_t kCollisionFilterSize = 32;
constexpr std::bitset<kCollisionFilterSize> kCollisionFilterAllMask(
    (1ull << kCollisionFilterSize) - 1);
class CollisionComponent : public Component {
 public:
  CollisionComponent(class Actor* owner,
                     int update_order = kCollisionUpdateOrder);
  ~CollisionComponent() override;

  [[nodiscard]] IShape* GetShape() const;
  void SetShape(const std::shared_ptr<IShape> shape);
  void Sync();
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
  void Update() override;
  [[nodiscard]] Actor* GetActor() const { return owner_; }
  Mof::CRectangle AABB() const { return GetShape()->AABB() + GetPosition(); }
  void Start() override;

  [[nodiscard]] class PhysicsBodyComponent* GetPhysicsBody();
  void SetPhysicsBody(class PhysicsBodyComponent* body) { body_ = body; }
  void SetPhysicsBody(physics::PhysicsBody* physics_body) {
    physics_body_ = physics_body;
  }
  physics::PhysicsBody* GetEnginePhysicsBody() const { return physics_body_; }
  void SyncPosition();

 private:
  std::shared_ptr<class IShape> shape_{};
  std::bitset<kCollisionFilterSize> target_layer_;
  std::bitset<kCollisionFilterSize> object_layer_;
  class PhysicsBodyComponent* body_ = nullptr;
  bool is_trigger_ = false;
  physics::PhysicsBody* physics_body_ = nullptr;
  [[nodiscard]] Vector2 GetPosition() const { return owner_->GetPosition(); }

  bool is_start_ = false;
};
inline bool CollisionComponent::IsMatch(CollisionComponent* target) const {
  return ((target_layer_ & target->object_layer_) != 0) ||
         ((object_layer_ & target->target_layer_) != 0);
}
}  // namespace base_engine
