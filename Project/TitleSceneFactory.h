// @TitleSceneFactory.h
// @brief
// @author ICE
// @date 2022/12/08
//
// @details

#pragma once
#include "Game.h"
#include "ISceneFactory.h"
#include "InputManager.h"
#include "Rect.h"
#include "TitleListener.h"

class TitleSceneFactory : public ISceneFactory {
 public:
  explicit TitleSceneFactory(base_engine::Game* game) : game_(game) {}

  void Factory() override;

 private:
  void CreatePopup(InputManager* input, const base_engine::Rect& rect,
                   std::vector<std::tuple<base_engine::Vector2, std::string,
                                          std::function<void()>>>
                       main_pack,
                   TitleComponent::Popup* popup,bool enable = true);
  base_engine::Game* game_ = nullptr;
};
