#include "SparkEffectActor.h"

#include "MofSpriteAnimationComponent.h"
#include "ResourceContainer.h"
using namespace base_engine;
using RC = ResourceContainer;
SparkEffectActor::SparkEffectActor(base_engine::Game* game) : Actor(game) {}

void SparkEffectActor::Start() {}

void SparkEffectActor::Update() {
  if (motion_->IsEndMotion()) {
    GetGame()->RemoveActor(this);
  }
}

void SparkEffectActor::Show() const { sprite_->SetEnabled(true); }

void SparkEffectActor::Hide() const { sprite_->SetEnabled(false); }

void SparkEffectActor::Play() { motion_->Play("Animation"); }

void SparkEffectActor::Create(const Vector2& pos, const std::string_view name) {
  SetPosition(pos);

  const auto pack = RC::GetPack<RC::AnimationResourcePack>(name.data());
  motion_ = new MofSpriteAnimationComponent(this);
  sprite_ = new SpriteComponent(this, 150);
  sprite_->SetImage(*pack->Get<RC::Sprite>()->Get(0));
  motion_->Load(sprite_, *pack->Get<RC::AnimationClips>()->Get(0));
  sprite_->SetAlignment(Mof::TEXALIGN_CENTERCENTER);
}
