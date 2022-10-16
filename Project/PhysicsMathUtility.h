// @PhysicsMathUtility.h
// @brief
// @author かき氷氷味
// @date 2022/10/13
//
// @details

#pragma once
#include <algorithm>
#include <initializer_list>

#include "Actor.h"
#include "Component.h"
#include "PhysicsVector2.h"
namespace base_engine::physics {
template <class Type>
constexpr Type Min(std::initializer_list<Type> ilist) {
  return *std::min_element(ilist.begin(), ilist.end());
}

template <typename T>
constexpr T PhysicsMax(T a, T b) {
  return a > b ? a : b;
}
constexpr PVec2 PhysicsMax(const PVec2& a, const PVec2& b) noexcept {
  return {PhysicsMax(a.x, b.x), PhysicsMax(a.y, b.y)};
}

template <typename T>
constexpr T PhysicsMin(T a, T b) noexcept {
  return a < b ? a : b;
}
constexpr PVec2 PhysicsMin(const PVec2& a, const PVec2& b) noexcept {
  return {PhysicsMin(a.x, b.x), PhysicsMin(a.y, b.y)};
}

template <typename T>
constexpr T PhysicsClamp(T a, T low,
                         T high) noexcept {
  return std::clamp(a, low, high);
}
constexpr PVec2 PhysicsClamp(const PVec2& a, const PVec2& low,
                             const PVec2& high) noexcept {
  return {PhysicsMax(low, PhysicsMin(a, high))};
}
template <typename T>
constexpr T PhysicsAbs(T a) noexcept {
  return std::abs(a);
}
constexpr PVec2 PhysicsAbs(const PVec2& a) noexcept {
  return {PhysicsAbs(a.x), PhysicsAbs(a.y)};
}



}  // namespace base_engine::physics