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
  void AddTarget(const base_engine::ActorWeakPtr& target) {
    if (target.expired()) return;
    targets_.emplace_back(target.lock().get());
  }

  [[nodiscard]] const std::vector<Actor*>& GetTarget() const {
    return targets_;
  }
  void Create(const LoadObject& object);

 private:
  std::vector<Actor*> targets_;
  observable::ReactiveProperty<bool> electric_power_ = false;
  int sequential_ = 15;
};
