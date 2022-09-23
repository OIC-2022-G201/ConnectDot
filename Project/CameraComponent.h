// @file CameraComponent.h
// @brief
// @author ICE
// @date 2022/09/23
//
// @details

#pragma once
#include "Actor.h"
#include "BaseEngineCore.h"
#include "Component.h"
#include "ComponentParameter.h"
#include "IBaseEngineRender.h"

namespace base_engine {
class CameraComponent : public Component {
 public:
  CameraComponent(Actor* owner, int update_order = kCameraUpdateOrder)
        : Component(owner, update_order)
    {
    }

  void Update() override
  {
    BASE_ENGINE(Render)->SetCameraPosition(owner_->GetPosition());
  }
};
}  // namespace base_engine
