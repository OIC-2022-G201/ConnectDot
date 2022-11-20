// @file CollisionLayer.h
// @brief
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once

namespace detail {
constexpr unsigned long long Shift(size_t val) { return 1ull << val; }
}  // namespace detail

class CollisionLayer final {
 public:
  // kBeaconTargetFilter = kSenderFilter
  enum Layer {
    kNone = 0,
    kFieldFilter = 1 << 1,
    kPlayerFilter = 1 << 2,
    kMachineFilter = 1 << 4,
    kReceiverFilter = 1 << 5,
    kSenderFilter = 1 << 6,

    kElectricityAreaFilter = 1 << 8,

    kActionable = 1 << 16,

  };

 private:
  using U = std::underlying_type_t<Layer>;

 public:
  constexpr CollisionLayer(const U val) noexcept
      : val_(static_cast<Layer>(val)) {}

  explicit constexpr operator U() const { return val_; }

 private:
  Layer val_;
};
using BitCollisionLayer = std::bitset<base_engine::kCollisionFilterSize>;

constexpr BitCollisionLayer kActionableMask{CollisionLayer::kActionable};

constexpr BitCollisionLayer kFieldObjectFilter{CollisionLayer::kFieldFilter};
constexpr BitCollisionLayer kFieldTargetFilter{CollisionLayer::kPlayerFilter};

constexpr BitCollisionLayer kPlayerObjectFilter{CollisionLayer::kPlayerFilter};
constexpr BitCollisionLayer kPlayerTargetFilter{CollisionLayer::kFieldFilter |
                                                CollisionLayer::kActionable};

//! Beacon
constexpr BitCollisionLayer kBeaconObjectFilter{
    CollisionLayer::kReceiverFilter | CollisionLayer::kSenderFilter};

constexpr BitCollisionLayer kBeaconTargetFilter{
    CollisionLayer::kReceiverFilter};

//! PowerSupplyUnitActor
constexpr BitCollisionLayer kPowerSupplyUnitObjectFilter{kBeaconObjectFilter};

constexpr BitCollisionLayer kPowerSupplyUnitTargetFilter{CollisionLayer::kNone};

//! Pylon
constexpr BitCollisionLayer kPylonObjectFilter{CollisionLayer::kSenderFilter};

constexpr BitCollisionLayer kPylonTargetFilter{CollisionLayer::kReceiverFilter};

//! Signboard
constexpr BitCollisionLayer kSignboardObjectFilter{CollisionLayer::kNone};

constexpr BitCollisionLayer kSignboardTargetFilter{CollisionLayer::kNone};

//! Lever
constexpr BitCollisionLayer kLeverObjectFilter{CollisionLayer::kActionable};

constexpr BitCollisionLayer kLeverTargetFilter{CollisionLayer::kNone};