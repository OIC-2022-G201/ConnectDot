// @PhysicsBody2D.h
// @brief
// @author かき氷氷味
// @date 2022/10/13
//
// @details

#pragma once
#include "PhysicsComponentData.h"
#include "PhysicsTransform.h"
#include "PhysicsVector2.h"

namespace base_engine::physics {

class PhysicsFixture;

enum class BodyType { kStaticBody, kKinematicBody, kDynamicBody };
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
    type = BodyType::kStaticBody;
    enabled = true;
    gravityScale = 1.0f;
  }

  BodyType type;

  PVec2 position;

  float angle;

  PVec2 linearVelocity;

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
  [[nodiscard]] const b2Transform& GetTransform() const { return m_xf; }

 private:
  b2Transform m_xf;  // the body origin transform
};
}  // namespace base_engine::physics