﻿// @file TexturePaths.h
// @brief
// @author ICE
// @date 2022/09/20
//
// @details

#pragma once
#include <array>
#include <ranges>
#include <string_view>

using namespace std::literals::string_view_literals;

namespace texture {

//! Player
constexpr std::string_view kPlayerTextureKey = "Player.png"sv;

//! Enemy
constexpr std::string_view kEnemyTextureKey = "LivingEntity/Enemy/Enemy1.png"sv;

//! Beacon


//! PowerSupplyUnitActor
constexpr std::string_view kPowerSupplyUnitTextureKey =
    "Objects/PowerSupplyUnit/Powersupply_Lv0.png"sv;

//! Signboard
constexpr std::string_view kSignboardTextureKey =
    "Objects/Signboard/Signboard.png"sv;
constexpr std::string_view kSignboardDisplayDemoTextureKey =
    "Objects/Signboard/Display.png"sv;

//! Restart
constexpr std::string_view kRestartButtonTextureKey =
"Restart.png";

//! Resume
constexpr std::string_view kResumeButtonTextureKey =
"Resume.png";


//! ChangeRestart
constexpr  std::string_view kChangeRestartButtonTextureKey =
"Restart2.png";

//! ChangeResume
constexpr  std::string_view kChangeResumeButtonTextureKey =
"Resume2.png";

constexpr  std::string_view kDoorTextureKey =
"Objects/Door/Door1.png"sv;

constexpr  std::string_view kOpenDoorTextureKey =
"Objects/Door/Door2.png"sv;
namespace effect {

//! ElectricEffect
constexpr std::string_view kElectricEffectTextureKey =
    "Effect/Electric/ElectroCellMap.png"sv;
}  // namespace effect

}  // namespace texture
