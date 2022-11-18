#pragma once
#include "Actor.h"
#include "GridSnapComponent.h"
#include "ReactiveProperty.h"
#include "SpriteComponent.h"
#include "LeverActor.h"
class MoveFloorActor final : public base_engine::Actor {
 public:
  explicit MoveFloorActor(base_engine::Game* game);
  


  void Start() override;
  void Update() override;
  void SetElectricPower(bool flg) { electric_power_ = flg; }
  [[nodiscard]] auto&& ElectricPowerTrigger() {
    return electric_power_.ToReadOnly();
  }
 
  int Sequential() const { return sequential_; }
  void SetTarget(Actor* target) { target_ = target; }
  void SetSwitch();

 private:
  observable::ReactiveProperty<bool> electric_power_ = false;
  base_engine::SpriteComponent* sender_ = nullptr;
 std::vector<base_engine::Rect> mf_shape_;
  int sequential_ = 15;
  Actor* target_ = nullptr;
   int switch_ = 0;
  int mx_=4, my_=5;
  
  grid::GridSnapComponent* grid_;

};
