// @file Player.h
// @brief
// @author ICE
// @date 2022/08/07
//
// @details

#pragma once
namespace player {
//#define PLAYER_DEBUG
#ifdef PLAYER_DEBUG
#define PLAYER_DATA const
#else 
#define PLAYER_DATA constexpr
#endif

PLAYER_DATA float kSpeed = 6;
PLAYER_DATA float kSneakSpeed = 3;

}
