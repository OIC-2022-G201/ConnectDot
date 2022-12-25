#include "SoundEffectActor.h"

#include "DrawOrder.h"
#include "ResourceContainer.h"
#include "MofSpriteAnimationComponent.h"
using namespace base_engine;
using RC = ResourceContainer;

void SoundEffectActor::Play()
{
  if (!sprite_) {
    sprite_ = new base_engine::SpriteComponent(this, 130);
    const auto sprite_resource = RC::GetPack<RC::AnimationResourcePack>("SoundAnimation");
    sprite_->SetImage(*sprite_resource->Get<RC::Sprite>()->Get(0));

    motion_ = new base_engine::MofSpriteAnimationComponent(this);
    motion_->Load(sprite_, *sprite_resource->Get<RC::AnimationClips>()->Get(0));
  }
  motion_->Play("Sound");
}

void SoundEffectActor::Stop() { motion_->Stop(true); }
