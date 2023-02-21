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
#include "StageConstitution.h"

class VentActor final : public base_engine::Actor {
 public:
  explicit VentActor(base_engine::Game* game);

  void Create(const LoadObject& object);
};
class VentComponent final : public base_engine::Component,
                            public IMachineActionable {
 public:
  explicit VentComponent(base_engine::Actor* owner);

  void Start() override;

  void Update() override;

  void Action(base_engine::Actor* player) override;

  bool CanInteractive(base_engine::Actor* actor);

  [[nodiscard]] base_engine::Vector2 GetGoInPosition() const {
    auto pos = owner_->GetPosition();
    pos.x += stage::kStageCellSizeHalf<float>.x;
    return pos;
  }

  void SetElectric(const bool flg) { electric_power_ = flg; }
  [[nodiscard]] bool GetElectric() const { return electric_power_; }

  void SetTransitionTarget(std::string right,std::string left)
  {
    right_ = right;
    left_ = left;
  }
  std::weak_ptr<base_engine::Actor> GetRight() const;
  std::weak_ptr<base_engine::Actor> GetLeft() const;

 private:
  std::string right_;
  std::string left_;
  int group_mask_;
  bool electric_power_ = false;
};
