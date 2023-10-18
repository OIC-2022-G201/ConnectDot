// @PhysicsBody2D.h
// @brief
// @author ICE
// @date 2022/10/13
//
// @details

#pragma once
#include "PhysicsComponentData.h"
#include "PhysicsShapes.h"
#include "PhysicsSweep.h"
#include "PhysicsTransform.h"
#include "PhysicsVector2.h"

namespace base_engine::physics {
class PhysicsContactEdge;
class PhysicsWorld;
class PhysicsShape;
struct PhysicsFixtureDef;

class PhysicsFixture;

enum class PhysicsBodyType { kStaticBody, kKinematicBody, kDynamicBody };
struct BodyDef

{
  /// This constructor sets the body definition default values.
  BodyDef() {
    position.Set(0.0f, 0.0f);
    angle = 0.0f;
    linearVelocity.Set(0.0f, 0.0f);
    angularVelocity = 0.0f;
    linearDamping = 0.0f;
    angularDamping = 0.0f;
    allowSleep = true;
    awake = true;
    fixedRotation = false;
    bullet = false;
    type = PhysicsBodyType::kStaticBody;
    enabled = true;
    gravityScale = 1.0f;
  }

  PhysicsBodyType type;

  PVec2 position{};

  float angle;

  PVec2 linearVelocity{};

  float angularVelocity;

  float linearDamping;

  float angularDamping;

  bool allowSleep;

  bool awake;

  bool fixedRotation;

  bool bullet;

  bool enabled;

  BodyUserComponentData userData;

  float gravityScale;
};

class PhysicsBody {
 public:
  /// Creates a fixture and attach it to this body. Use this function if you
  /// need to set some fixture parameters, like friction. Otherwise you can
  /// create the fixture directly from a shape. If the density is non-zero, this
  /// function automatically updates the mass of the body. Contacts are not
  /// created until the next time step.
  /// @param def the fixture definition.
  /// @warning This function is locked during callbacks.
  PhysicsFixture* CreateFixture(const PhysicsFixtureDef* def);

  /// Creates a fixture from a shape and attach it to this body.
  /// This is a convenience function. Use PhysicsFixtureDef if you need to set
  /// parameters like friction, restitution, user data, or filtering. If the
  /// density is non-zero, this function automatically updates the mass of the
  /// body.
  /// @param shape the shape to be cloned.
  /// @param density the shape density (set to zero for static bodies).
  /// @warning This function is locked during callbacks.
  PhysicsFixture* CreateFixture(const PhysicsShape* shape, float density);

  /// Destroy a fixture. This removes the fixture from the broad-phase and
  /// destroys all contacts associated with this fixture. This will
  /// automatically adjust the mass of the body if the body is dynamic and the
  /// fixture has positive density.
  /// All fixtures attached to a body are implicitly destroyed when the body is
  /// destroyed.
  /// @param fixture the fixture to be removed.
  /// @warning This function is locked during callbacks.
  void DestroyFixture(PhysicsFixture* fixture);

  /// Set the position of the body's origin and rotation.
  /// Manipulating a body's transform may cause non-physical behavior.
  /// Note: contacts are updated on the next call to PhysicsWorld::Step.
  /// @param position the world position of the body's local origin.
  /// @param angle the world rotation in radians.
  void SetTransform(const PVec2& position, float angle);

  /// Get the body transform for the body's origin.
  /// @return the world transform of the body's origin.
  [[nodiscard]] const PhysicsTransform& GetTransform() const { return m_xf; }

  /// Get the world body origin position.
  /// @return the world position of the body's origin.
  const PVec2& GetPosition() const { return m_xf.p; }

  /// Get the angle in radians.
  /// @return the current world rotation angle in radians.
  float GetAngle() const;

  /// Get the world position of the center of mass.
  const PVec2& GetWorldCenter() const;

  /// Get the local position of the center of mass.
  const PVec2& GetLocalCenter() const;

  /// Set the linear velocity of the center of mass.
  /// @param v the new linear velocity of the center of mass.
  void SetLinearVelocity(const PVec2& v);

  /// Get the linear velocity of the center of mass.
  /// @return the linear velocity of the center of mass.
  const PVec2& GetLinearVelocity() const;

  /// Set the angular velocity.
  /// @param omega the new angular velocity in radians/second.
  void SetAngularVelocity(float omega);

  /// Get the angular velocity.
  /// @return the angular velocity in radians/second.
  float GetAngularVelocity() const;

  /// Apply a force at a world point. If the force is not
  /// applied at the center of mass, it will generate a torque and
  /// affect the angular velocity. This wakes up the body.
  /// @param force the world force vector, usually in Newtons (N).
  /// @param point the world position of the point of application.
  /// @param wake also wake up the body
  void ApplyForce(const PVec2& force, const PVec2& point, bool wake);

  /// Apply a force to the center of mass. This wakes up the body.
  /// @param force the world force vector, usually in Newtons (N).
  /// @param wake also wake up the body
  void ApplyForceToCenter(const PVec2& force, bool wake);

  /// Apply a torque. This affects the angular velocity
  /// without affecting the linear velocity of the center of mass.
  /// @param torque about the z-axis (out of the screen), usually in N-m.
  /// @param wake also wake up the body
  void ApplyTorque(float torque, bool wake);

  /// Apply an impulse at a point. This immediately modifies the velocity.
  /// It also modifies the angular velocity if the point of application
  /// is not at the center of mass. This wakes up the body.
  /// @param impulse the world impulse vector, usually in N-seconds or kg-m/s.
  /// @param point the world position of the point of application.
  /// @param wake also wake up the body
  void ApplyLinearImpulse(const PVec2& impulse, const PVec2& point, bool wake);

  /// Apply an impulse to the center of mass. This immediately modifies the
  /// velocity.
  /// @param impulse the world impulse vector, usually in N-seconds or kg-m/s.
  /// @param wake also wake up the body
  void ApplyLinearImpulseToCenter(const PVec2& impulse, bool wake);

  /// Apply an angular impulse.
  /// @param impulse the angular impulse in units of kg*m*m/s
  /// @param wake also wake up the body
  void ApplyAngularImpulse(float impulse, bool wake);

  /// Get the total mass of the body.
  /// @return the mass, usually in kilograms (kg).
  float GetMass() const;

  /// Get the rotational inertia of the body about the local origin.
  /// @return the rotational inertia, usually in kg-m^2.
  float GetInertia() const;

  /// Get the mass data of the body.
  /// @return a struct containing the mass, inertia and center of the body.
  PhysicsMassData GetMassData() const;

  /// Set the mass properties to override the mass properties of the fixtures.
  /// Note that this changes the center of mass position.
  /// Note that creating or destroying fixtures can also alter the mass.
  /// This function has no effect if the body isn't dynamic.
  /// @param data the mass properties.
  void SetMassData(const PhysicsMassData* data);

  /// This resets the mass properties to the sum of the mass properties of the
  /// fixtures. This normally does not need to be called unless you called
  /// SetMassData to override the mass and you later want to reset the mass.
  void ResetMassData() {}

  /// Get the world coordinates of a point given the local coordinates.
  /// @param localPoint a point on the body measured relative the the body's
  /// origin.
  /// @return the same point expressed in world coordinates.
  PVec2 GetWorldPoint(const PVec2& localPoint) const;

  /// Get the world coordinates of a vector given the local coordinates.
  /// @param localVector a vector fixed in the body.
  /// @return the same vector expressed in world coordinates.
  PVec2 GetWorldVector(const PVec2& localVector) const;

  /// Gets a local point relative to the body's origin given a world point.
  /// @param worldPoint a point in world coordinates.
  /// @return the corresponding local point relative to the body's origin.
  PVec2 GetLocalPoint(const PVec2& worldPoint) const;

  /// Gets a local vector given a world vector.
  /// @param worldVector a vector in world coordinates.
  /// @return the corresponding local vector.
  PVec2 GetLocalVector(const PVec2& worldVector) const;

  /// Get the world linear velocity of a world point attached to this body.
  /// @param worldPoint a point in world coordinates.
  /// @return the world velocity of a point.
  PVec2 GetLinearVelocityFromWorldPoint(const PVec2& worldPoint) const;

  /// Get the world velocity of a local point.
  /// @param localPoint a point in local coordinates.
  /// @return the world velocity of a point.
  PVec2 GetLinearVelocityFromLocalPoint(const PVec2& localPoint) const;

  /// Get the linear damping of the body.
  float GetLinearDamping() const;

  /// Set the linear damping of the body.
  void SetLinearDamping(float linearDamping);

  /// Get the angular damping of the body.
  float GetAngularDamping() const;

  /// Set the angular damping of the body.
  void SetAngularDamping(float angularDamping);

  /// Get the gravity scale of the body.
  float GetGravityScale() const;

  /// Set the gravity scale of the body.
  void SetGravityScale(float scale);

  /// Set the type of this body. This may alter the mass and velocity.
  void SetType(PhysicsBodyType type);

  /// Get the type of this body.
  PhysicsBodyType GetType() const;

  /// Should this body be treated like a bullet for continuous collision
  /// detection?
  void SetBullet(bool flag);

  /// Is this body treated like a bullet for continuous collision detection?
  bool IsBullet() const;

  /// You can disable sleeping on this body. If you disable sleeping, the
  /// body will be woken.
  void SetSleepingAllowed(bool flag);

  /// Is this body allowed to sleep
  bool IsSleepingAllowed() const;

  /// Set the sleep state of the body. A sleeping body has very
  /// low CPU cost.
  /// @param flag set to true to wake the body, false to put it to sleep.
  void SetAwake(bool flag) {
    if (m_type == PhysicsBodyType::kStaticBody) {
      return;
    }

    if (flag) {
      m_flags |= e_awakeFlag;
      m_sleepTime = 0.0f;
    } else {
      m_flags &= ~e_awakeFlag;
      m_sleepTime = 0.0f;
      m_linearVelocity.SetZero();
      m_angularVelocity = 0.0f;
      m_force.SetZero();
      m_torque = 0.0f;
    }
  }

  /// Get the sleeping state of this body.
  /// @return true if the body is awake.
  bool IsAwake() const { return (m_flags & e_awakeFlag) == e_awakeFlag; }

  /// Allow a body to be disabled. A disabled body is not simulated and cannot
  /// be collided with or woken up.
  /// If you pass a flag of true, all fixtures will be added to the broad-phase.
  /// If you pass a flag of false, all fixtures will be removed from the
  /// broad-phase and all contacts will be destroyed.
  /// Fixtures and joints are otherwise unaffected. You may continue
  /// to create/destroy fixtures and joints on disabled bodies.
  /// Fixtures on a disabled body are implicitly disabled and will
  /// not participate in collisions, ray-casts, or queries.
  /// Joints connected to a disabled body are implicitly disabled.
  /// An diabled body is still owned by a PhysicsWorld object and remains
  /// in the body list.
  void SetEnabled(bool flag);

  /// Get the active state of the body.
  bool IsEnabled() const;

  /// Set this body to have fixed rotation. This causes the mass
  /// to be reset.
  void SetFixedRotation(bool flag);

  /// Does this body have fixed rotation?
  bool IsFixedRotation() const;

  /// Get the list of all fixtures attached to this body.
  PhysicsFixture* GetFixtureList() { return this->m_fixtureList; }

  /// Get the list of all contacts attached to this body.
  /// @warning this list changes during the time step and you may
  /// miss some collisions if you don't use PhysicsContactListener.
  PhysicsContactEdge* GetContactList() { return m_contactList; }
  const PhysicsContactEdge* GetContactList() const { return m_contactList; }

  /// Get the next body in the world's body list.
  PhysicsBody* GetNext();
  const PhysicsBody* GetNext() const;

  /// Get the user data pointer that was provided in the body definition.
  BodyUserComponentData& GetUserData();
  const BodyUserComponentData& GetUserData() const;

  /// Get the parent world of this body.
  PhysicsWorld* GetWorld();
  const PhysicsWorld* GetWorld() const;

  /// Dump this body to a file
  void Dump();

 private:
  friend class PhysicsWorld;
  friend class PhysicsContactManager;

  // m_flags
  enum {
    e_islandFlag = 0x0001,
    e_awakeFlag = 0x0002,
    e_autoSleepFlag = 0x0004,
    e_bulletFlag = 0x0008,
    e_fixedRotationFlag = 0x0010,
    e_enabledFlag = 0x0020,
    e_toiFlag = 0x0040
  };

  void SynchronizeFixtures();
  void SynchronizeTransform();

  // This is used to prevent connected bodies from colliding.
  // It may lie, depending on the collideConnected flag.
  bool ShouldCollide(const PhysicsBody* other) const;

  void Advance(float t);

  PhysicsBodyType m_type;

  uint16_t m_flags;

  int32_t m_islandIndex;

  PhysicsTransform m_xf;  // the body origin transform
  PhysicsSweep m_sweep;   // the swept motion for CCD

  PVec2 m_linearVelocity;
  float m_angularVelocity;

  PVec2 m_force;
  float m_torque;

  class PhysicsWorld* m_world;
  PhysicsBody* m_prev;
  PhysicsBody* m_next;

  PhysicsFixture* m_fixtureList;
  int32_t m_fixtureCount;

  PhysicsContactEdge* m_contactList = nullptr;
  float m_mass, m_invMass;

  // Rotational inertia about the center of mass.
  float m_I, m_invI;

  float m_linearDamping;
  float m_angularDamping;
  float m_gravityScale;

  float m_sleepTime;

  BodyUserComponentData m_userData;

  PhysicsBody(const BodyDef* bd, PhysicsWorld* physics_world);
};

}  // namespace base_engine::physics