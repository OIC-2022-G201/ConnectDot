// @file GameData.h
// @brief
// @author ICE
// @date 2022/09/27
//
// @details

#pragma once
#include "Game.h"

class GameData {
  base_engine::Game* game_ = nullptr;

 public:
  explicit GameData(base_engine::Game* game) : game_(game) {}

  void Register();
};
