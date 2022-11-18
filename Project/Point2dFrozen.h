// @Point2dFrozen.h
// @brief
// @author ICE
// @date 2022/11/18
//
// @details

#pragma once
#include "FrozenMacro.h"
#include "Point2d.h"

namespace frozen {

template <class Archive, class T>
inline void FROZEN_SAVE_FUNCTION_NAME(Archive& ar, Point2d<T> const& vector) {
  ar(vector.x, vector.y);
}

template <class Archive, class T>
void FROZEN_LOAD_FUNCTION_NAME(Archive& ar, Point2d<T>& vector) {
  ar(vector.x, vector.y);
}
}  // namespace frozen