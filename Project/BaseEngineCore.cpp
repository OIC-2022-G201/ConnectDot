#include "BaseEngineCore.h"

#include "IBaseEngineEmpty.h"
#include "IBaseEngineTexture.h"
#include "IBaseEngineRender.h"
#include "IBaseEngineCollider.h"
namespace base_engine {
namespace detail {
template <size_t I, class Tuple>
static void Release(Tuple&& t) {
  std::get<I>(t).release();

  if constexpr (I > 0) {
    Release<I - 1>(t);
  }
}

template <class Tuple>
static void ReleaseAll(Tuple&& t) {
  return Release<std::tuple_size_v<std::remove_reference_t<Tuple>> - 1>(
      std::forward<Tuple>(t));
}
}  // namespace detail
BaseEngineCore::BaseEngineCore() noexcept { engine_ = this; }

BaseEngineCore::~BaseEngineCore() { detail::ReleaseAll(components_); }

bool BaseEngineCore::IsActive() noexcept { return (engine_ != nullptr); }
}  // namespace base_engine
