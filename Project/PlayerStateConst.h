// @PlayerStateConst.h
// @brief
// @author ICE
// @date 2022/11/26
// 
// @details

#pragma once
#include <numbers>

namespace player::jump {
using std::numbers::pi_v;

constexpr uint16_t kMaxFrame = 60;

// 300 Sin[(Pi x)/60] 第二次微分
template <std::floating_point Floating>
constexpr Floating kJumpCoefficient = static_cast<Floating>(
    static_cast<Floating>(-1.0 / 12.0) * pi_v<Floating> * pi_v<Floating>);

template <std::floating_point Floating>
constexpr Floating kTimeCoefficient = static_cast<Floating>(pi_v<Floating> /
                                                            kMaxFrame);
}  // namespace player::detail