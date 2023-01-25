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
#include "SpriteComponent.h"

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
  bool IsFly() const { return is_fly_; }

  void SetOutline(const bool flg) const;
  bool IsOutline() const;
  void SetOnImage(const bool flg) const;

  void SetCanRemote(const bool remote) { can_remote_ = remote; }

 private:
  std::vector<Actor*> targets_;

  base_engine::SpriteComponent* sprite_outline_;
  base_engine::SpriteComponent* sprite_;
  observable::ReactiveProperty<bool> electric_power_ = false;
  bool is_fly_ = false;
  bool can_remote_ = false;
  int sequential_ = -1;
};
