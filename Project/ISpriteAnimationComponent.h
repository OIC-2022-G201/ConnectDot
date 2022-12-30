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

#include "YesNo.h"
#include "ISpriteAnimatable.h"
namespace base_engine {

struct AnimationPattern {
  float wait;
  int32_t no;
  int32_t step;
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

struct ISpriteAnimationComponent {
  virtual ~ISpriteAnimationComponent() = default;
  void virtual SetSpriteComponent(ISpriteAnimatable* component) = 0;
  bool virtual Load(ISpriteAnimatable* component,
                    std::span<SpriteAnimationClip>) = 0;
  bool virtual Load(ISpriteAnimatable* component,
                    std::string_view file) = 0;
  
  /**
   * \brief This method will be removed in due time.
   * Use of the Play() method is recommended.
   * \param name change animation name.
   * \param is_same The animation is the same, it will be played from the beginning
   * \return 
   */
  [[deprecated]]
  bool virtual ChangeMotion(const std::string_view name,
                            bool is_same = true) = 0;

  void virtual Play(const std::string_view name = "",const float speed = 1) = 0;
  void virtual Stop(bool reset = false) = 0;
  [[nodiscard]] bool virtual IsMotion(const std::string_view name) const = 0;
  bool virtual IsEndMotion() = 0;
  bool virtual Release() = 0;
};

}  // namespace base_engine