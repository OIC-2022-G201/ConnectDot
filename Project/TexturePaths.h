// @file TexturePaths.h
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

//! zero
constexpr std::string_view kZeroTextureKey =
"number/zero.png"sv;

//! one
constexpr std::string_view kOneTextureKey =
"number/one.png"sv;

//! two
constexpr std::string_view kTwoTextureKey =
"number/two.png"sv;

//! three
constexpr std::string_view kThreeTextureKey =
"number/three.png"sv;

//! four
constexpr std::string_view kFourTextureKey =
"number/four.png"sv;

//! five
constexpr std::string_view kFiveTextureKey =
"number/five.png"sv;

//!six
constexpr std::string_view kSixTextureKey =
"number/six.png"sv;

//!seven
constexpr std::string_view kSevenTextureKey =
"number/seven.png"sv;

//!eight
constexpr std::string_view kEightTextureKey =
"number/eight.png"sv;

//!nine
constexpr std::string_view kNineTextureKey =
"number/nine.png"sv;

namespace effect {

//! ElectricEffect
constexpr std::string_view kElectricEffectTextureKey =
    "Effect/Electric/ElectroCellMap.png"sv;

}  // namespace effect

}  // namespace texture
