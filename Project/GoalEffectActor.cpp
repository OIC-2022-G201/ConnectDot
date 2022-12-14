#include "GoalEffectActor.h"

#include <numbers>

#include "BaseEngineCore.h"
#include "ButtonPressEvent.h"
#include "EventHandler.h"
#include "GameWindow.h"
#include "HandlerRegistration.h"
#include "IBaseEngineTexture.h"
#include "ImageAlphaTween.h"
#include "ImageComponent.h"
#include "InputManager.h"
#include "PositionXTween.h"
#include "SceneManager.h"
#include "TitleSceneFactory.h"
using namespace base_engine;
using ::GoalEffectActor;
class ResultListener final : public EventHandler<ButtonPressEvent> {
 public:
  void OnEvent(ButtonPressEvent& press) override {}
};
class GoalEffectActor::GoalEffectComponent final : public Component {
  std::pair<Actor*, ImageComponent*> top_;
  std::pair<Actor*, ImageComponent*> bottom_;
  std::pair<Actor*, ImageComponent*> popup_;
  std::pair<Actor*, ImageComponent*> next_logo_;

  std::unique_ptr<ResultListener> listener_;
  std::shared_ptr<HandlerRegistration> handle_;
  bool end_animation_ = false;

 public:
  explicit GoalEffectComponent(Actor* owner);

  void Start() override;
  void Update() override;

  void DeleteActor(const std::pair<Actor*, ImageComponent*>* pair) const {
    owner_->GetGame()->RemoveActor(pair->first);
  }
};
GoalEffectActor::GoalEffectComponent::GoalEffectComponent(Actor* owner)
    : Component(owner) {}

void GoalEffectActor::GoalEffectComponent::Start() {
  const auto img_letter =
      BASE_ENGINE(Texture)->Get("UI/Result/DiagonalLetterBox.png");
  const auto img_popup = BASE_ENGINE(Texture)->Get("UI/Popup/Result.png");
  const auto img_next_logo =
      BASE_ENGINE(Texture)->Get("UI/Nextbutton/Nextlogo.png");
  bottom_.first = new Actor(owner_->GetGame());
  top_.first = new Actor(owner_->GetGame());
  popup_.first = new Actor(owner_->GetGame());

  top_.first->SetPosition({-1920, 0});
  top_.second = new ImageComponent(top_.first, 2000);
  top_.second->SetImage(img_letter);
  top_.second->SetAngle(std::numbers::pi_v<float>);
  top_.second->SetAlignment(Mof::TEXALIGN_BOTTOMRIGHT);

  bottom_.first->SetPosition({1920, 0});
  bottom_.second = new ImageComponent(bottom_.first, 2000);
  bottom_.second->SetImage(img_letter);
  bottom_.second->SetOffset({0, window::kHeight});
  bottom_.second->SetAlignment(Mof::TEXALIGN_BOTTOMLEFT);

  popup_.second = new ImageComponent(popup_.first, 2000);
  popup_.second->SetImage(img_popup);
  popup_.second->SetOffset({300, 300});
  popup_.second->SetColor(MOF_ARGB(0, 255, 255, 255));
  popup_.second->SetEnabled(false);

  next_logo_.first = new Actor(owner_->GetGame());
  next_logo_.first->SetPosition({1000, 700});

  next_logo_.second = new ImageComponent(next_logo_.first, 2000);
  next_logo_.second->SetImage(img_next_logo);
  next_logo_.second->SetEnabled(false);
  next_logo_.second->SetColor(MOF_ARGB(0, 255, 255, 255));

  constexpr float letter_time = 0.2f;
  ma_tween::PositionXTween::TweenLocalPositionX(bottom_.first, 0, letter_time)
      .SetEase(EaseType::kOutquart)
      .SetSequenceDelay(5);
  ma_tween::PositionXTween::TweenLocalPositionX(top_.first, 0, letter_time)
      .SetEase(EaseType::kOutquart)
      .SetSequenceDelay(5)
      .SetOnComplete([this] {
        popup_.second->SetEnabled(true);
        ma_tween::ImageAlphaTween::TweenImageAlpha(popup_.first, 255, 0.5)
            .SetOnComplete([this] {
              next_logo_.second->SetEnabled(true);
              ma_tween::ImageAlphaTween::TweenImageAlpha(next_logo_.first, 255,
                                                         0.5);
              end_animation_ = true;
            });
      });
}

void GoalEffectActor::GoalEffectComponent::Update() {
  if (!end_animation_) return;
  if (InputManager::Instance()->ButtonDecision()) {
    scene::LoadScene(scene::kTitle);
  }
}

GoalEffectActor::GoalEffectActor(base_engine::Game* game) : Actor(game) {}

void GoalEffectActor::Start() { new GoalEffectComponent(this); }
