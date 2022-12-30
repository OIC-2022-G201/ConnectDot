// @ISpriteAnimatable.h
// @brief
// @author ICE
// @date 2022/12/29
//
// @details

#pragma once
#include <Collision/Rectangle.h>

__interface ISpriteAnimatable
{
	void SetClipRect(const Mof::CRectangle& rect);
  Mof::CRectangle GetClipRect() const = 0;
};
