// @TransitionFadeComponent.h
// @brief
// @author ICE
// @date 2023/01/15
// 
// @details

#pragma once
#include "Component.h"
#include "ImageComponent.h"
#include "Material.h"

class TransitionFadeComponent : base_engine::Component
{
  std::shared_ptr<base_engine::Material> material_;
  float progress_ = 0;
 public:
	TransitionFadeComponent(base_engine::Actor* owner);
  void Bind(base_engine::ImageComponent* image) const;
  void Start() override;
  void Update() override;
};
