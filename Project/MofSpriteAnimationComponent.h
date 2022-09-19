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

  bool ChangeMotion(const std::string_view name, const bool is_same) override;

  [[nodiscard]] bool IsMotion(const std::string_view name) const override;
  bool IsEndMotion() override;

  void Update() override;

 private:
  Mof::CSpriteMotionController motion_;
  std::unordered_map<std::string_view, MofU32> motion_map_;
  SpriteComponent* sprite_ = nullptr;
};
}  // namespace base_engine