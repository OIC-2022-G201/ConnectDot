// @file ReactiveProperty.h
// @brief
// @author ICE
// @date 2022/09/13
//
// @details

#pragma once
#include <functional>
#include <optional>

#include "Subject.h"

namespace observable {
template <typename ValueType>
struct IReadOnlyReactiveProperty : public IObservable<ValueType> {
  void Subscribe(IObserverPtr<ValueType> observer) override = 0;
  IObserverPtr<ValueType> Subscribe(Action<ValueType> observer) override = 0;
  void Dispose(IObserverPtr<ValueType> observer) override = 0;
  virtual explicit operator ValueType const &() const noexcept = 0;
};

template <typename ValueType>
class ReactiveProperty : public IReadOnlyReactiveProperty<ValueType>,public IObserver<ValueType> {
 public:
  template <typename U>
  explicit(!std::is_same_v<ValueType, U>) ReactiveProperty(const U& v)
      : value_(v) {}
  void Subscribe(IObserverPtr<ValueType> observer) override {
    observers_.emplace_back(observer);
  }
  IObserverPtr<ValueType> Subscribe(Action<ValueType> on_next) override {
    auto observer = std::make_shared<ObserverSubscribe<ValueType>>(on_next);
    observers_.emplace_back(observer);
    return observer;
  }
  void Dispose(IObserverPtr<ValueType> observer) override {
    auto result = std::ranges::remove(observers_, observer);
    observers_.erase(result.begin(), observers_.end());
  }

  ReactiveProperty<ValueType>& operator=(const ValueType& v) {
    value_ = v;
    this->OnNext(value_);
    return *this;
  }

  void OnNext(ValueType& arg) override {
    std::ranges::for_each(observers_, [&](IObserverPtr<ValueType> observer) {
      observer->OnNext(arg);
    });
  }

  IReadOnlyReactiveProperty<ValueType>& ToReadOnly() {
    return *this;
  }
  explicit operator ValueType const &() const noexcept {
    return value_;
  }

 private:
  ValueType value_{};
  std::vector<IObserverPtr<ValueType>> observers_{};
};
}  // namespace observable
