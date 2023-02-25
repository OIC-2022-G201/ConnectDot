// @GimmickCreateHelper.h
// @brief
// @author ICE
// @date 2023/02/24
//
// @details

#pragma once
#include <string>

#include "Actor.h"

namespace base_engine {
struct ISpriteAnimationComponent;
class SpriteComponent;
}  // namespace base_engine

class GimmickCreateHelper {
 public:
  static base_engine::SpriteComponent* SpriteCreateKey(
      base_engine::Actor* owner, const std::string& key, int color_type,
      int draw_order = 100);

  static base_engine::SpriteComponent* SpriteCreatePath(
      base_engine::Actor* owner, const std::string& path, int color_type,
      int draw_order = 100);

  static std::pair<base_engine::SpriteComponent*,
                   base_engine::ISpriteAnimationComponent*>
  AnimationCreateKey(base_engine::Actor* owner, const std::string& key,
                     int color_type,bool play = false, int draw_order = 100);

  static std::pair<base_engine::SpriteComponent*,
                   base_engine::ISpriteAnimationComponent*>
  AnimationCreatePath(base_engine::Actor* owner, const std::string& path,
                      int color_type, bool play = false, int draw_order = 100);
};
