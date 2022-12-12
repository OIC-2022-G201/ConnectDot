#include "GoalEffectActor.h"

#include <numbers>

#include "BaseEngineCore.h"
#include "GameWindow.h"
#include "IBaseEngineTexture.h"
#include "ImageComponent.h"
using namespace base_engine;
using ::GoalEffectActor;
class GoalEffectActor::GoalEffectComponent final : Component {
  ImageComponent* top_ = nullptr;
  ImageComponent* bottom_ = nullptr;
  ImageComponent* popup_ = nullptr;

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

  top_ = new ImageComponent(owner_);
  top_->SetImage(img_letter);
  top_->SetAngle(std::numbers::pi_v<float>);
  top_->SetAlignment(Mof::TEXALIGN_BOTTOMRIGHT);
  bottom_ = new ImageComponent(owner_);
  bottom_->SetImage(img_letter);
  bottom_->SetOffset({0, window::kHeight});
  bottom_->SetAlignment(Mof::TEXALIGN_BOTTOMLEFT);

  popup_ = new ImageComponent(owner_);
  popup_->SetImage(img_popup);
  popup_->SetOffset({300, 300});

  bottom_->SetEnabled(false);
  top_->SetEnabled(false);
}

void GoalEffectActor::GoalEffectComponent::Update() {}

GoalEffectActor::GoalEffectActor(base_engine::Game* game) : Actor(game) {}

void GoalEffectActor::Start() { new GoalEffectComponent(this); }
