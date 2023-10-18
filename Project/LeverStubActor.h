// @file LeverStubActor.h
// @brief
// @author ICE
// @date 2022/11/21
//
// @details

#pragma once
#include "Actor.h"
#include "Component.h"
#include "IMachineActionable.h"
#include "LoadObjectParameter.h"
#include "ReceiverComponent.h"
#include "TransmitterComponent.h"

class LeverStubActor final : public base_engine::Actor {
 public:
  explicit LeverStubActor(base_engine::Game* game);

  void Create(const LoadObject& object);

  void SetTarget(Actor* target) { target_ = target; }
  [[nodiscard]] Actor* GetTarget() const { return target_; }
  void SetElectric(bool flg) { electric_power_ = flg; }
  bool GetElectric() const { return electric_power_; }

 private:
  bool electric_power_ = false;
  Actor* target_ = nullptr;
};
class LeverStubComponent final : public base_engine::Component,
                                 public IMachineActionable {
 public:
  explicit LeverStubComponent(base_engine::Actor* owner,
                              const int update_order = 100)
      : Component(owner, update_order) {}

  void Action(base_engine::Actor*) override;
  bool CanInteractive(base_engine::Actor* actor) override;
};