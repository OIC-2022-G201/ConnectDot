// @SpriteAnimationClipFrozen.h
// @brief
// @author ICE
// @date 2022/11/25
//
// @details

#pragma once
#include "ISpriteAnimationComponent.h"
#include "FrozenMacro.h"
#include "VectorFrozen.h"
#include "StringFrozen.h"

namespace base_engine {
template <class Archive>
void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& ar, AnimationPattern& pattern) {
  ar(pattern.wait, pattern.no, pattern.step);
}
template <class Archive>
void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& ar, SpriteAnimationClip& info) {
  ar(info.name, info.offset_x, info.offset_y, info.width, info.height,
     info.is_loop, info.pattern);
}
}  // namespace base_engine
