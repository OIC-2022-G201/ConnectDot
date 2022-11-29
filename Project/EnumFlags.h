// @EnumFlags.h
// @brief
// @author ICE
// @date 2022/11/25
//
// @details

#pragma once
#include <type_traits>

#define ENUM_CLASS_FLAGS(enum_name) \
  constexpr bool ENUM_CLASS_IS_FLAG(enum_name) { return true; }

namespace ee {
template <typename T>
concept UnsignedEnum =
    std::is_enum_v<T> && std::is_unsigned_v<std::underlying_type_t<T>>;

namespace details {
  template <UnsignedEnum T>
  constexpr bool is_flag() {
    return ENUM_CLASS_IS_FLAG(T{});
  }
}  // namespace details

template <typename T>
concept Flag = UnsignedEnum<T> && details::is_flag<T>();

template <Flag T>
constexpr auto underlying_value(T enum_value) {
  return static_cast<std::underlying_type_t<T>>(enum_value);
}

template <Flag T>
constexpr auto operator~(T value) {
  return static_cast<std::underlying_type_t<T>>(~underlying_value(value));
}

template <Flag T>
constexpr auto operator|(T lhs, T rhs) {
  return static_cast<std::underlying_type_t<T>>(underlying_value(lhs) |
                                                underlying_value(rhs));
}
template <Flag T>
constexpr auto operator|(std::underlying_type_t<T> lhs, T rhs) {
  return static_cast<std::underlying_type_t<T>>(lhs | underlying_value(rhs));
}
template <Flag T>
constexpr auto operator|(T lhs, std::underlying_type_t<T> rhs) {
  return static_cast<std::underlying_type_t<T>>(underlying_value(lhs) | rhs);
}
template <Flag T>
constexpr auto operator|=(std::underlying_type_t<T> &value, T const flag) {
  return value = value | flag;
}

template <Flag T>
constexpr auto operator&(T lhs, T rhs) {
  return static_cast<std::underlying_type_t<T>>(underlying_value(lhs) &
                                                underlying_value(rhs));
}
template <Flag T>
constexpr auto operator&(std::underlying_type_t<T> lhs, T rhs) {
  return static_cast<std::underlying_type_t<T>>(lhs & underlying_value(rhs));
}
template <Flag T>
constexpr auto operator&(T lhs, std::underlying_type_t<T> rhs) {
  return static_cast<std::underlying_type_t<T>>(underlying_value(lhs) & rhs);
}
template <Flag T>
constexpr auto operator&=(std::underlying_type_t<T> &value, T const flag) {
  return value = value & flag;
}

template <Flag T>
constexpr auto operator^(T lhs, T rhs) {
  return static_cast<std::underlying_type_t<T>>(underlying_value(lhs) ^
                                                underlying_value(rhs));
}
template <Flag T>
constexpr auto operator^(std::underlying_type_t<T> lhs, T rhs) {
  return static_cast<std::underlying_type_t<T>>(lhs ^ underlying_value(rhs));
}
template <Flag T>
constexpr auto operator^(T lhs, std::underlying_type_t<T> rhs) {
  return static_cast<std::underlying_type_t<T>>(underlying_value(lhs) ^ rhs);
}
template <Flag T>
constexpr auto operator^=(std::underlying_type_t<T> &value, T const flag) {
  return value = value ^ flag;
}

template <auto Mask, class T>
constexpr bool has(T value) {
  return (static_cast<__underlying_type(T)>(value) &
          static_cast<__underlying_type(T)>(Mask)) != 0;
}
}  // namespace ee