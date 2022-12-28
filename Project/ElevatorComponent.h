// @ElevatorComponent.h
// @brief
// @author ICE
// @date 2022/12/28
//
// @details

#pragma once
#include "Actor.h"
#include "Component.h"
#include "GridPosition.h"
#include "IMachineActionable.h"
#include "LoadObjectParameter.h"

class ElevatorActor final : public base_engine::Actor {
 public:
  explicit ElevatorActor(base_engine::Game* game);
  void Create(const LoadObject& object);
};

class ElevatorComponent final : public base_engine::Component,
                                public IMachineActionable {
 public:
  explicit ElevatorComponent(base_engine::Actor* owner,
                             const int update_order = 100);

  void Start() override;

  void SetElectric(const bool flg) { electric_power_ = flg; }
  [[nodiscard]] bool GetElectric() const { return electric_power_; }
  void Action(base_engine::Actor* actor) override;
  void AddFloor(const GridPosition& pos) { positions_.emplace_back(pos); }

 private:
  bool electric_power_ = false;

  bool busy_ = false;

  std::vector<GridPosition> positions_;

  int current_floor_ = 1;
};
