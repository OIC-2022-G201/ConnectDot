// @ParentTest.h
// @brief
// @author ICE
// @date 2022/12/16
//
// @details

#pragma once
#include "Game.h"

class ParentTest {
  base_engine::Game* game_ = nullptr;

 public:
  ParentTest(base_engine::Game* game) : game_(game) {}
  void Main();
};
