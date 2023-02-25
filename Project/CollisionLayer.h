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
  enum Layer : unsigned long long {
    kNone = 0,
    kFieldFilter = 1 << 1,
    kPlayerFilter = 1 << 2,
    kEnemyFilter = 1 << 3,
    kMachineFilter = 1 << 4,
    kReceiverFilter = 1 << 5,
    kSenderFilter = 1 << 6,
    kSoundFilter = 1 << 7,
    kElectricityAreaFilter = 1 << 8,

    kActionable = 1 << 9,
    kItem = 1 << 10,
    kCanMove = 1 << 11,

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

constexpr BitCollisionLayer kConveyorObjectFilter{CollisionLayer::kFieldFilter};
constexpr BitCollisionLayer kConveyorTargetFilter{CollisionLayer::kCanMove};

constexpr BitCollisionLayer kBoxObjectFilter{CollisionLayer::kCanMove |
                                             CollisionLayer::kFieldFilter};
constexpr BitCollisionLayer kBoxTargetFilter{CollisionLayer::kFieldFilter |
                                             CollisionLayer::kCanMove};

constexpr BitCollisionLayer kChipObjectFilter{CollisionLayer::kItem};
constexpr BitCollisionLayer kChipTargetFilter{CollisionLayer::kPlayerFilter};

constexpr BitCollisionLayer kPlayerObjectFilter{CollisionLayer::kPlayerFilter |
                                                CollisionLayer::kCanMove};
constexpr BitCollisionLayer kPlayerTargetFilter{CollisionLayer::kFieldFilter |
                                                CollisionLayer::kActionable};

constexpr BitCollisionLayer kEnemyObjectFilter{CollisionLayer::kEnemyFilter};
constexpr BitCollisionLayer kEnemyTargetFilter{CollisionLayer::kFieldFilter |
                                               CollisionLayer::kPlayerFilter};
constexpr BitCollisionLayer kEnemyVisionTargetFilter{
    CollisionLayer::kSoundFilter | CollisionLayer::kPlayerFilter};

//! Beacon
constexpr BitCollisionLayer kBeaconObjectFilter{
    CollisionLayer::kReceiverFilter | CollisionLayer::kSenderFilter};

constexpr BitCollisionLayer kBeaconTargetFilter{
    CollisionLayer::kReceiverFilter};

//! PowerSupplyUnitActor
constexpr BitCollisionLayer kPowerSupplyUnitObjectFilter{kBeaconObjectFilter};

constexpr BitCollisionLayer kPowerSupplyUnitTargetFilter{kBeaconTargetFilter};

//! Pylon
constexpr BitCollisionLayer kPylonObjectFilter{CollisionLayer::kSenderFilter};

constexpr BitCollisionLayer kPylonTargetFilter{CollisionLayer::kReceiverFilter};

//! Signboard
constexpr BitCollisionLayer kSignboardObjectFilter{CollisionLayer::kNone};

constexpr BitCollisionLayer kSignboardTargetFilter{CollisionLayer::kNone};

//! Lever
constexpr BitCollisionLayer kLeverObjectFilter{CollisionLayer::kActionable};

constexpr BitCollisionLayer kLeverTargetFilter{CollisionLayer::kNone};

//! Goal
constexpr BitCollisionLayer kGoalTargetFilter{CollisionLayer::kPlayerFilter};

//! SoundEffect
constexpr BitCollisionLayer kSoundObjectFilter{CollisionLayer::kSoundFilter};

constexpr BitCollisionLayer kSoundTargetFilter{CollisionLayer::kNone};

//! MoveFloor
constexpr BitCollisionLayer kMoveFloorObjectFilter{
    CollisionLayer::kFieldFilter};

constexpr BitCollisionLayer kMoveFloorTargetFilter{
    CollisionLayer::kPlayerFilter};
