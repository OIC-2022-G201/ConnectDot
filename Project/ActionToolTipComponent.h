// @ActionToolTipComponent.h
// @brief
// @author
// @date 2023/01/09
//
// @details

#pragma once
#include "Component.h"
#include "IMachineActionable.h"
#include "SpriteComponent.h"

class ActionToolTipComponent : public base_engine::Component {
 public:
  ActionToolTipComponent(base_engine::Actor* owner, int update_order = 100)
      : Component(owner, update_order) {}

  static std::weak_ptr<ActionToolTipComponent> Create(
      base_engine::Actor* owner,
      const std::weak_ptr<IMachineActionable>& machine);

  void Show();
  void Hide();
  void Update() override;

private:
  base_engine::SpriteComponent* sprite_ = nullptr;
  std::weak_ptr<base_engine::Actor> panel_;

  bool play_animation_ = false;
  bool open_ = false;

  bool is_show_ = false;
  float count_frame_ = 0;
};
