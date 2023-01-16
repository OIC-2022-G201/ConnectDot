// @PauseComponent.h
// @brief
// @author ICE
// @date 2023/01/16
//
// @details

#pragma once
#include "Component.h"

class PauseComponent : base_engine::Component {
 public:
  PauseComponent(base_engine::Actor* owner)
      : Component(owner) {}
  bool IsPause() const { return is_pause_; }
  void Update() override;
private:
  bool is_pause_ = false;
};
