#include "ParallaxCameraFlowLayer.h"

#include "CameraComponent.h"
#include "ParallaxCameraFlowLayerComponent.h"
#include "ResourceContainer.h"
#include "SpriteComponent.h"
using namespace base_engine;
using RC = ResourceContainer;

void CreateRow(int y_count, Game* game, const ActorWeakPtr camera_actor,
               const ParallaxCameraFlowLayer::CreateInfo& def,
               Actor* const layer,
               const std::shared_ptr<Mof::ITexture*> image) {
  for (int x_count = 0; x_count < 3; ++x_count) {
    const auto sprite_actor = new Actor(game);
    layer->AddChild(sprite_actor->GetId());
    const auto sprite = new SpriteComponent(sprite_actor, def.draw_order);
    sprite->SetImage(*image);
    sprite_actor->SetPosition(
        Vector2{static_cast<float>((*image)->GetWidth()) * (x_count - 1),
                static_cast<float>((*image)->GetHeight()) * (y_count - 1)});
    const auto rotation =
        new HorizontalDynamicImageRotationComponent(sprite_actor);
    rotation->Create(camera_actor);
  }
}

Actor* ParallaxCameraFlowLayer::Create(Game* game, std::string_view name,
                                       const std::span<CreateInfo>& literals) {
  const auto camera_actor = CameraComponent::GetMainCamera().lock()->GetOwner();

  const auto parallax_actor = new Actor(game);
  for (const auto& def : literals) {
    const auto layer = new Actor(game);
    const auto parallax = new ParallaxCameraFlowLayerComponent(layer);
    parallax->Create(camera_actor, def.follow_per_x, def.follow_per_y,
                     def.initial_position);
    parallax_actor->AddChild(layer->GetId());
    const auto image = RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
        {std::string{name.data()} + std::string{def.literal_name.data()}});
    if (def.vertical_loop) {
      CreateRow(0, game, camera_actor, def, layer, image);
      CreateRow(1, game, camera_actor, def, layer, image);
      CreateRow(2, game, camera_actor, def, layer, image);

    } else {
      CreateRow(1, game, camera_actor, def, layer, image);
    }
  }

  return parallax_actor;
}
