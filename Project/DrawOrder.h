// @file DrawOrder.h
// @brief 
// @author ICE
// @date 2022/08/20
// 
// @details

#pragma once
namespace draw_order {


    

constexpr int kElectromagneticAreaDrawOrder = 110;
constexpr int kEnhancementElectromagneticAreaDrawOrder = 110;

constexpr int kStageOrder = 120;
constexpr int kPylonDrawOrder = 120;
constexpr int kPowerSupplyUnitDrawOrder = 120;
constexpr int kBeaconDrawOrder = 120;
constexpr int kSignboardDrawOrder = 120;
constexpr int kSignboardDisplayDrawOrder = kSignboardDrawOrder+1;
constexpr int kElectricEffectDrawOrder = 130;

constexpr int kEnemyDrawOrder = 149;
constexpr int kPlayerDrawOrder = 150;
constexpr int kButtonDrawOrder = 151;
constexpr int kChangeButtonDrawOrder = 152;
}  // namespace draw_order