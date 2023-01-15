#include "TestSceneFactory.h"

#include "Actor.h"
#include "PositionXTween.h"
#include "PositionYTween.h"
#include "ResourceContainer.h"
#include "SpriteComponent.h"

using namespace base_engine;
using RC = ResourceContainer;
void TestSceneFactory::Factory() {
  const auto actor = new Actor(game_);
  const auto sprite = new SpriteComponent(actor);

  const auto image =
      *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("Panel");
  sprite->SetImage(image);

  ma_tween::PositionXTween::TweenLocalPositionX(actor, 300, 3.0f)
      .SetOnComplete([actor] {
        ma_tween::PositionXTween::TweenLocalPositionX(actor, 0, 3.0f);
      }).SetEase(EaseType::kInbounce);
}
