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
constexpr std::string_view kEnemyTextureKey = "LivingEntity/Enemy/Enemy2_MotionChip.png"sv;
constexpr std::string_view kEnemyHeadTextureKey = "LivingEntity/Enemy/Enemy3_Head.png"sv;
constexpr std::string_view kEnemyBodyTextureKey = "LivingEntity/Enemy/Enemy3_Body.png"sv;
constexpr std::string_view kEnemyNeckTextureKey = "LivingEntity/Enemy/Enemy3_Neck.png"sv;

//! Beacon
constexpr std::string_view kBeaconTextureKey = "gimmick/Objects/Beacon/Beacon.png";


//! PowerSupplyUnitActor
constexpr std::string_view kPowerSupplyUnitTextureKey =
    "gimmick/Objects/Powersupply/Powersupply_Lv0.png"sv;

//! Signboard
constexpr std::string_view kSignboardTextureKey =
    "Objects/Signboard/Signboard.png"sv;
constexpr std::string_view kSignboardDisplayDemoTextureKey =
    "gimmick/Objects/Signboard/Signboard_on.png"sv;

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

namespace effect {

//! ElectricEffect
constexpr std::string_view kElectricEffectTextureKey =
    "Effect/Electric/ElectroCellMap.png"sv;
}  // namespace effect

}  // namespace texture
