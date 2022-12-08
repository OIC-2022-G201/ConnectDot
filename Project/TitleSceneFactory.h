// @TitleSceneFactory.h
// @brief
// @author ICE
// @date 2022/12/08
//
// @details

#pragma once
#include "Game.h"
#include "ISceneFactory.h"

class TitleSceneFactory : public ISceneFactory {
 public:
  explicit TitleSceneFactory(base_engine::Game* game) : game_(game) {}

  void Factory() override;

private:
  base_engine::Game* game_ = nullptr;
};
