// @file ParameterMap.h
// @brief 
// @author ICE
// @date 2022/09/19
// 
// @details

#pragma once

#include <array>
#include <utility>
#include <algorithm>
#include <string_view>
#include <stdexcept>

template <typename Key, typename Value, std::size_t Size>
struct ParameterMap {
  std::array<std::pair<Key, Value>, Size> data;
  constexpr Value at(const Key &key) const {
    const auto itr =
        std::find_if(begin(data), end(data),
                     [&key](const auto &v) { return v.first == key; });
    if (itr != end(data)) {
      return itr->second;
    } else {
      throw std::range_error("Not Found");
    }
  }
};