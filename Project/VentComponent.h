// @VentComponent.h
// @brief
// @author ICE
// @date 2022/11/29
//
// @details

#pragma once
#include "Actor.h"
#include "Component.h"
#include "IMachineActionable.h"
#include "LoadObjectParameter.h"

class VentActor final : public base_engine::Actor {
 public:
  explicit VentActor(base_engine::Game* game);

  void Create(const LoadObject& object);
  void SetElectric(const bool flg) { electric_power_ = flg; }
  [[nodiscard]] bool GetElectric() const { return electric_power_; }

 private:
  bool electric_power_ = false;
};
class VentComponent final : public base_engine::Component,
                            public IMachineActionable {
 public:
  explicit VentComponent(base_engine::Actor* owner) : Component(owner) {}

  void Start() override {}

  void Update() override {}

  void Action(base_engine::Actor* player) override {}
};
