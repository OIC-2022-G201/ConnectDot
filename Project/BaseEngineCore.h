#pragma once
#include <tuple>

#include "EngineComponent.h"

namespace base_engine {
class IBaseEngineEmpty;
class IBaseEngineTexture;
class IBaseEngineRender;
class IBaseEngineCollider;

class BaseEngineCore {
 private:
  inline static BaseEngineCore* engine_ = nullptr;

  std::tuple<BaseEngineComponent<IBaseEngineEmpty>,
             BaseEngineComponent<IBaseEngineTexture>,
             BaseEngineComponent<IBaseEngineRender>,
             BaseEngineComponent<IBaseEngineCollider>>
      components_;

 public:
  BaseEngineCore() noexcept;

  ~BaseEngineCore();

  [[nodiscard]] static bool IsActive() noexcept;

  template <class Interface>
  [[nodiscard]] static auto* Get() noexcept {
    return std::get<BaseEngineComponent<Interface>>(engine_->components_).get();
  }
};

#define BASE_ENGINE(COMPONENT) \
  base_engine::BaseEngineCore::Get<base_engine::IBaseEngine##COMPONENT>()
}  // namespace base_engine
