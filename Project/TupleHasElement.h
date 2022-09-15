// @file TupleHasElement.h
// @brief 
// @author ICE
// @date 2022/09/13
// 
// @details

#pragma once
#include <tuple>
template <class T, class U>
concept TupleAssign = requires(U a) {
  std::get<U>(a);
};

template <typename, typename>
struct tuple_holds;

template <typename... Ts, typename T>
struct tuple_holds<std::tuple<Ts...>, T>
    : std::disjunction<std::is_same<Ts, T>...> {};


template <class... Ts>
inline constexpr bool tuple_holds_v = tuple_holds<Ts...>::value;