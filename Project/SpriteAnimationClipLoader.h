// @SpriteAnimationClipLoader.h
// @brief
// @author ICE
// @date 2022/12/07
// 
// @details

#pragma once
#include <fstream>

#include "BinaryArchive.h"
#include "ISpriteAnimationComponent.h"
#include "VectorFrozen.h"
#include "SpriteAnimationClipFrozen.h"

class SpriteAnimationClipLoader {
 public:
  SpriteAnimationClipLoader() = delete;
  static std::vector<base_engine::SpriteAnimationClip> Load(const char* filename) {
    std::vector<base_engine::SpriteAnimationClip> sprite_animation_clips;

    {
      std::ifstream stream(filename, std::ios::binary);
      frozen::BinaryInputArchive archive(stream);
      archive(sprite_animation_clips);
    }
    return sprite_animation_clips;
  }
};
