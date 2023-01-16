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
#include "Material.h"

namespace base_engine {
class CameraComponent final : public Component {
  static std::weak_ptr<CameraComponent> main_camera_weak_;

 public:
  CameraComponent(Actor* owner, int update_order = kCameraUpdateOrder);

  void Update() override;

  void SetMainCamera() const;
  void SetMaterial(const std::shared_ptr<Material>& material) const;
  static std::weak_ptr<CameraComponent> GetMainCamera();
};
}  // namespace base_engine
