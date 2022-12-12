// @FollowCameraComponent.h
// @brief
// @author ICE
// @date 2022/12/12
//
// @details

#pragma once
#include "Component.h"
class FollowCameraComponent final : public base_engine::Component {
  float interp_velocity_ = 0;
  float min_distance_ = 0;
  float follow_distance_ = 0;
  base_engine::ActorWeakPtr* actor_weak_{};
  base_engine::Vector2 offset_;
  base_engine::Vector2 target_pos_;
  // Use this for initialization
 public:
  FollowCameraComponent(base_engine::Actor* owner);

  void Update() override;
};
