#pragma once

#include <utility>

#include "FrozenHelper.h"
#include "FrozenMacro.h"

namespace frozen {
  template <class Archive, class T, class A>
  void FROZEN_SAVE_FUNCTION_NAME(Archive& ar, std::pair<T, A> const& pair) {
    ar(pair.first, pair.second);
  }

  template <class Archive, class T, class A>
  void FROZEN_LOAD_FUNCTION_NAME(Archive& ar, std::pair<T, A>& pair) {
    ar(pair.first, pair.second);
  }
}  // namespace frozen