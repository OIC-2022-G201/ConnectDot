// @VentComponent.h
// @brief
// @author ICE
// @date 2022/11/29
//
// @details

#pragma once
#include "Component.h"
#include "IMachineActionable.h"

class VentComponent final : public base_engine::Component,
                            public IMachineActionable {
 public:
  VentComponent(base_engine::Actor* owner, int update_order)
      : Component(owner, update_order) {}

  void Start() override {}

  void Update() override {}

  void Action() override
  {
      
  }
};
