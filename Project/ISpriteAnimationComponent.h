// @file ISpriteAnimationComponent.h
// @brief 
// @author ICE
// @date 2022/09/17
// 
// @details

#pragma once
#include <span>
#include <string_view>
#include <vector>

namespace base_engine {

struct AnimationPattern {
  uint_fast32_t wait;
  uint_fast32_t no;
  uint_fast32_t step;
};
struct SpriteAnimationClip {
  std::string name;
  float offset_x;
  float offset_y;
  float width;
  float height;
  bool is_loop; 
  std::vector<AnimationPattern> pattern;
};

struct ISpriteAnimationComponent
{
    virtual ~ISpriteAnimationComponent() = default;
    void virtual SetSpriteComponent(class SpriteComponent* component) = 0;
    bool virtual Load(SpriteComponent* component, std::span<SpriteAnimationClip>) = 0;
    bool virtual ChangeMotion(const std::string_view name,
                              bool is_same = true) = 0;
    [[nodiscard]] bool virtual IsMotion(const std::string_view name) const = 0;
    bool virtual IsEndMotion() = 0;
};

}  // namespace base_engine