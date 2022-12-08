// @UiPackage.h
// @brief
// @author ICE
// @date 2022/12/08
// 
// @details

#pragma once
#include <array>

#include "IBaseEngineTexture.h"
using ButtonSprites = std::array<base_engine::TexturePtr,2>;
struct ButtonPackage
{
  ButtonSprites sprites = ButtonSprites{nullptr,nullptr};
};