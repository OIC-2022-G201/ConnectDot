// @file LeverStubActor.h
// @brief
// @author ICE
// @date 2022/11/21
//
// @details

#pragma once
#include "Actor.h"
#include "Component.h"
#include "LoadObjectParameter.h"
#include "ReactiveProperty.h"
#include "ReceiverComponent.h"
#include "TransmitterComponent.h"

class IActionable {
 public:
  virtual void Action() = 0;
};


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
  int sequential_ = 15;
  Actor* target_ = nullptr;
};
class LeverStubComponent final : public base_engine::Component,
                                 public IActionable {
 public:
  explicit LeverStubComponent(base_engine::Actor* owner,
                              const int update_order = 100)
      : Component(owner, update_order) {}

  void Action() override {
      base_engine::Actor* target = nullptr;
    if (auto lever = dynamic_cast<LeverStubActor*>(owner_); lever) {
      if (!lever->GetElectric()) return;

      target = lever->GetTarget();
      const auto receiver =
          target->GetComponent<ReceiverComponent>();
      const auto sender =
          owner_->GetComponent<TransmitterComponent>().lock().get();
      sender->AddTarget(receiver);
    }

  }
};