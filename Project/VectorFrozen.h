// @VectorFrozen.h
// @brief
// @author ICE
// @date 2022/11/17
//
// @details

#pragma once
#include <vector>

#include "FrozenHelper.h"
#include "FrozenMacro.h"

namespace frozen {
template <class Archive, class T, class A>
void FROZEN_SAVE_FUNCTION_NAME(Archive& ar, std::vector<T, A> const& vector) {
  ar(make_size_tag(
      static_cast<SizeType>(vector.size())));  // number of elements
  for (auto&& v : vector) ar(v);
}

template <class Archive, class T, class A>
void FROZEN_LOAD_FUNCTION_NAME(Archive& ar, std::vector<T, A>& vector) {
  SizeType size;
  ar(make_size_tag(size));

  vector.resize(static_cast<std::size_t>(size));
  for (auto&& v : vector) ar(v);
}
}  // namespace frozen