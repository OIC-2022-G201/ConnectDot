#include "MofSpriteAnimationComponent.h"

Mof::SpriteAnimationCreate base_engine::MofSpriteAnimationComponent::Convert(
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

base_engine::MofSpriteAnimationComponent::MofSpriteAnimationComponent(
    Actor* owner, int update_order)
    : Component(owner, update_order) {}

void base_engine::MofSpriteAnimationComponent::SetSpriteComponent(
    SpriteComponent* component) {
  sprite_ = component;
}

bool base_engine::MofSpriteAnimationComponent::Load(
    base_engine::SpriteComponent* component, std::span<SpriteAnimationClip> clips) {
  std::vector<Mof::SpriteAnimationCreate> pac(clips.size());
  for (MofU32 i = 0; i < clips.size(); i++) {
    pac[i] = Convert(clips[i]);
    motion_map_[clips[i].name] = i;
  }
  SetSpriteComponent(component);
  sprite_->SetClipRect(motion_.GetSrcRect());
  return motion_.Create(pac.data(), clips.size());
}

bool base_engine::MofSpriteAnimationComponent::ChangeMotion(
    const std::string_view name, const bool is_same) {
  return motion_.ChangeMotion(motion_map_[name], is_same);
}

bool base_engine::MofSpriteAnimationComponent::IsMotion(
    const std::string_view name) const {
  const auto& v = motion_map_.find(name);
  if (v == motion_map_.end()) {
    return false;
  }

  return motion_.GetMotionNo() == v->second;
}

bool base_engine::MofSpriteAnimationComponent::IsEndMotion() {
  return motion_.IsEndMotion();
}

void base_engine::MofSpriteAnimationComponent::Update() {
  motion_.AddTimer(animation_detail::kFrameTime);
  if (!sprite_) return;
  sprite_->SetClipRect(motion_.GetSrcRect());
}
