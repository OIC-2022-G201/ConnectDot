// @StringFrozen.h
// @brief
// @author ICE
// @date 2022/11/17
//
// @details

#pragma once
#include <string>

#include "FrozenConcept.h"
#include "FrozenHelper.h"
#include "FrozenMacro.h"
namespace frozen {

template <class Archive, class CharT, class Traits, class Alloc>
requires NotDuplicationSerializeSave<BinaryData<CharT>, Archive>
void FROZEN_SAVE_FUNCTION_NAME(
    Archive &ar, std::basic_string<CharT, Traits, Alloc> const &str) {
  // Save number of chars + the data
  ar(make_size_tag(static_cast<SizeType>(str.size())));
  ar(binary_data(str.data(), str.size() * sizeof(CharT)));
}
template <class Archive, class CharT, class Traits, class Alloc>
requires NotDuplicationSerializeLoad<BinaryData<CharT>, Archive>
void FROZEN_LOAD_FUNCTION_NAME(Archive &ar,
                               std::basic_string<CharT, Traits, Alloc> &str) {
  SizeType size;
  ar(make_size_tag(size));
  str.resize(static_cast<std::size_t>(size));
  ar(binary_data(const_cast<CharT *>(str.data()),
                 static_cast<std::size_t>(size) * sizeof(CharT)));
}
}  // namespace frozen