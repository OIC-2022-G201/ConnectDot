// @PauseComponent.h
// @brief
// @author ICE
// @date 2023/01/16
//
// @details

#pragma once
#include "AudioStreamComponent.h"
#include "Component.h"

class PauseComponent : base_engine::Component {
 public:
  PauseComponent(base_engine::Actor* owner)
      : Component(owner) {}

  void Start() override;
  void Update() override;
private:
  base_engine::AudioStreamComponent* open_se_ = nullptr;
};
