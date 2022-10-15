// @PhysicsFixture.h
// @brief
// @author かき氷氷味
// @date 2022/10/13
//
// @details

#pragma once
#include "PhysicsCollision.h"
#include "PhysicsComponentData.h"

namespace base_engine::physics {
class b2Shape;
struct b2Filter {
  b2Filter() {
    categoryBits = 0x0001u;
    maskBits = 0xFFFFu;
    groupIndex = 0u;
  }

  /// The collision category bits. Normally you would just set one bit.
  uint32_t categoryBits;

  /// The collision mask bits. This states the categories that this
  /// shape would accept for collision.
  uint32_t maskBits;

  /// Collision groups allow a certain group of objects to never collide
  /// (negative) or always collide (positive). Zero means no collision group.
  /// Non-zero group filtering always wins against the mask bits.
  int16_t groupIndex;
};
struct PhysicsFixtureDef {
  /// The constructor sets the default fixture definition values.
  PhysicsFixtureDef() {
    shape = nullptr;
    friction = 0.2f;
    restitution = 0.0f;
    restitutionThreshold = 1.0f * kLengthUnitsPerMeter;
    density = 0.0f;
    isSensor = false;
  }

  /// The shape, this must be set. The shape will be cloned, so you
  /// can create the shape on the stack.
  const b2Shape* shape;

  /// Use this to store application specific fixture data.
  FixtureUserComponentData userData;

  /// The friction coefficient, usually in the range [0,1].
  float friction;

  /// The restitution (elasticity) usually in the range [0,1].
  float restitution;

  /// Restitution velocity threshold, usually in m/s. Collisions above this
  /// speed have restitution applied (will bounce).
  float restitutionThreshold;

  /// The density, usually in kg/m^2.
  float density;

  /// A sensor shape collects contact information but never generates a
  /// collision response.
  bool isSensor;

  /// Contact filtering data.
  b2Filter filter;
};

class PhysicsFixture;
struct PhysicsFixtureProxy {
  PhysicsAABB aabb;
  PhysicsFixture* fixture;
  int32_t childIndex;
  int32_t proxyId;
};
class PhysicsFixture
{
  /// Get the type of the child shape. You can use this to down cast to the
  /// concrete shape.
  /// @return the shape type.
  b2Shape GetType() const;

  /// Get the child shape. You can modify the child shape, however you should
  /// not change the number of vertices because this will crash some collision
  /// caching mechanisms. Manipulating the shape may lead to non-physical
  /// behavior.
  b2Shape* GetShape();
  const b2Shape* GetShape() const;

  /// Set if this fixture is a sensor.
  void SetSensor(bool sensor);

  /// Is this fixture a sensor (non-solid)?
  /// @return the true if the shape is a sensor.
  bool IsSensor() const;

  /// Set the contact filtering data. This will not update contacts until the
  /// next time step when either parent body is active and awake. This
  /// automatically calls Refilter.
  void SetFilterData(const b2Filter& filter);

  /// Get the contact filtering data.
  const b2Filter& GetFilterData() const;

  /// Call this if you want to establish collision that was previously disabled
  /// by b2ContactFilter::ShouldCollide.
  void Refilter();

  /// Get the parent body of this fixture. This is nullptr if the fixture is not
  /// attached.
  /// @return the parent body.
  b2Body* GetBody();
  const b2Body* GetBody() const;

  /// Get the next fixture in the parent body's fixture list.
  /// @return the next shape.
  b2Fixture* GetNext();
  const b2Fixture* GetNext() const;

  /// Get the user data that was assigned in the fixture definition. Use this to
  /// store your application specific data.
  b2FixtureUserData& GetUserData();
  const b2FixtureUserData& GetUserData() const;

  /// Test a point for containment in this fixture.
  /// @param p a point in world coordinates.
  bool TestPoint(const b2Vec2& p) const;

  /// Cast a ray against this shape.
  /// @param output the ray-cast results.
  /// @param input the ray-cast input parameters.
  /// @param childIndex the child shape index (e.g. edge index)
  bool RayCast(b2RayCastOutput* output, const b2RayCastInput& input,
               int32 childIndex) const;

  /// Get the mass data for this fixture. The mass data is based on the density
  /// and the shape. The rotational inertia is about the shape's origin. This
  /// operation may be expensive.
  void GetMassData(b2MassData* massData) const;

  /// Set the density of this fixture. This will _not_ automatically adjust the
  /// mass of the body. You must call b2Body::ResetMassData to update the body's
  /// mass.
  void SetDensity(float density);

  /// Get the density of this fixture.
  float GetDensity() const;

  /// Get the coefficient of friction.
  float GetFriction() const;

  /// Set the coefficient of friction. This will _not_ change the friction of
  /// existing contacts.
  void SetFriction(float friction);

  /// Get the coefficient of restitution.
  float GetRestitution() const;

  /// Set the coefficient of restitution. This will _not_ change the restitution
  /// of existing contacts.
  void SetRestitution(float restitution);

  /// Get the restitution velocity threshold.
  float GetRestitutionThreshold() const;

  /// Set the restitution threshold. This will _not_ change the restitution
  /// threshold of existing contacts.
  void SetRestitutionThreshold(float threshold);

  /// Get the fixture's AABB. This AABB may be enlarge and/or stale.
  /// If you need a more accurate AABB, compute it using the shape and
  /// the body transform.
  const b2AABB& GetAABB(int32 childIndex) const;

  /// Dump this fixture to the log file.
  void Dump(int32 bodyIndex);

 protected:
  friend class b2Body;
  friend class b2World;
  friend class b2Contact;
  friend class b2ContactManager;

  b2Fixture();

  // We need separation create/destroy functions from the constructor/destructor
  // because the destructor cannot access the allocator (no destructor arguments
  // allowed by C++).
  void Create(b2BlockAllocator* allocator, b2Body* body,
              const b2FixtureDef* def);
  void Destroy(b2BlockAllocator* allocator);

  // These support body activation/deactivation.
  void CreateProxies(b2BroadPhase* broadPhase, const b2Transform& xf);
  void DestroyProxies(b2BroadPhase* broadPhase);

  void Synchronize(b2BroadPhase* broadPhase, const b2Transform& xf1,
                   const b2Transform& xf2);

  float m_density;

  b2Fixture* m_next;
  b2Body* m_body;

  b2Shape* m_shape;

  float m_friction;
  float m_restitution;
  float m_restitutionThreshold;

  b2FixtureProxy* m_proxies;
  int32 m_proxyCount;

  b2Filter m_filter;

  bool m_isSensor;

  b2FixtureUserData m_userData;

};
}  // namespace base_engine::physics