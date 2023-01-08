#include "BeaconPowerUpActor.h"

#include "BeaconActor.h"
#include "BeaconPowerUpActionEvent.h"
#include "Dummytween.h"
#include "EventBus.h"
#include "InputManager.h"
#include "MofSpriteAnimationComponent.h"
#include "OneTimeEffectActor.h"
#include "PositionXTween.h"
#include "PositionYTween.h"
#include "ReceiverComponent.h"
#include "ResourceContainer.h"
#include "ScaleTween.h"
#include "SpriteAlphaTween.h"
#include "SpriteComponent.h"
#include "StageConstitution.h"
using namespace base_engine;
using RC = ResourceContainer;
constexpr float kSpawnY = 64;
constexpr float kAnimationTime = 0.5f;

class BeaconPowerUpActor::BeaconPowerUpActionComponent final
    : public Component {
 public:
  explicit BeaconPowerUpActionComponent(Actor* owner) : Component(owner) {}
  void Create(BeaconActor* target) {
    target_beacon_ = target;
    back_bar_sprite_ = CreateImage("FrameBar");
    back_bar_actor_ = back_bar_sprite_->GetOwner().lock().get();
    back_bar_actor_->SetPosition(back_bar_actor_->GetPosition() -
                                 Vector2{0, kSpawnY});
    back_bar_sprite_->SetColor(MOF_ARGB(0, 255, 255, 255));
    width_ = back_bar_sprite_->GetClipRect().GetWidth();

    beat_point_sprite_ = CreateImage("StopBar", Mof::TEXALIGN_CENTERCENTER);
    beat_point_actor_ = beat_point_sprite_->GetOwner().lock().get();
    beat_point_actor_->SetPosition(beat_point_actor_->GetPosition() -
                                   Vector2{0, kSpawnY});
    beat_point_sprite_->SetOffset({width_ * beat_point_, 0});
    beat_point_sprite_->SetColor(MOF_ARGB(0, 255, 255, 255));

    note_sprite_ = CreateImage("MoveBar");
    note_sprite_->SetColor(MOF_ARGB(0, 255, 255, 255));
    note_actor_ = note_sprite_->GetOwner().lock().get();
    note_actor_->SetPosition(note_actor_->GetPosition() - Vector2{0, kSpawnY});

    chain_actor_.clear();
    chain_actor_.emplace_back(
        target->GetComponent<ReceiverComponent>().lock()->GetOwner());
    std::weak_ptr<Actor> receiver_actor =
        target->GetComponent<ReceiverComponent>().lock()->GetSenderActor();

    while (true) {
      chain_actor_.emplace_back(receiver_actor);
      const auto receiver =
          receiver_actor.lock()->GetComponent<ReceiverComponent>();
      if (receiver.expired()) {
        break;
      }
      receiver_actor = receiver.lock()->GetSenderActor();
      if (receiver_actor.expired()) {
        break;
      }
    }
    current_iterator_ = chain_actor_.rbegin();
    {
      const auto pack =
          RC::GetPack<RC::AnimationResourcePack>("FlowElectroEffect");
      flow_actor_ = new Actor(owner_->GetGame());
      flow_sprite_ = new SpriteComponent(flow_actor_, 220);
      flow_sprite_->SetImage(*pack->Get<RC::Sprite>()->Get(0));
      flow_sprite_->SetOffset({64, 0});
      const auto animation = new MofSpriteAnimationComponent(flow_actor_);
      animation->Load(flow_sprite_, *pack->Get<RC::AnimationClips>()->Get(0));
      flow_actor_->SetPosition({chain_actor_.back().lock()->GetPosition()});
    }
  }
  void Start() override {
    {
      constexpr float up = kSpawnY;
      constexpr float t = kAnimationTime;
      ma_tween::PositionYTween::TweenLocalPositionY(
          note_actor_, note_actor_->GetPosition().y + up, t)
          .SetEase(EaseType::kOutquad);
      ma_tween::PositionYTween::TweenLocalPositionY(
          back_bar_actor_, back_bar_actor_->GetPosition().y + up, t)
          .SetEase(EaseType::kOutquad);
      ma_tween::PositionYTween::TweenLocalPositionY(
          beat_point_actor_, beat_point_actor_->GetPosition().y + up, t)
          .SetEase(EaseType::kOutquad);

      ma_tween::SpriteAlphaTween::Tween(note_actor_, 255, t)
          .SetEase(EaseType::kInoutexpo);
      ma_tween::SpriteAlphaTween::Tween(back_bar_actor_, 255, t)
          .SetEase(EaseType::kInoutexpo);
      ma_tween::SpriteAlphaTween::Tween(beat_point_actor_, 255, t)
          .SetEase(EaseType::kInoutexpo)
          .SetOnComplete([this] {
            start_ = true;
            space_key_effect_ = OneTimeEffectActor::Create(
                owner_->GetGame(), owner_->GetPosition() + Vector2{0,-64}, "SpaceKeyUI",
                150);
            NextBeacon();
          });
    }
  }
  void Update() override {
    if (end_) return;
    if (!start_) return;

    if (InputManager::Instance()->ActionFire()) {
      ma_tween::DummyTween::TweenDummy(owner_, 0.1f).SetOnComplete([this] {
        EventEnd();
      });
      return;
    }
    current_time_ += Speed();
    note_sprite_->SetOffset({width_ * current_time_, 0});
    flow_actor_->SetPosition(MOF_LERP(start_pos_, target_pos_, current_time_));

    if (current_time_ >= 1) {
      NextBeacon();
      return;
    }
    if (state_ != kNone) return;
    if (current_time_ > beat_point_ + tolerance_) {
      ClickFailed();
      return;
    }

    if (InputManager::Instance()->JumpFire()) {
      if ((current_time_ >= beat_point_ - tolerance_) &&
          (current_time_ <= beat_point_ + tolerance_)) {
        ClickSuccess();
        return;
      }
      ClickFailed();
    }
  }

 private:
  void NextBeacon() {
    if (const auto receiver =
            current_iterator_->lock()->GetComponent<ReceiverComponent>();
        !receiver.expired()) {
      receiver.lock()->FlowSparkEffect();
    }

    if ((current_iterator_ + 1) == chain_actor_.rend()) {

      target_beacon_->LevelUp();
      EventEnd();
      return;
    }
    ++current_iterator_;
    NoteSpawn();

    start_pos_ = (current_iterator_ - 1)->lock()->GetPosition();
    target_pos_ = (current_iterator_)->lock()->GetPosition();
    target_pos_ -= VectorUtilities::Normalize(target_pos_ - start_pos_) * 64;
    flow_sprite_->SetAngle(
        atan2(target_pos_.y - start_pos_.y, target_pos_.x - start_pos_.x));

    const auto length = VectorUtilities::Length(target_pos_ - start_pos_);
    speed_scale_ = 1 / (length / stage::kStageCellSize<float>.x);
  }

  void ClickSuccess() {
    state_ = kSuccess;
    OneTimeEffectActor::Create(owner_->GetGame(),
        beat_point_actor_->GetPosition() + Vector2{width_ * beat_point_,0},
                               "CriticalPointEffect", 230);
    speed_ *=
        (1.1f + (static_cast<float>(chain_actor_.size()) / 100.0f) * 2.0f);
  }
  void ClickFailed() {
    state_ = kFailed;
    ma_tween::ScaleTween::Tween(note_actor_, 2, 0.15f / ((Speed()) * 60.0f));
    ma_tween::SpriteAlphaTween::Tween(note_actor_, 0,
                                      0.15f / ((Speed()) * 60.0f))
        .SetOnComplete([this] {});
  }
  void NoteSpawn() {
    state_ = kNone;
    for (const auto& tween :
         note_actor_->GetComponents<ma_tween::core::ITween>()) {
      if (tween.expired()) continue;
      tween.lock()->Cancel();
    }
    note_sprite_->SetColor(MOF_ARGB(255, 255, 255, 255));
    note_actor_->SetScale(1);
    current_time_ = 0;
    note_sprite_->SetOffset({width_ * current_time_, 0});
  }
  void EventEnd() {
    std::any send = std::make_any<Actor*>(owner_);
    auto event = BeaconPowerUpActionEvent(send, true);
    EventBus::FireEvent(event);
    end_ = true;
    owner_->GetGame()->RemoveActor(flow_actor_);
    owner_->GetGame()->RemoveActor(space_key_effect_);
    {
      constexpr float up = -kSpawnY;
      constexpr float t = kAnimationTime;
      ma_tween::PositionYTween::TweenLocalPositionY(
          note_actor_, note_actor_->GetPosition().y + up, t)
          .SetEase(EaseType::kInquad);
      ma_tween::PositionYTween::TweenLocalPositionY(
          back_bar_actor_, back_bar_actor_->GetPosition().y + up, t)
          .SetEase(EaseType::kInquad);
      ma_tween::PositionYTween::TweenLocalPositionY(
          beat_point_actor_, beat_point_actor_->GetPosition().y + up, t)
          .SetEase(EaseType::kInquad);

      ma_tween::SpriteAlphaTween::Tween(note_actor_, 0, t)
          .SetEase(EaseType::kInoutexpo);
      ma_tween::SpriteAlphaTween::Tween(back_bar_actor_, 0, t)
          .SetEase(EaseType::kInoutexpo);
      ma_tween::SpriteAlphaTween::Tween(beat_point_actor_, 0, t)
          .SetEase(EaseType::kInoutexpo)
          .SetOnComplete([this] { owner_->GetGame()->RemoveActor(owner_); });
    }
  }
  SpriteComponent* CreateImage(
      const std::string_view name,
      const Mof::TextureAlignment alignment = Mof::TEXALIGN_CENTERLEFT) const {
    const auto actor = new Actor(owner_->GetGame());
    actor->SetPosition(owner_->GetPosition());
    const auto sprite = new SpriteComponent(actor, 220);
    sprite->SetImage(
        *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(name.data()));
    sprite->SetAlignment(alignment);
    return sprite;
  }
  float Speed() const {
    return (std::min)((std::min)(speed_, 2.0f) * block_per_second_ *
                          speed_scale_,
                      0.2f);
  }
  float width_ = 0;

  float beat_point_ = 0.75f;
  float tolerance_ = 0.05f;

  float speed_ = 1.0f;
  float speed_scale_ = 1.0f;
  float current_time_ = 0;

  static constexpr float block_per_second_ = 1.0f / 30.0f;
  enum { kNone, kSuccess, kFailed } state_ = kNone;
  bool end_ = false;
  bool start_ = false;

  SpriteComponent* back_bar_sprite_ = nullptr;
  Actor* back_bar_actor_ = nullptr;
  SpriteComponent* beat_point_sprite_ = nullptr;
  Actor* beat_point_actor_ = nullptr;

  SpriteComponent* note_sprite_ = nullptr;
  Actor* note_actor_ = nullptr;

  std::vector<std::weak_ptr<Actor>> chain_actor_{};
  std::vector<std::weak_ptr<Actor>>::reverse_iterator current_iterator_{};
  OneTimeEffectActor* space_key_effect_;
  OneTimeEffectActor* critical_effect_;
  Vector2 start_pos_;
  Vector2 target_pos_;
  Actor* flow_actor_ = nullptr;
  SpriteComponent* flow_sprite_ = nullptr;
  BeaconActor* target_beacon_ = nullptr;
};

BeaconPowerUpActor::BeaconPowerUpActor(Game* game) : Actor(game) {}

void BeaconPowerUpActor::Create(Actor* target) {
  auto pos = target->GetPosition();
  pos.y -= 64;
  SetPosition(pos);
  const auto action_component = new BeaconPowerUpActionComponent(this);
  action_component->Create(dynamic_cast<BeaconActor*>(target));
}
