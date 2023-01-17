#include "TitleListener.h"

#include <ranges>

#include "ButtonPressEvent.h"
#include "ClipSizeXTween.h"
#include "ClipSizeYTween.h"
#include "ComponentServiceLocator.h"
#include "DummyTween.h"
#include "EventBus.h"
#include "EventHandler.h"
#include "ITransitionFadeSystem.h"
#include "ImageAlphaTween.h"
#include "InputManager.h"
#include "NinePatchImageComponent.h"
#include "ResourceContainer.h"
#include "SceneManager.h"
#include "StageContainer.h"
#include "TransitionParameter.h"
using namespace base_engine;
constexpr float kAnimationElementTime = 0.15f;
constexpr float kAnimationPopupTime = 0.3f;
constexpr float kAnimationWait = 0.075f;
constexpr float kAnimationSum = kAnimationElementTime + kAnimationPopupTime;

constexpr float kAnimationCompleteTime =
    kAnimationElementTime + kAnimationPopupTime + kAnimationWait;

class TitleComponent::TitleListener final
    : public EventHandler<ButtonPressEvent> {
 public:
  void OnEvent(ButtonPressEvent& press) override;
};
void TitleComponent::TitleListener::OnEvent(ButtonPressEvent& press) {}

TitleComponent::TitleComponent(base_engine::Actor* owner) : Component(owner) {}

void TitleComponent::Start() {
  listener_ = std::make_unique<TitleListener>();
  handle_ = EventBus::AddHandler(*listener_);
  line_actor_ = new base_engine::Actor(owner_->GetGame());
  const auto line = new base_engine::ImageComponent(line_actor_);
  line->SetImage(
      *ResourceContainer::GetResource<ResourceContainer::SpriteResourcePack,
                                      ResourceContainer::Sprite>("PopupLine"));
  line_ = line_actor_->GetComponent<base_engine::ImageComponent>();
}

void TitleComponent::Update() {
  if (current_popup_ > 0) {
    if (InputManager::Instance()->ButtonHorizontal() < 0 &&
        !popups_[current_popup_]->is_animation) {
      popups_[current_popup_]->Hide();
      ma_tween::ClipSizeXTween::TweenClipSizeX(line_actor_, line_, 0,
                                               kAnimationWait)
          .SetSequenceDelay(kAnimationSum)
          .SetOnComplete([this] {
            current_popup_ = 0;
            if (main_popup_.elements.contains("selector")) {
              main_popup_.elements["selector"]->SetEnable(true);
            }
          });
    }
  }
  if (current_popup_ == 0 && InputManager::Instance()->ButtonHorizontal() > 0 &&
      !popups_[current_popup_]->is_animation) {
    dynamic_cast<ButtonSelecter*>(main_popup_.elements["selector"])
        ->ButtonSelect();
  }
}

void TitleComponent::Popup::Hide() {
  is_animation = true;
  constexpr bool enable = false;

  const auto panel =
      popup_actor->GetComponent<base_engine::NinePatchImageComponent>();
  for (const auto& actor : this->elements | std::views::values) {
    //フェードアウト
    if (auto image = actor->GetComponent<base_engine::ImageComponent>();
        image.expired()) {
      actor->SetEnable(enable);
      continue;
    }
    ma_tween::ImageAlphaTween::TweenImageAlpha(actor, 0, kAnimationElementTime)
        .SetOnComplete([actor] { actor->SetEnable(enable); });
  }
  ma_tween::ClipSizeXTween::TweenClipSizeX(popup_actor, panel, 0,
                                           kAnimationPopupTime)
      .SetSequenceDelay(kAnimationElementTime)
      .SetEase(EaseType::kInoutcirc);
  ma_tween::ClipSizeYTween::TweenClipSizeY(popup_actor, panel, 0,
                                           kAnimationPopupTime)
      .SetSequenceDelay(kAnimationElementTime)
      .SetEase(EaseType::kInoutcirc)
      .SetOnComplete([this, panel] { panel.lock()->SetEnabled(false); });

  ma_tween::DummyTween::TweenDummy(popup_actor, kAnimationCompleteTime)
      .SetOnComplete([this] { is_animation = false; });
}

void TitleComponent::Popup::Show() {
  is_animation = true;
  constexpr bool enable = true;

  const auto panel =
      popup_actor->GetComponent<base_engine::NinePatchImageComponent>();

  panel.lock()->SetEnabled(enable);
  panel.lock()->SetClipRect({0, 0, 0, 0});
  ma_tween::ClipSizeXTween::TweenClipSizeX(popup_actor, panel, size.x,
                                           kAnimationPopupTime)
      .SetEase(EaseType::kInoutcirc);
  ma_tween::ClipSizeYTween::TweenClipSizeY(popup_actor, panel, size.y,
                                           kAnimationPopupTime)
      .SetEase(EaseType::kInoutcirc)
      .SetOnComplete([this] {
        for (const auto& actor : this->elements | std::views::values) {
          //フェードイン
          auto image = actor->GetComponent<base_engine::ImageComponent>();

          if (image.expired()) {
            continue;
          }
          actor->SetEnable(enable);
          image.lock()->SetColor(MOF_ARGB(0, 255, 255, 255));
          ma_tween::ImageAlphaTween::TweenImageAlpha(actor, 255,
                                                     kAnimationElementTime)
              .SetOnComplete([this, actor] {

              });
        }
        ma_tween::DummyTween::TweenDummy(popup_actor, kAnimationElementTime)
            .SetOnComplete([this] {
              is_animation = false;
              if (elements.contains("selector")) {
                elements["selector"]->SetEnable(enable);
              }
            });
      });
}

void TitleComponent::NewGameEvent() {
  const auto stage_container =
      ServiceLocator::Instance().Resolve<StageContainer>();
  stage_container->SelectStage("Stage1");
  ServiceLocator::Instance().Resolve<ITransitionFadeSystem>()->SceneTransition(
      scene::kGame, kNewGameToGameFadeIn, kNewGameToGameFadeOut);
}

void TitleComponent::StageSelect(std::string_view name) {
  const auto stage_container =
      ServiceLocator::Instance().Resolve<StageContainer>();
  stage_container->SelectStage(name);
  ServiceLocator::Instance().Resolve<ITransitionFadeSystem>()->SceneTransition(
      scene::kGame, kStageSelectToGameFadeIn, kStageSelectToGameFadeOut);
}

void TitleComponent::OpenStageSelectPopup() {
  if (stage_select_popup_.is_animation) return;
  current_popup_ = 1;
  stage_select_popup_.is_animation = true;
  main_popup_.elements["selector"]->SetEnable(false);

  const auto rect = main_popup_.popup_actor
                        ->GetComponent<base_engine::NinePatchImageComponent>()
                        .lock()
                        ->GetClipRect();
  const Vector2 pos = {
      main_popup_.popup_actor->GetPosition().x + rect.Right,
      main_popup_.elements["StageSelectButton"]->GetPosition().y};
  line_actor_->SetPosition(pos);
  line_.lock()->SetClipRect({0, 0, 0, 5});
  ma_tween::ClipSizeXTween::TweenClipSizeX(line_actor_, line_, 40,
                                           kAnimationWait)
      .SetOnComplete([this] { stage_select_popup_.Show(); });
}
void TitleComponent::OpenKeyGuidePopup() {
  if (key_guide_popup_.is_animation) return;
  current_popup_ = 2;
  key_guide_popup_.is_animation = true;
  main_popup_.elements["selector"]->SetEnable(false);

  const auto rect = main_popup_.popup_actor
                        ->GetComponent<base_engine::NinePatchImageComponent>()
                        .lock()
                        ->GetClipRect();
  const Vector2 pos = {main_popup_.popup_actor->GetPosition().x + rect.Right,
                       main_popup_.elements["KeyGuideButton"]->GetPosition().y};
  line_actor_->SetPosition(pos);
  line_.lock()->SetClipRect({0, 0, 0, 5});
  ma_tween::ClipSizeXTween::TweenClipSizeX(line_actor_, line_, 40,
                                           kAnimationWait)
      .SetOnComplete([this] { key_guide_popup_.Show(); });
}
void TitleComponent::CloseStageSelectPopup() { stage_select_popup_.Hide(); }
