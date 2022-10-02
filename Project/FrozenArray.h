// @file FrozenArray.h
// @brief
// @author ICE
// @date 2022/10/02
//
// @details

#pragma once
#include <array>

#include "FrozenHelper.h"
#include "FrozenMacro.h"

namespace frozen {

template <class ArchiveType, class T, size_t N>
requires(!BinaryArchiveConcept<
         ArchiveType,
         T>) inline void FROZEN_SAVE_FUNCTION_NAME(ArchiveType& ar,
                                                   std::array<T, N>& array) {
  for (auto const& i : array) ar(i);
};
template <class ArchiveType, class T, size_t N>
requires(!BinaryArchiveConcept<
         ArchiveType,
         T>) inline void FROZEN_LOAD_FUNCTION_NAME(ArchiveType& ar,
                                                   std::array<T, N>& array) {
  for (auto& i : array) ar(i);
};

template <class ArchiveType, class T, size_t N>
requires BinaryArchiveConcept<ArchiveType, T>
inline void FROZEN_SAVE_FUNCTION_NAME(ArchiveType& ar,
                                      std::array<T, N>& array) {
  ar(binary_data(array.data(), sizeof(array)));
};
template <class ArchiveType, class T, size_t N>
requires BinaryArchiveConcept<ArchiveType, T>
inline void FROZEN_LOAD_FUNCTION_NAME(ArchiveType& ar,
                                      std::array<T, N>& array) {
  ar(binary_data(array.data(), sizeof(array)));
};
}  // namespace frozen