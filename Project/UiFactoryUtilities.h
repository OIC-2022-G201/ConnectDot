// @UiFactoryUtilities.h
// @brief
// @author ICE
// @date 2022/12/25
//
// @details

#pragma once
#include <string_view>

#include "Button.h"
#include "ButtonSelecter.h"
#include "Game.h"
#include "ImageComponent.h"
#include "UiFrozen.h"

class UiFactoryUtilities {
 public:
  static std::pair<base_engine::Actor*, base_engine::ImageComponent*>
  ImageCreate(base_engine::Game* game, std::string_view key);

  static std::pair<Button*, ButtonSelecter*> ButtonCreate(
      base_engine::Game* game, ButtonSelecter* selector,
      const ButtonFrozenPack& button_data);
};
