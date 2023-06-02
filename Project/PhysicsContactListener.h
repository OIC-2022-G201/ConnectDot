// @PhysicsContactListener.h
// @brief
// @author ICE
// @date 2022/10/17
//
// @details

#pragma once
#include "PhysicsManifold.h"

namespace base_engine::physics {
class PhysicsContact;
struct PhysicsContactImpulse {
  float normalImpulses[Physics_maxManifoldPoints];
  float tangentImpulses[Physics_maxManifoldPoints];
  int32_t count;
};

class IPhysicsContactListener {
 public:
  virtual ~IPhysicsContactListener() {}

  /// Called when two fixtures begin to touch.
  virtual void BeginContact(PhysicsContact* contact) {}

  /// Called when two fixtures cease to touch.
  virtual void EndContact(PhysicsContact* contact) {}

  /// This is called after a contact is updated. This allows you to inspect a
  /// contact before it goes to the solver. If you are careful, you can modify
  /// the contact manifold (e.g. disable contact). A copy of the old manifold is
  /// provided so that you can detect changes. Note: this is called only for
  /// awake bodies. Note: this is called even when the number of contact points
  /// is zero. Note: this is not called for sensors. Note: if you set the number
  /// of contact points to zero, you will not get an EndContact callback.
  /// However, you may get a BeginContact callback the next step.
  virtual void PreSolve(PhysicsContact* contact,
                        const PhysicsManifold* oldManifold) {}

  /// This lets you inspect a contact after the solver is finished. This is
  /// useful for inspecting impulses. Note: the contact manifold does not
  /// include time of impact impulses, which can be arbitrarily large if the
  /// sub-step is small. Hence the impulse is provided explicitly in a separate
  /// data structure. Note: this is only called for contacts that are touching,
  /// solid, and awake.
  virtual void PostSolve(PhysicsContact* contact,
                         const PhysicsContactImpulse* impulse) {}
};

class PhysicsContactListener : public IPhysicsContactListener {
 public:
  ~PhysicsContactListener() override = default;
  void BeginContact(PhysicsContact* contact) override {}
  void EndContact(PhysicsContact* contact) override {}
  void PreSolve(PhysicsContact* contact,
                const PhysicsManifold* oldManifold) override {}
  void PostSolve(PhysicsContact* contact,
                 const PhysicsContactImpulse* impulse) override {}
};
}  // namespace base_engine::physics
