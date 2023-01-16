// @ShaderTest01.h
// @brief
// @author ICE
// @date 2023/01/14
// 
// @details

#pragma once
#include "Game.h"

class ShaderTest01
{
  base_engine::Game* game_;

 public:
  ShaderTest01(base_engine::Game* game) : game_(game){}
  void Main();
};
