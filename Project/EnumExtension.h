// @EnumExtension.h
// @brief
// @author かき氷氷味
// @date 2022/10/16
// 
// @details

#pragma once
#include <string_view>
#include <type_traits>

namespace ee {
constexpr std::string_view pretty_name(std::string_view name) noexcept {
  for (std::size_t i = name.size(); i > 0; --i) {
    if (!((name[i - 1] >= '0' && name[i - 1] <= '9') ||
          (name[i - 1] >= 'a' && name[i - 1] <= 'z') ||
          (name[i - 1] >= 'A' && name[i - 1] <= 'Z') || (name[i - 1] == '_'))) {
      name.remove_prefix(i);
      break;
    }
  }

  if (!name.empty() && ((name[0] >= 'a' && name[0] <= 'z') ||
                        (name[0] >= 'A' && name[0] <= 'Z') ||

                        (name[0] == '_'))) {
    return name;
  }

  return {};  // Invalid name.
}
template <typename E, E V>
constexpr bool IsValid() noexcept {
  constexpr auto name = pretty_name({__FUNCSIG__, sizeof(__FUNCSIG__) - 17});

  int i = name.size() - 1;

  if (i < 0) return false;

  for (; i >= 0; --i) {
    if (name[i] == ' ') {
      break;
    }
  }

  char c = name[i + 1];
  if (c >= '0' && c <= '9') {
    return false;
  }
  return true;
}
template <typename E>
constexpr int CountValid() {
  return 0;
}

template <typename E, E A, E... B>
constexpr int CountValid() {
  constexpr bool is_valid = IsValid<E, A>();
  return CountValid<E, B...>() + static_cast<int>(is_valid);
}

template <typename E, int... I>
constexpr int InternalElementCount(std::integer_sequence<int, I...> unused) {
  return CountValid<E, static_cast<E>(I)...>();
}

template <class T>
concept Enum = std::is_enum_v<T>;

template <Enum E>
consteval int ElementCount() {
  return InternalElementCount<E>(std::make_integer_sequence<int, 40>());
}
}  // namespace ee