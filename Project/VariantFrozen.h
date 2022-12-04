// @VariantFrozen.h
// @brief
// @author ICE
// @date 2022/11/18
//
// @details

#pragma once
#include <string>
#include <variant>

#include "FrozenConcept.h"
#include "FrozenHelper.h"
#include "FrozenMacro.h"
namespace frozen {
namespace detail {
template <class Archive>
struct VariantSaveVisitor {
  VariantSaveVisitor(Archive &ar) : ar(ar) {}

  template <class T>
  void operator()(T const &value) const {
    ar(value);
  }

  Archive &ar;
};

template <int N, class Variant, class Archive>
typename std::enable_if<N == std::variant_size_v<Variant>, void>::type
load_variant(Archive & /*ar*/, int /*target*/, Variant & /*variant*/) {
}
template <int N, class Variant, class Archive>
std::enable_if_t <
    N<std::variant_size_v<Variant>, void> load_variant(Archive &ar,
                                                             int target,
                                                             Variant &variant) {
  if (N == target) {
    variant.template emplace<N>();
    ar(std::get<N>(variant));
  } else
    load_variant<N + 1>(ar, target, variant);
}
}  // namespace detail
template <class Archive, typename VariantType1, typename... VariantTypes>
void FROZEN_SAVE_FUNCTION_NAME(
    Archive &ar, std::variant<VariantType1, VariantTypes...> const &variant) {
  std::int32_t index = static_cast<std::int32_t>(variant.index());
  ar(index);
  detail::VariantSaveVisitor<Archive> visitor(ar);
  std::visit(visitor, variant);
}
template <class Archive, typename... VariantTypes>
void FROZEN_LOAD_FUNCTION_NAME(Archive &ar,
                               std::variant<VariantTypes...> &variant) {
  using VariantT = typename std::variant<VariantTypes...>;

  std::int32_t index;
  ar(index);
  detail::load_variant<0>(ar, index, variant);
}
}  // namespace frozen