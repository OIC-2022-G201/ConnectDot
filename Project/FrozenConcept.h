// @file FrozenConcept.h
// @brief 
// @author ICE
// @date 2022/10/02
// 
// @details

#pragma once
#include <utility>
#include "FrozenMacro.h"
namespace frozen {

template <class T, class ArchiveType>
concept HasSerialize = requires(T& x, ArchiveType type) {
  x.FROZEN_SERIALIZE_FUNCTION_NAME(type);
};
template <class T, class ArchiveType>
concept NonMemberSerialize = requires(T& x, ArchiveType type) {
  FROZEN_SERIALIZE_FUNCTION_NAME(type, x);
};
template <class T, class ArchiveType>
concept HasSave = requires(T& x, ArchiveType type) {
  x.FROZEN_SAVE_FUNCTION_NAME(type);
};
template <class T, class ArchiveType>
concept NonMemberSave = requires(T& x, ArchiveType type) {
  FROZEN_SAVE_FUNCTION_NAME(type, x);
};
template <class T, class ArchiveType>
concept HasLoad = requires(T& x, ArchiveType type) {
  x.FROZEN_LOAD_FUNCTION_NAME(type);
};
template <class T, class ArchiveType>
concept NonMemberLoad = requires(T& x, ArchiveType type) {
  FROZEN_LOAD_FUNCTION_NAME(type, x);
};
template <class T, class InputArchive>
struct count_save_serializers
    : std::integral_constant<int, HasSerialize<T, InputArchive> +
                                      NonMemberSerialize<T, InputArchive> +
                                      HasSave<T, InputArchive> +
                                      NonMemberSave<T, InputArchive>> {};
template <class T, class InputArchive>
struct count_load_serializers
    : std::integral_constant<int, HasSerialize<T, InputArchive> +
                                      NonMemberSerialize<T, InputArchive> +
                                      HasLoad<T, InputArchive> +
                                      NonMemberLoad<T, InputArchive>> {};
template <class T, class ArchiveType>
concept NotDuplicationSerializeSave = requires() {
  typename std::enable_if_t<
      (count_save_serializers<T, ArchiveType>::value == 1) ||
          std::is_arithmetic_v<std::remove_reference_t<T>>,
      bool>;
};
template <class T, class ArchiveType>
concept NotDuplicationSerializeLoad = requires() {
  typename std::enable_if_t<
      (count_load_serializers<T, ArchiveType>::value == 1) ||
          std::is_arithmetic_v<std::remove_reference_t<T>>,
      bool>;
};
}  // namespace frozen