// @PhysicsComponentData.h
// @brief
// @author ICE
// @date 2022/10/13
//
// @details

#pragma once
#include <cstdint>

namespace base_engine::physics {
constexpr double kLengthUnitsPerMeter = 1.0;
constexpr double kAABBExtension = 0.1 * kLengthUnitsPerMeter;

constexpr float kAABBMultiplier = 4.0f;

    constexpr uint8_t kMaxPolygonVertices = 8;

template <class Tag>
struct PointerComponentData {
  PointerComponentData() { pointer = 0; }
  uintptr_t pointer;
};
using BodyUserComponentData = PointerComponentData<struct BodyUser>;
using FixtureUserComponentData = PointerComponentData<struct FjxtureUser>;
using JointUserComponentData = PointerComponentData<struct JointUser>;

}  // namespace base_engine::physics
