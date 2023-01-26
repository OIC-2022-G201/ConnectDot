// @InvaderSceneFactory.h
// @brief
// @author ICE
// @date 2023/01/26
//
// @details

#pragma once
#include <string_view>

#include "Game.h"
#include "ISceneFactory.h"

constexpr std::string_view kInvader = "Invader";
class InvaderSceneFactory : public ISceneFactory {
 public:
  void Factory() override;

  explicit InvaderSceneFactory(base_engine::Game* game) : game_(game) {}

 private:
  base_engine::Game* game_ = nullptr;
};
