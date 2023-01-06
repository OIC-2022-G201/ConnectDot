#include "OneTimeEffectActor.h"

#include "MofSpriteAnimationComponent.h"
#include "ResourceContainer.h"

using namespace base_engine;
using RC = ResourceContainer;
OneTimeEffectActor::OneTimeEffectActor(base_engine::Game* game) : Actor(game) {}

void OneTimeEffectActor::Start() {}

void OneTimeEffectActor::Update() {
  if (motion_->IsEndMotion()) {
    GetGame()->RemoveActor(this);
  }
}

void OneTimeEffectActor::Show() const { sprite_->SetEnabled(true); }

void OneTimeEffectActor::Hide() const { sprite_->SetEnabled(false); }

void OneTimeEffectActor::Play() { motion_->Play("Animation"); }

OneTimeEffectActor* OneTimeEffectActor::Create(base_engine::Game* game,
                                               const base_engine::Vector2& pos,
                                               std::string_view name,
                                               int draw_order) {
  const auto actor = new OneTimeEffectActor(game);
  actor->SetPosition(pos);

  const auto pack = RC::GetPack<RC::AnimationResourcePack>(name.data());
  actor->motion_ = new MofSpriteAnimationComponent(actor);
  actor->sprite_ = new SpriteComponent(actor, draw_order);
  actor->sprite_->SetImage(*pack->Get<RC::Sprite>()->Get(0));
  actor->motion_->Load(actor->sprite_,
                       *pack->Get<RC::AnimationClips>()->Get(0));
  actor->sprite_->SetAlignment(Mof::TEXALIGN_CENTERCENTER);
  return actor;
}
