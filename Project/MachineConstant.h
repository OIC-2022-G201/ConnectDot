// @file MachineConstant.h
// @brief 
// @author ICE
// @date 2022/09/19
// 
// @details

#pragma once
#include "Vector.h"

const base_engine::Vector2 kPylonTransmitterOffset = {64, 64};
const base_engine::Vector2 kBeaconTransmitterOffset = {64, 64};
const base_engine::Vector2 kBeaconReceiverOffset = {64, 64};



constexpr base_engine::FillMode kElectricAreaFillMode = base_engine::FillMode::No;
constexpr uint32_t kElectricAreaColor = MOF_ARGB(255 - 128, 0, 64, 0);