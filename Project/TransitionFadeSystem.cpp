#include "TransitionFadeSystem.h"

#include "MofShader.h"
#include "ResourceContainer.h"
#include "TransitionFadeComponent.h"
#include "VirtualTweenFloat.h"
using namespace base_engine;
using RC = ResourceContainer;

struct alignas(16) Progress {
  float progress;
};
TransitionFadeSystem::TransitionFadeSystem(base_engine::Game* game)
    : game_(game) {
  material_ = std::make_shared<Material>();
  {
    const auto shader =
        std::make_shared<MofShader>("Shader/TransitionFade.hlsl");
    shader->CreateParameter({"Progress", PropertyType::kBuffer, 16});
    material_->SetShader(shader);
  }
}

void TransitionFadeSystem::SceneTransition(const std::string& scene_name) {}

void TransitionFadeSystem::Fade() {
  {
    const auto actor = new Actor(game_);
    const auto image = new ImageComponent(actor, 3000);

    image->SetImage(
        *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("Fade"));
    image->SetMaterial(material_);
    image->SetColor(MOF_ARGB(255, 29, 33, 45));
  }
  ma_tween::VirtualTweenFloat::Tween(game_, 1.2, 0, 3, [this](float b) {
    Progress progress{b};
    material_->SetParameter({"progress", 0, PropertyType::kBuffer, &progress});
  });
}
