#include "ParallaxCameraFlowLayer.h"

#include "CameraComponent.h"
#include "ParallaxCameraFlowLayerComponent.h"
#include "ResourceContainer.h"
#include "SpriteComponent.h"
using namespace base_engine;
using RC = ResourceContainer;
Actor* ParallaxCameraFlowLayer::Create(Game* game, std::string_view name,
                                       const std::span<CreateInfo>& literals) {
  const auto camera_actor = CameraComponent::GetMainCamera().lock()->GetOwner();

  const auto parallax_actor = new Actor(game);
  for (const auto& def : literals) {
    const auto layer = new Actor(game);
    const auto parallax = new ParallaxCameraFlowLayerComponent(layer);
    parallax->Create(camera_actor, def.follow_per_x,def.follow_per_y,def.initial_position);
    parallax_actor->AddChild(layer->GetId());
    const auto image = RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
        {std::string{name.data()} + std::string{def.literal_name.data()}});

    for (int i = 0; i < 3; ++i) {
      const auto sprite_actor = new Actor(game);
      layer->AddChild(sprite_actor->GetId());
      const auto sprite = new SpriteComponent(sprite_actor, def.draw_order);
      sprite->SetImage(*image);
      sprite_actor->SetPosition(
          Vector2{static_cast<float>((*image)->GetWidth()) * (i - 1), 0});
      const auto rotation =
          new HorizontalDynamicImageRotationComponent(sprite_actor);
      rotation->Create(camera_actor);
    }
  }

  return parallax_actor;
}
