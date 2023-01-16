// @TransitionFadeSystem.h
// @brief
// @author ICE
// @date 2023/01/16
//
// @details

#pragma once
#include "Game.h"
#include "Material.h"

class TransitionFadeSystem {
  base_engine::Game* game_;
  std::shared_ptr<base_engine::Material> material_;

public:
  explicit TransitionFadeSystem(base_engine::Game* game);

  void SceneTransition(const std::string& scene_name);

  void Fade();
};
