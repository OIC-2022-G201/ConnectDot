#pragma once
#include "Actor.h"
#include "CollisionComponent.h"
#include "ReactiveProperty.h"
class LeverActor final : public base_engine::Actor {
 public:
  explicit LeverActor(base_engine::Game* game) : Actor(game) {}
  void Start() override;
  void Update() override{};

  
  void SetElectricPower(bool flg) { electric_power_ = flg; }
  [[nodiscard]] auto&& ElectricPowerTrigger() {
    return electric_power_.ToReadOnly();
  }

  observable::ReactiveProperty<bool> GetElectricPower() { return electric_power_; }
  void SetSequential(const int sequential) { sequential_ = sequential; }
  int Sequential() const { return sequential_; }
  void SetTarget(Actor* target) { target_ = target; }
  /*int Switch() const  { return switch_; }*/

 private:
  observable::ReactiveProperty<bool> electric_power_ = false;
  int sequential_ = 15;
  Actor* target_ = nullptr;
  std::bitset<base_engine::kCollisionFilterSize> target_layer_;
  int switch_ = 0;
  class LeverComponent* lever_component_=nullptr;
};
