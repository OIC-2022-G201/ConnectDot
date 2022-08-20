// @file StageConstitution.h
// @brief ステージなどの情報
// @author ICE
// @date 2022/08/20
//
// @details

#pragma once
#include <cstdint>
#include <numbers>

#include "Vector.h"
namespace stage {
template <typename _Floating>
constexpr _Floating kStageCellWidth = static_cast<_Floating>(128);

template <typename _Floating>
constexpr _Floating kStageCellHeight = static_cast<_Floating>(128);

template <typename _Floating>
constexpr _Floating kStageCellWidthHalf =
    static_cast<_Floating>(kStageCellWidth<_Floating> * 0.5);

template <typename _Floating>
constexpr _Floating kStageCellHeightHalf =
    static_cast<_Floating>(kStageCellHeight<_Floating> * 0.5);


template <typename _Floating>
constexpr base_engine::Vector2Impl kStageCellSize{
    kStageCellWidth<_Floating>,
                                                  kStageCellHeight<_Floating>};

template <typename _Floating>
constexpr base_engine::Vector2Impl kStageCellSizeHalf{
    kStageCellWidthHalf<_Floating>, kStageCellHeightHalf<_Floating>};

}  // namespace stage