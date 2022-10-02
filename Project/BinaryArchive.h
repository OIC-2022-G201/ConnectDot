// @file Binary.h
// @brief
// @author ICE
// @date 2022/10/02
//
// @details

#pragma once
#include "FrozenHelper.h"
#include "frozen.h"

namespace frozen {
class BinaryOutputArchive : public frozen::OutputArchive<BinaryOutputArchive> {
 public:
  explicit BinaryOutputArchive(std::ostream& stream)
      : OutputArchive<BinaryOutputArchive>(this), its_writer_(stream) {}

  inline void SaveBinary(const void* data, std::streamsize size) {
    std::streamsize writtenSize = 0;

    writtenSize =
        its_writer_.rdbuf()->sputn(std::bit_cast<const char*>(data), size);
  }

 private:
  std::ostream& its_writer_;
};
class BinaryInputArchive : public frozen::InputArchive<BinaryInputArchive> {
 public:
  explicit BinaryInputArchive(std::istream& stream)
      : InputArchive<BinaryInputArchive>(this), its_writer_(stream) {}

  inline void LoadBinary(const void* data, std::streamsize size) {
    std::streamsize writtenSize = 0;

    writtenSize = its_writer_.rdbuf()->sgetn(std::bit_cast<char*>(data), size);
  }

 private:
  std::istream& its_writer_;
};
template <class T>
requires std::is_fundamental_v<T>
inline void FROZEN_SAVE_FUNCTION_NAME(BinaryOutputArchive& ar, T const& t) {
  ar.SaveBinary(std::addressof(t), sizeof(t));
}
template <class T>
requires std::is_fundamental_v<T>
inline void FROZEN_SERIALIZE_FUNCTION_NAME(BinaryOutputArchive& ar,
                                           T const& t) {
  ar.SaveBinary(std::addressof(t), sizeof(t));
}

template <class T>
requires std::is_fundamental_v<T>
inline void FROZEN_LOAD_FUNCTION_NAME(BinaryInputArchive& ar, T const& t) {
  ar.LoadBinary(std::addressof(t), sizeof(t));
}
template <class T>
requires std::is_fundamental_v<T>
inline void FROZEN_SERIALIZE_FUNCTION_NAME(BinaryInputArchive& ar, T const& t) {
  ar.LoadBinary(std::addressof(t), sizeof(t));
}

//! Saving binary data
template <class T>
inline void FROZEN_SAVE_FUNCTION_NAME(BinaryOutputArchive& ar,
                                      BinaryData<T> const& bd) {
  ar.SaveBinary(bd.data, static_cast<std::streamsize>(bd.size));
}

//! Loading binary data
template <class T>
inline void FROZEN_LOAD_FUNCTION_NAME(BinaryInputArchive& ar,
                                      BinaryData<T>& bd) {
  ar.LoadBinary(bd.data, static_cast<std::streamsize>(bd.size));
}
}  // namespace frozen