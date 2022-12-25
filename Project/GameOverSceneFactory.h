// @GameOverSceneFactory.h
// @brief
// @author ICE
// @date 2022/12/25
// 
// @details

#pragma once

#include "Game.h"
#include "ISceneFactory.h"
constexpr std::string_view kGameOver = "GameOver";

class GameOverSceneFactory : public ISceneFactory {
 public:
  explicit GameOverSceneFactory(base_engine::Game* game) : game_(game) {}

  void Factory() override;

private:
  base_engine::Game* game_ = nullptr;
};
