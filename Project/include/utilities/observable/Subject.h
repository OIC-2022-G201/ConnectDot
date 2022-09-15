// @file Subject.h
// @brief
// @author ICE
// @date 2022/09/13
//
// @details

#pragma once
#include <algorithm>
#include <vector>
#include <memory>

#include "IObservable.h"
#include "IObserver.h"

namespace observable {
    
template <class T>
class ISubject : public IObserver<T>, public IObservable<T> {
 public:
  void virtual Subscribe(IObserverPtr<T> observer) = 0;
  IObserverPtr<T> virtual Subscribe(Action<T> on_next) = 0;

  void virtual OnNext(T& arg) = 0;
  void virtual Dispose(IObserverPtr<T> observer) = 0;
};
template <class T>
class Subject : public ISubject<T> {
 public:
  void Subscribe(IObserverPtr<T> observer) override
  {
    observers_.emplace_back(observer);
  }
  IObserverPtr<T> Subscribe(Action<T> on_next) override
  {
    auto observer = std::make_shared<ObserverSubscribe<T>>(on_next);
    observers_.emplace_back(observer);
    return observer;
  }

  void OnNext(T& arg) override {
    std::ranges::for_each(
        observers_, [&](IObserverPtr<T> observer) { observer->OnNext(arg); });
  }
  void Dispose(IObserverPtr<T> observer) override {
    auto result = std::ranges::remove(observers_, observer);
    observers_.erase(result.begin(), observers_.end());
  }
private:
  std::vector<IObserverPtr<T>> observers_{};
};
}  // namespace observable
