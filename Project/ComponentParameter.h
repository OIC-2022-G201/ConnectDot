#pragma once
#include <limits>
#undef max

constexpr int kInputUpdateOrder = 50;
constexpr int kPhysicsBodyUpdateOrder = 1000;
constexpr int kCollisionUpdateOrder = 2000;
constexpr int kAnimationUpdateOrder = 3000;
constexpr int kRenderUpdateOrder = 10000;
constexpr int kCameraUpdateOrder = std::numeric_limits<int>::max();