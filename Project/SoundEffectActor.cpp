#include "SoundEffectActor.h"

#include <ranges>

#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "MofSpriteAnimationComponent.h"
#include "ResourceContainer.h"
using namespace base_engine;
using RC = ResourceContainer;

void SoundEffectActor::Play(const float range) {
  range_ = range;
  if (!is_create_) {
    is_create_ = true;

    collision_ = new CollisionComponent(this);
    collision_->SetObjectFilter(kSoundObjectFilter);
    collision_->SetTargetFilter(kSoundTargetFilter);
    collision_->SetTrigger(true);

    debug_shape_ = new ShapeRenderComponent(this, 100);
    debug_shape_->SetColor(MOF_COLOR_GREEN);
    debug_shape_->SetFillMode(FillMode::No);
    auto& [sprite_, motion_] = effects_[0];
    sprite_ = new base_engine::SpriteComponent(this, 130);
    const auto sprite_resource =
        RC::GetPack<RC::AnimationResourcePack>("SoundAnimation");
    sprite_->SetImage(*sprite_resource->Get<RC::Sprite>()->Get(0));
    sprite_->SetAlignment(Mof::TEXALIGN_CENTERLEFT);
    motion_ = new MofSpriteAnimationComponent(this);
    motion_->Load(sprite_, *sprite_resource->Get<RC::AnimationClips>()->Get(0));

    auto& [sprite2_, motion2_] = effects_[1];
    sprite2_ = new SpriteComponent(this, 130);
    sprite2_->SetImage(*sprite_resource->Get<RC::Sprite>()->Get(0));
    sprite2_->SetAlignment(Mof::TEXALIGN_CENTERRIGHT);
    sprite2_->SetFlip(Flip::kHorizontal);
    motion2_ = new MofSpriteAnimationComponent(this);
    motion2_->Load(sprite2_,
                   *sprite_resource->Get<RC::AnimationClips>()->Get(0));
  }
  const auto shape = std::make_shared<Rect>(-range_, -range_, range_, range);
  collision_->SetShape(shape);
  collision_->SetObjectFilter(kSoundObjectFilter);
  debug_shape_->SetShape(shape);
  debug_shape_->SetEnabled(true);
  for (const auto& [sprite, motion] : effects_) {
    motion->Play("Sound");
    sprite->SetEnabled(true);
  }
  SetName("SoundEffect");
}

void SoundEffectActor::Stop() {
  collision_->SetObjectFilter(CollisionLayer::kNone);
  debug_shape_->SetEnabled(false);
  for (const auto& [sprite, motion] : effects_) {
    motion->Stop(true);
    sprite->SetEnabled(false);
  }
}
