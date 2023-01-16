#include "GoalEffectActor.h"

#include <numbers>

#include "BaseEngineCore.h"
#include "ButtonPressEvent.h"
#include "ClipSizeXTween.h"
#include "ClipSizeYTween.h"
#include "ComponentServiceLocator.h"
#include "CounterComponent.h"
#include "Dummytween.h"
#include "EventHandler.h"
#include "GameWindow.h"
#include "HandlerRegistration.h"
#include "IBaseEngineTexture.h"
#include "ImageAlphaTween.h"
#include "ImageComponent.h"
#include "InputManager.h"
#include "ITransitionFadeSystem.h"
#include "NinePatchImageComponent.h"
#include "PositionXTween.h"
#include "ResourceContainer.h"
#include "ResultModel.h"
#include "SceneManager.h"
#include "TitleSceneFactory.h"
using namespace base_engine;
using ::GoalEffectActor;
using RC = ResourceContainer;
class ResultListener final : public EventHandler<ButtonPressEvent> {
 public:
  void OnEvent(ButtonPressEvent& press) override {}
};

class Image {
 public:
  Image& Create(Game* game, float x, float y, const std::string_view name,
                const int order = 2000) {
    actor = new Actor(game);
    sprite = new ImageComponent(actor, order);
    actor->SetPosition({x, y});
    sprite->SetImage(
        *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(name.data()));
    return *this;
  }

  [[nodiscard]] ImageComponent& Sprite() const { return *sprite; }
  [[nodiscard]] Actor* Owner() const { return actor; }

 private:
  Actor* actor;
  ImageComponent* sprite;
};
class PopupPanel {
 public:
  PopupPanel& Create(Game* game, const Rect& rect, const std::string_view name,
                     const int order = 2000) {
    actor = new Actor(game);
    panel = new NinePatchImageComponent(actor, order);
    const auto sprite_resource =
        RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(name.data());
    panel->SetImage(*sprite_resource, {2, 2}, {126, 126});
    const Vector2 lt = rect.GetTopLeft();
    const Vector2 rb = rect.GetBottomRight();
    size_ = rb - lt;
    actor->SetPosition(lt);
    panel->SetClipRect({{0, 0}, {10, 10}});
    return *this;
  }

  [[nodiscard]] NinePatchImageComponent& Panel() const { return *panel; }
  [[nodiscard]] Actor* Owner() const { return actor; }

  Vector2 size_;

 private:
  Actor* actor;
  NinePatchImageComponent* panel;
};
class GoalEffectActor::GoalEffectComponent final : public Component {
  Image top_;
  Image bottom_;
  Image popup_text_;
  Image next_logo_;
  Image clear_logo_;
  Image character_logo_;
  PopupPanel panel_;
  std::unique_ptr<ResultListener> listener_;
  std::shared_ptr<HandlerRegistration> handle_;
  bool end_animation_ = false;
  CounterComponent* time_counter;
  CounterComponent* found_counter;
  CounterComponent* beacon_counter;

 public:
  explicit GoalEffectComponent(Actor* owner);

  void Start() override;
  void Update() override;
  void Show() {}

 private:
  auto& OpenPopup() const {
    panel_.Panel()
        .SetColor(MOF_ARGB(255, 255, 255, 255))
        .SetClipRect({0, 0, 0, 0});
    panel_.Panel().SetEnabled(true);
    ma_tween::ClipSizeYTween::TweenClipSizeY(
        panel_.Owner(), panel_.Owner()->GetComponent<NinePatchImageComponent>(),
        panel_.size_.y, 0.5f)
        .SetEase(EaseType::kInoutcirc);
    return ma_tween::ClipSizeXTween::TweenClipSizeX(
               panel_.Owner(),
               panel_.Owner()->GetComponent<NinePatchImageComponent>(),
               panel_.size_.x, 0.5f)
        .SetEase(EaseType::kInoutcirc);
  }
  auto& ShowScore() const {
    return ma_tween::DummyTween::TweenDummy(panel_.Owner(), 0.01)
        .SetOnComplete([this] {
          popup_text_.Sprite().SetColor(MOF_ARGB(255, 255, 255, 255));
          time_counter->SetEnable(true);
          found_counter->SetEnable(true);
          beacon_counter->SetEnable(true);
        });
  }
  auto& NextLogoAnimation() const {
    return ma_tween::ImageAlphaTween::TweenImageAlpha(next_logo_.Owner(), 255,
                                                      0.17f);
  }
  auto& ClearLogoAnimation() const {
    return ma_tween::ImageAlphaTween::TweenImageAlpha(clear_logo_.Owner(), 255,
                                                      0.17f);
  }
  auto& CharacterLogoAnimation() const {
    return ma_tween::ImageAlphaTween::TweenImageAlpha(character_logo_.Owner(),
                                                      255, .17f);
  }
  auto& LetterBoxAnimation() const {
    constexpr float letter_time = 0.2f;
    ma_tween::PositionXTween::TweenLocalPositionX(bottom_.Owner(), 0,
                                                  letter_time)
        .SetEase(EaseType::kOutquart)
        .SetSequenceDelay(1);
    return ma_tween::PositionXTween::TweenLocalPositionX(top_.Owner(), 0,
                                                         letter_time)
        .SetEase(EaseType::kOutquart)
        .SetSequenceDelay(1)
        .SetOnComplete([this] { ClearLogoAnimation(); });
  }
};
GoalEffectActor::GoalEffectComponent::GoalEffectComponent(Actor* owner)
    : Component(owner) {}

void GoalEffectActor::GoalEffectComponent::Start() {
  const auto game = owner_->GetGame();
  top_.Create(game, -1920, 0, "LetterBox")
      .Sprite()
      .SetAngle(std::numbers::pi_v<float>)
      .SetAlignment(Mof::TEXALIGN_BOTTOMRIGHT);

  bottom_.Create(game, 1920, window::kHeight, "LetterBox")
      .Sprite()
      .SetAlignment(Mof::TEXALIGN_BOTTOMLEFT);

  popup_text_.Create(game, 406, 359, "ResultPopup", 2001)
      .Sprite()
      .SetColor(MOF_ARGB(0, 255, 255, 255));

  clear_logo_.Create(game, 176, 125, "ResultLogo")
      .Sprite()
      .SetColor(MOF_ARGB(0, 255, 255, 255));
  character_logo_.Create(game, 840, 0, "ResultCharacter")
      .Sprite()
      .SetColor(MOF_ARGB(0, 255, 255, 255));

  next_logo_.Create(game, 972, 948, "NextLogo")
      .Sprite()
      .SetColor(MOF_ARGB(0, 255, 255, 255));

  panel_.Create(game, {324, 320, 1000, 857}, "Panel")
      .Panel()
      .SetColor(MOF_ARGB(0, 255, 255, 255))
      .SetEnabled(false);

  const auto score = ComponentServiceLocator::Instance().Resolve<ResultModel>();

  const auto found_actor = new Actor(owner_->GetGame());
  found_counter = new CounterComponent(found_actor);
  found_counter->SetNumber(score->GetFoundCount());
  found_actor->SetPosition({703, 476});

  const auto beacon_counter_actor = new Actor(owner_->GetGame());
  beacon_counter = new CounterComponent(beacon_counter_actor);
  beacon_counter->SetNumber(score->GetBeaconUsedTimes());
  beacon_counter_actor->SetPosition({703, 606});

  const auto time_counter_actor = new Actor(owner_->GetGame());
  time_counter = new CounterComponent(time_counter_actor);
  time_counter->SetNumber(score->GetTime());
  time_counter_actor->SetPosition({703, 736});

  found_counter->SetEnable(false);
  beacon_counter->SetEnable(false);
  time_counter->SetEnable(false);

  LetterBoxAnimation().SetOnComplete([this] {
    ClearLogoAnimation();
    CharacterLogoAnimation().SetOnComplete([this] {
      OpenPopup().SetOnComplete([this] {
        ShowScore();
        NextLogoAnimation().SetOnComplete([this] { end_animation_ = true;
        });
      });
    });
  });
}

void GoalEffectActor::GoalEffectComponent::Update() {
  if (!end_animation_) return;
  if (InputManager::Instance()->JumpFire()) {

    ServiceLocator::Instance()
        .Resolve<ITransitionFadeSystem>()
        ->SceneTransition(scene::kTitle, {0.6f, EaseType::kOutcirc},
                          {0.6f, EaseType::kIncirc});
  }
}

GoalEffectActor::GoalEffectActor(base_engine::Game* game) : Actor(game) {}

void GoalEffectActor::Start() { new GoalEffectComponent(this); }
