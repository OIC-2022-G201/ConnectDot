// @file ResourcePack.h
// @brief
// @author ICE
// @date 2022/09/24
//
// @details

#pragma once
#include <tuple>

#include "Resource.h"
#include "TupleHasElement.h"
namespace asset_system {
template <class... _Types>
class ResourcePack {
  using Elements = std::tuple<ResourcePtr<_Types>...>;

 public:
  template <class Type,
            std::enable_if_t<tuple_holds_v<Elements, ResourcePtr<Type>>, bool> =
                false>
  void Register(ResourcePtr<Type> resource) {
    std::get<ResourcePtr<Type>>(elements_) = resource;
  }

  template <class T, std::enable_if_t<tuple_holds_v<Elements, ResourcePtr<T>>,
                                      bool> = false>
  ResourcePtr<T>& Get() {
    return std::get<ResourcePtr<T>>(elements_);
  }

  template <class T, std::enable_if_t<tuple_holds_v<Elements, ResourcePtr<T>>,
                                      bool> = false>
  [[nodiscard]] const ResourcePtr<T>& Get() const {
    return const_cast<ResourcePack*>(this)->Get<T>();
  }

  using Ptr = std::shared_ptr<ResourcePack<_Types...>>;

 private:
  std::tuple<ResourcePtr<_Types>...> elements_;
};

template <typename... _Types>
using ResourcePackPtr = typename ResourcePack<_Types...>::Ptr;
}  // namespace asset_system
