// @file ReactiveProperty.h
// @brief
// @author ICE
// @date 2022/09/13
//
// @details

#pragma once
#include <functional>

#include "Subject.h"

namespace observable {

template <typename ValueType>
class ReactiveProperty {
  using ValueSubject = Subject<ValueType>;

 public:
  template <typename Callable>
  void Subscribe(Callable &&observer) const {
    value_observers_(std::forward<Callable>(observer));
  }

 private:
  ValueType value_;

  mutable ValueSubject value_observers_;
};
}  // namespace observable
