// @TupleApply.h
// @brief
// @author ICE
// @date 2023/02/08
// 
// @details

#pragma once
#include <type_traits>
#include <tuple>
template <typename F, typename T, size_t... indices>
void ApplyTuple(const F& func, T* tpl, std::index_sequence<indices...>) {
  using swallow = int[];
  (void)swallow{(func(std::get<indices>(*tpl)), 0)...};
};