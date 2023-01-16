#include "TransitionFadeSystem.h"

#include "ImageComponent.h"
#include "MofShader.h"
#include "ResourceContainer.h"
#include "SceneManager.h"
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

void TransitionFadeSystem::SceneTransition(const std::string_view scene_name,
                                           TransitionFadeInfo in_duration,
                                           TransitionFadeInfo out_duration) {
  FadeIn(in_duration.duration)
      .SetOnComplete([scene_name, out_duration, this] {
        scene::LoadScene(scene_name);
        game_->SetNextFrameEvent([this, out_duration] {
          FadeOut(out_duration.duration).SetEase(out_duration.ease);
        });
      })
      .SetEase(in_duration.ease);
}

ma_tween::TweenDriver<float>& TransitionFadeSystem::FadeIn(float duration) {
  {
    const auto actor = new Actor(game_);
    const auto image = new ImageComponent(actor, 3000);

    image->SetImage(
        *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("Fade"));
    image->SetMaterial(material_);
    image->SetColor(MOF_ARGB(255, 29, 33, 45));
    Progress progress{1.2f};
    material_->SetParameter({"progress", 0, PropertyType::kBuffer, &progress});
  }
  return ma_tween::VirtualTweenFloat::Tween(
      game_, 1.2, 0.0f, 3, [this](float b) {
        Progress progress{b};
        material_->SetParameter(
            {"progress", 0, PropertyType::kBuffer, &progress});
      });
}

ma_tween::TweenDriver<float>& TransitionFadeSystem::FadeOut(float duration) {
  const auto actor = new Actor(game_);
  const auto image = new ImageComponent(actor, 3000);

  image->SetImage(*RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("Fade"));
  image->SetMaterial(material_);
  image->SetColor(MOF_ARGB(255, 29, 33, 45));
  Progress progress{0.0f};
  material_->SetParameter({"progress", 0, PropertyType::kBuffer, &progress});
  return ma_tween::VirtualTweenFloat::Tween(
             game_, 0.0f, 1.2f, 3,
             [this](float b) {
               Progress progress{b};
               material_->SetParameter(
                   {"progress", 0, PropertyType::kBuffer, &progress});
             })
      .SetOnComplete([actor, this] { game_->RemoveActor(actor); });
}
