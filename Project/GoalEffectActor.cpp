#include "GoalEffectActor.h"

#include <numbers>

#include "BaseEngineCore.h"
#include "GameWindow.h"
#include "IBaseEngineTexture.h"
#include "ImageComponent.h"
#include "PositionXTween.h"
using namespace base_engine;
using ::GoalEffectActor;
class GoalEffectActor::GoalEffectComponent final : public Component {
  ImageComponent* top_ = nullptr;
  ImageComponent* bottom_ = nullptr;
  ImageComponent* popup_ = nullptr;
  ImageComponent* next_logo_ = nullptr;

 public:
  explicit GoalEffectComponent(Actor* owner);

  void Start() override;
  void Update() override;
};
GoalEffectActor::GoalEffectComponent::GoalEffectComponent(Actor* owner)
    : Component(owner) {}

void GoalEffectActor::GoalEffectComponent::Start() {
  const auto img_letter =
      BASE_ENGINE(Texture)->Get("UI/Result/DiagonalLetterBox.png");
  const auto img_popup = BASE_ENGINE(Texture)->Get("UI/Popup/Result.png");
  const auto img_next_logo = BASE_ENGINE(Texture)->Get("UI/Nextbutton/Result.png");
  auto bottom_actor = new Actor(owner_->GetGame());
  auto top_actor = new Actor(owner_->GetGame());
  auto popup_actor = new Actor(owner_->GetGame());

  top_actor->SetPosition({-1920, 0});
  top_ = new ImageComponent(top_actor);
  top_->SetImage(img_letter);
  top_->SetAngle(std::numbers::pi_v<float>);
  top_->SetAlignment(Mof::TEXALIGN_BOTTOMRIGHT);

  bottom_actor->SetPosition({1920, 0});
  bottom_ = new ImageComponent(bottom_actor);
  bottom_->SetImage(img_letter);
  bottom_->SetOffset({0, window::kHeight});
  bottom_->SetAlignment(Mof::TEXALIGN_BOTTOMLEFT);

  popup_ = new ImageComponent(popup_actor);
  popup_->SetImage(img_popup);
  popup_->SetOffset({300, 300});
  bottom_->SetEnabled(true);
  top_->SetEnabled(true);

  auto next_logo_actor = new Actor(owner_->GetGame());
  next_logo_ = new ImageComponent(next_logo_actor);

  ma_tween::PositionXTween::TweenLocalPositionX(bottom_actor, 0, 3);
  ma_tween::PositionXTween::TweenLocalPositionX(top_actor, 0, 3);
  ma_tween::PositionXTween::TweenLocalPositionX(popup_actor, 300, 3)
      .SetOnComplete([this]() {});
}

void GoalEffectActor::GoalEffectComponent::Update() {}

GoalEffectActor::GoalEffectActor(base_engine::Game* game) : Actor(game) {}

void GoalEffectActor::Start() { new GoalEffectComponent(this); }
