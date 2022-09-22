// @file ElectronicsPower.h
// @brief 電気の範囲など
// @author ICE
// @date 2022/08/20
//
// @details

#pragma once
#include <cstdint>
#include "ShapeRenderComponent.h"
namespace electronics {
namespace electricity {

constexpr uint32_t kPowerRadius = 385;
constexpr uint32_t kEnhancementPowerRadius = kPowerRadius / 2;

constexpr base_engine::FillMode kElectricAreaFillMode =
    base_engine::FillMode::No;

constexpr uint32_t kElectricAreaColor = MOF_ARGB(255 - 128, 0, 64, 0);
constexpr uint32_t kEnhancementElectricAreaColor =
    MOF_ARGB(255 - 128, 255, 0, 255);

}  // namespace electricity

namespace pylon {
constexpr uint32_t kPylonCellHeight = 1;
constexpr uint32_t kPylonCellWidth = 1;
const base_engine::Vector2 kPylonTransmitterOffset = {64, 64};
}  // namespace pylon

namespace beacon {
const base_engine::Vector2 kBeaconTransmitterOffset = {64, 64};
const base_engine::Vector2 kBeaconReceiverOffset = {64, 64};
}  // namespace beacon

namespace psu
{
const base_engine::Vector2 kPowerSupplyUnitTransmitterOffset = {64, 64};
const base_engine::Vector2 kPowerSupplyUnitReceiverOffset = {64, 64};
}

using namespace electricity;
}  // namespace electronics