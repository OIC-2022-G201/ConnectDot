// @VariantUtilities.h
// @brief
// @author ICE
// @date 2022/11/18
// 
// @details

#pragma once
#include <stdexcept>
#include <string>
#include <variant>

template <class Variant, size_t I = 0>
Variant VariantFromIndex(const size_t index) {
  if constexpr (I >= std::variant_size_v<Variant>)
    throw std::runtime_error{"Variant index " + std::to_string(I + index) +
                             " Over"};
  else
    return index == 0 ? Variant{std::in_place_index<I>}
                      : VariantFromIndex<Variant, I + 1>(index - 1);
}
