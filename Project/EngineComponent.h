#pragma once
#include <cassert>
#include <concepts>

namespace base_engine {

template <class Interface>
class BaseEngineComponent {
 private:
  Interface* interface_ = Interface::Create();

 public:
  ~BaseEngineComponent();

  [[nodiscard]] Interface* get() noexcept;

  void release();
};

template <class Interface>
BaseEngineComponent<Interface>::~BaseEngineComponent() {
  // must be released prior to the destructor executing
  assert(interface_ == nullptr);
}

template <class Interface>
Interface* BaseEngineComponent<Interface>::get() noexcept {
  return interface_;
}

template <class Interface>
void BaseEngineComponent<Interface>::release() {
  delete interface_;
  interface_ = nullptr;
}
}  // namespace base_engine
