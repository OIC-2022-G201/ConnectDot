// @file IObserver.h
// @brief
// @author ICE
// @date 2022/09/13
//
// @details

#pragma once
#include <functional>

namespace observable {

template <class Ts>
class IObserver {
 public:
  virtual ~IObserver() = default;
  void virtual OnNext(Ts& arg) = 0;
};


template <class T>
using Action = std::function<void(T)>;

template <class T>
class ObserverSubscribe final : public IObserver<T> {
  Action<T> on_next_;

 public:
  explicit ObserverSubscribe(Action<T> on_next)
      : on_next_(std::move(on_next)){};
  void OnNext(T& arg) override { on_next_(arg); }
};

template <class T>
using IObserverPtr = std::shared_ptr<IObserver<T>>;
}  // namespace observable
