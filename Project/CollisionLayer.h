// @file CollisionLayer.h
// @brief
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once
#include "CollisionComponent.h"

namespace detail {
constexpr unsigned long long Shift(size_t val) { return 1 << val; }
}  // namespace detail

class CollisionLayer final {
 public:
  // kBeaconTargetFilter = kSenderFilter
  enum Layer {
      kNone = 0,
    kPlayerFilter = 1 << 1,
    kMachineFilter = 1 << 4,
    kReceiverFilter = 1 << 5,
    kSenderFilter = 1 << 6,

    kElectricityAreaFilter = 1 << 8,

  };

 private:
  using U = typename std::underlying_type<Layer>::type;

 public:
  constexpr CollisionLayer(const U val) noexcept
      : val_(static_cast<Layer>(val)) {}

  constexpr operator U() const { return val_; }

 private:
  Layer val_;
};
using BitCollisionLayer = std::bitset<base_engine::kCollisionFilterSize>;
constexpr BitCollisionLayer kPlayerObjectFilter{CollisionLayer::kPlayerFilter};
constexpr BitCollisionLayer kPlayerTargetFilter{CollisionLayer::kPlayerFilter};

constexpr BitCollisionLayer kBeaconObjectFilter{
    CollisionLayer::kReceiverFilter | CollisionLayer::kSenderFilter};

constexpr BitCollisionLayer kBeaconTargetFilter{
    CollisionLayer::kReceiverFilter};

constexpr BitCollisionLayer kPylonObjectFilter{
    CollisionLayer::CollisionLayer::kSenderFilter};

constexpr BitCollisionLayer kPylonTargetFilter{
    CollisionLayer::kReceiverFilter};
/*
using BitCollisionLayer = std::bitset<base_engine::kCollisionFilterSize>;
#define SET_DEFINITION_LAYER(layer_name, val) \
  constexpr size_t layer_name##Number = val;  \
  constexpr CollisionLayer layer_name{detail::Shift(kPlayerFilterNumber)};

#define GET_LAYER(layer_name) layer_name##Number
#define SET_MULTI_LAYER(layer_name, val) \
  constexpr CollisionLayer layer_name{val};

SET_DEFINITION_LAYER(kPlayerFilter, 0)
SET_DEFINITION_LAYER(kMachineFilter, 4)
SET_DEFINITION_LAYER(kReceiverFilter, 6)
SET_DEFINITION_LAYER(kElectricityAreaFilter, 8)

SET_MULTI_LAYER(kBeaconObjectFilter, GET_LAYER(kMachineFilter))
constexpr CollisionLayer kBeaconObjectFilter =
    (kMachineFilter | kReceiverFilter);
*/