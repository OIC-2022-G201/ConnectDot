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
  ar(binary_data(vector.data(), vector.size() * sizeof(T)));
}

template <class Archive, class T, class A>
void FROZEN_LOAD_FUNCTION_NAME(Archive& ar, std::vector<T, A>& vector) {
  SizeType vector_size;
  ar(make_size_tag(vector_size));

  vector.resize(static_cast<std::size_t>(vector_size));
  ar(binary_data(vector.data(),
                 static_cast<std::size_t>(vector_size) * sizeof(T)));
}
}  // namespace frozen