#include "TransitionFadeComponent.h"

#include "MofShader.h"
#include "ResourceContainer.h"

using namespace base_engine;

struct alignas(16) Progress {
  float progress;
};
TransitionFadeComponent::TransitionFadeComponent(base_engine::Actor* owner)
    : Component(owner) {
  material_ = std::make_shared<base_engine::Material>();
  {
    const auto shader =
        std::make_shared<MofShader>("Shader/TransitionFade.hlsl");
    shader->CreateParameter({"Progress", PropertyType::kBuffer, 16});
    material_->SetShader(shader);
    //Progress progress{0.5f};
    //material_->SetParameter({"Progress", 0, PropertyType::kBuffer, &progress});
  }
}

void TransitionFadeComponent::Bind(base_engine::ImageComponent* image) const {
  image->SetMaterial(material_);
  image->SetColor(MOF_ARGB(255, 29, 33, 45));
}

void TransitionFadeComponent::Start() {}

void TransitionFadeComponent::Update() {
  progress_ += 0.01f;
  if (progress_ > 1.5) {
    progress_ = 1.5;
  }
  Progress progress{progress_};
  material_->SetParameter({"progress", 0, PropertyType::kBuffer, &progress});
}
