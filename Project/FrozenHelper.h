// @file FrozenHelper.h
// @brief 
// @author ICE
// @date 2022/10/02
// 
// @details

#pragma once
#include <type_traits>
namespace frozen {
template <class T>
struct BinaryData {
  using TPtr = std::conditional_t<
      std::is_const_v<std::remove_pointer_t<std::remove_reference_t<T>>>,
      const void*, void*>;

  BinaryData(T&& d, uint64_t s) : data(std::forward<T>(d)), size(s) {}

  TPtr data;
  uint64_t size;
};

template <class T>
inline BinaryData<T> binary_data(T&& data, size_t size) {
  return {std::forward<T>(data), size};
}

}  // namespace frozen
template <class ArchiveType, class T>
concept BinaryArchiveConcept = requires(ArchiveType& ar,
                                        frozen::BinaryData<T> binary) {
  ar(binary);
};
