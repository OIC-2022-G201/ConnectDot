// @file PowerSupplyUnitActor.h
// @brief
// @author ICE
// @date 2022/09/22
//
// @details

#pragma once
#include "Actor.h"
#include "Game.h"
#include "ReactiveProperty.h"

struct LoadObject;

class PowerSupplyUnitActor final : public base_engine::Actor {
 public:
  explicit PowerSupplyUnitActor(base_engine::Game* game) : Actor(game) {}

  void Start() override;

  void SetElectricPower(bool flg) { electric_power_ = flg; }
  [[nodiscard]] auto&& ElectricPowerTrigger() {
    return electric_power_.ToReadOnly();
  }
  void SetSequential(const int sequential) { sequential_ = sequential; }
  int Sequential() const { return sequential_; }
  void SetTarget(const base_engine::ActorWeakPtr& target) { target_ = target; }
  Actor* GetTarget() const
  {
    if (target_.expired()) return nullptr;
      return target_.lock().get();
  }
  void Create(const LoadObject& object);

 private:
  observable::ReactiveProperty<bool> electric_power_ = false;
  int sequential_ = 15;
  base_engine::ActorWeakPtr target_;
};
