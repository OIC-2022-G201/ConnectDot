// @TestSceneFactory.h
// @brief
// @author ICE
// @date 2023/01/15
// 
// @details

#pragma once
#include "Game.h"
#include "ISceneFactory.h"
constexpr std::string_view kTest = "Test";

class TestSceneFactory : public ISceneFactory {
 public:
  explicit TestSceneFactory(base_engine::Game* game) : game_(game) {}

  void Factory() override;

 private:
  base_engine::Game* game_ = nullptr;
};
