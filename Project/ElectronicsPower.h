// @file ElectronicsPower.h
// @brief 電気の範囲など
// @author ICE
// @date 2022/08/20
// 
// @details

#pragma once
#include <cstdint>
namespace electronics {
namespace electricity {
constexpr uint32_t kPowerRadius = 400;
}

namespace pylon
{
constexpr uint32_t kPylonCellHeight = 1;
constexpr uint32_t kPylonCellWidth = 1;
}
    using namespace electricity;
}