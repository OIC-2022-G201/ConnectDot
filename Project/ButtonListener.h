// @ButtonListener.h
// @brief
// @author ICE
// @date 2022/12/15
//
// @details

#pragma once
#include "ButtonPressEvent.h"
#include "Component.h"
#include "EventHandler.h"

class ButtonListener final : public base_engine::Component,
                             public EventHandler<ButtonPressEvent> {
 public:
  explicit ButtonListener(base_engine::Actor* owner) : Component(owner) {}

  void OnEvent(ButtonPressEvent& press) override
  {
      
  }
};
