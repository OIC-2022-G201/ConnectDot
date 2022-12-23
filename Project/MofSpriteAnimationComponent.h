// @file MofSpriteAnimationComponent.h
// @brief
// @author ICE
// @date 2022/09/17
//
// @details

#pragma once
#include <Graphics/SpriteMotionController.h>

#include "Component.h"
#include "ComponentParameter.h"
#include "ISpriteAnimationComponent.h"
#include "SpriteComponent.h"

namespace base_engine {
namespace animation_detail {
constexpr float kFrameTime = 1.0f / 60.0f;
}
class MofSpriteAnimationComponent final : public Component,
                                          public ISpriteAnimationComponent {
  static Mof::SpriteAnimationCreate Convert(SpriteAnimationClip data);

 public:
  MofSpriteAnimationComponent(Actor* owner,
                              int update_order = kAnimationUpdateOrder);

  void SetSpriteComponent(SpriteComponent* component) override;

  bool Load(SpriteComponent* component, std::span<SpriteAnimationClip> clips) override;
  bool Load(SpriteComponent* component, std::string_view file) override;

  bool ChangeMotion(const std::string_view name, const bool is_same) override;

  [[nodiscard]] bool IsMotion(const std::string_view name) const override;
  bool IsEndMotion() override;
  void Play(std::string_view name = "", float speed = 1) override;

  void Stop(bool reset = false) override;

  void Update() override;
  bool Release() override;
private:
  bool pause_ = false;
  bool reset_ = false;
  float speed_ = 1;
  std::string current_name_;
  Mof::CSpriteMotionController motion_;
  std::unordered_map<std::string, MofU32> motion_map_;
  SpriteComponent* sprite_ = nullptr;
};
}  // namespace base_engine