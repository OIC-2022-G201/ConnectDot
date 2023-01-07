// @ParallaxCameraFlowLayerComponent.h
// @brief
// @author
// @date 2023/01/07
//
// @details

#pragma once
#include "Component.h"

class ParallaxCameraFlowLayerComponent final : base_engine::Component {
 public:
  explicit ParallaxCameraFlowLayerComponent(base_engine::Actor* owner);

  void Create(const std::weak_ptr<base_engine::Actor>& camera,
              const float follow_per_x, const float follow_per_y);
  void Start() override;
  void Update();

private:
  std::weak_ptr<base_engine::Actor> camera_actor_;
  /**
   * \brief カメラに追従する程度(1: カメラと同じ移動量 0: 移動しない)
   */
  base_engine::Vector2 follow_factor_;

  base_engine::Vector2 previous_camera_pos_;
};

class HorizontalDynamicImageRotationComponent final : base_engine::Component {
 public:
  HorizontalDynamicImageRotationComponent(base_engine::Actor* owner);

  void Create(const std::weak_ptr<base_engine::Actor>& camera);
  void Start() override;

  void Update() override;

private:
  std::weak_ptr<base_engine::Actor> camera_actor_;
  std::weak_ptr<base_engine::Actor> parent_cash_;
  float image_width_;
};