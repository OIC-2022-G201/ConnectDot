#include "MofSpriteAnimationComponent.h"

#include <fstream>

#include "BinaryArchive.h"
#include "SpriteAnimationClipFrozen.h"
#include "VectorFrozen.h"
using namespace base_engine;
Mof::SpriteAnimationCreate MofSpriteAnimationComponent::Convert(
    SpriteAnimationClip data) {
  Mof::SpriteAnimationCreate result{data.name.data(),
                                    data.offset_x,
                                    data.offset_y,
                                    data.width,
                                    data.height,
                                    data.is_loop,
                                    {}};
  for (MofU32 i = 0; i < data.pattern.size(); i++) {
    result.Pattern[i].Wait = data.pattern[i].wait;
    result.Pattern[i].No = data.pattern[i].no;
    result.Pattern[i].Step = data.pattern[i].step;
  }
  return result;
}

MofSpriteAnimationComponent::MofSpriteAnimationComponent(Actor* owner,
                                                         int update_order)
    : Component(owner, update_order) {}

void MofSpriteAnimationComponent::SetSpriteComponent(
    SpriteComponent* component) {
  sprite_ = component;
}

bool MofSpriteAnimationComponent::Load(SpriteComponent* component,
                                       std::span<SpriteAnimationClip> clips) {
  std::vector<Mof::SpriteAnimationCreate> pac(clips.size());
  for (MofU32 i = 0; i < clips.size(); i++) {
    pac[i] = Convert(clips[i]);
    motion_map_[clips[i].name] = i;
  }
  SetSpriteComponent(component);
  sprite_->SetClipRect(motion_.GetSrcRect());
  return motion_.Create(pac.data(), clips.size());
}

bool MofSpriteAnimationComponent::Load(SpriteComponent* component,
                                       const std::string_view file) {
  std::vector<SpriteAnimationClip> sprite_animation_clips;

  {
    std::ifstream stream(file.data(), std::ios::binary);
    frozen::BinaryInputArchive archive(stream);
    archive(sprite_animation_clips);
  }
  return Load(component, sprite_animation_clips);
}

bool MofSpriteAnimationComponent::ChangeMotion(const std::string_view name,
                                               const bool is_same) {
  return motion_.ChangeMotion(motion_map_[name.data()], is_same);
}

bool MofSpriteAnimationComponent::IsMotion(const std::string_view name) const {
  const auto& v = motion_map_.find(name.data());
  if (v == motion_map_.end()) {
    return false;
  }

  return motion_.GetMotionNo() == v->second;
}

bool MofSpriteAnimationComponent::IsEndMotion() {
  return motion_.IsEndMotion();
}

void MofSpriteAnimationComponent::Update() {
  motion_.AddTimer(animation_detail::kFrameTime);
  if (!sprite_) return;
  sprite_->SetClipRect(motion_.GetSrcRect());
}

bool MofSpriteAnimationComponent::Release() { return motion_.Release(); }
