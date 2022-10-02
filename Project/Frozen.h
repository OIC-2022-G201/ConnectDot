// @file frozen.h
// @brief シリアル化基底クラス
// @author ICE
// @date 2022/10/02
// 
// @details

#pragma once

#include <sstream>
#include <utility>

#include "FrozenConcept.h"
namespace frozen {

template <class ArchiveType>
class OutputArchive {
 public:
  explicit OutputArchive(ArchiveType* const derived) : self_(derived) {}

  OutputArchive& operator=(OutputArchive const&) = delete;

  template <NotDuplicationSerializeSave<ArchiveType>... Types>
  inline ArchiveType& operator()(Types&&... args) {
    self_->process(std::forward<Types>(args)...);
    return *self_;
  }
  template <class T>
  inline void process(T&& head) {
    prologue(*self_, head);
    if constexpr (std::is_arithmetic_v<std::remove_reference_t<T>>) {
      FROZEN_SAVE_FUNCTION_NAME(*self_, const_cast<T&>(head));
    } else {
      self_->processImpl(head);
    }
    epilogue(*self_, head);
  }

  template <class T, class... Other>
  inline void process(T&& head, Other&&... tail) {
    self_->process(std::forward<T>(head));
    self_->process(std::forward<Other>(tail)...);
  }
  template <HasSerialize<ArchiveType> T>
  inline ArchiveType& processImpl(const T& t) {
    const_cast<T&>(t).FROZEN_SERIALIZE_FUNCTION_NAME(*self_);
    return *self_;
  }

  template <NonMemberSerialize<ArchiveType> T>
  inline ArchiveType& processImpl(const T& t) {
    FROZEN_SERIALIZE_FUNCTION_NAME(*self_, const_cast<T&>(t));
    return *self_;
  }

  template <HasSave<ArchiveType> T>
  inline ArchiveType& processImpl(const T& t) {
    const_cast<T&>(t).FROZEN_SAVE_FUNCTION_NAME(*self_);
    return *self_;
  }

  template <NonMemberSave<ArchiveType> T>
  inline ArchiveType& processImpl(const T& t) {
    FROZEN_SAVE_FUNCTION_NAME(*self_, const_cast<T&>(t));
    return *self_;
  }

 private:
  ArchiveType* self_ = nullptr;
};
template <class ArchiveType>
class InputArchive {
 public:
  explicit InputArchive(ArchiveType* const derived) : self_(derived) {}

  InputArchive& operator=(InputArchive const&) = delete;

  template <NotDuplicationSerializeLoad<ArchiveType>... Types>
  inline ArchiveType& operator()(Types&&... args) {
    self_->process(std::forward<Types>(args)...);
    return *self_;
  }
  template <class... Types>
  requires std::is_arithmetic_v<Types...>
  inline ArchiveType& operator()(Types&&... args) {
    self_->process(std::forward<Types>(args)...);
    return *self_;
  }
  template <class T>
  inline void process(T&& head) {
    prologue(*self_, head);
    if constexpr (std::is_arithmetic_v<std::remove_reference_t<T>>) {
      FROZEN_LOAD_FUNCTION_NAME(*self_, const_cast<T&>(head));
    } else {
      self_->processImpl(head);
    }
    epilogue(*self_, head);
  }

  template <class T, class... Other>
  inline void process(T&& head, Other&&... tail) {
    self_->process(std::forward<T>(head));
    self_->process(std::forward<Other>(tail)...);
  }
  template <HasSerialize<ArchiveType> T>
  inline ArchiveType& processImpl(const T& t) {
    const_cast<T&>(t).FROZEN_SERIALIZE_FUNCTION_NAME(*self_);
    return *self_;
  }

  template <NonMemberSerialize<ArchiveType> T>
  inline ArchiveType& processImpl(const T& t) {
    FROZEN_SERIALIZE_FUNCTION_NAME(*self_, const_cast<T&>(t));
    return *self_;
  }

  template <HasLoad<ArchiveType> T>
  inline ArchiveType& processImpl(const T& t) {
    const_cast<T&>(t).FROZEN_LOAD_FUNCTION_NAME(*self_);
    return *self_;
  }

  template <NonMemberLoad<ArchiveType> T>
  inline ArchiveType& processImpl(const T& t) {
    FROZEN_LOAD_FUNCTION_NAME(*self_, const_cast<T&>(t));
    return *self_;
  }

 private:
  ArchiveType* self_ = nullptr;
};
template <class Archive, class T>
inline void prologue(Archive& /* archive */, T const& /* data */) {}

template <class Archive, class T>
inline void epilogue(Archive& /* archive */, T const& /* data */) {}
}  // namespace frozen