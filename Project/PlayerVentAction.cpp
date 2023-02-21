#include "PlayerVentAction.h"

#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "PlayerComponent.h"
#include "SpriteComponent.h"
#include "VentGroupLocator.h"
using namespace player;
constexpr size_t kMaxFrame = 38;

class VentCalcUtilities {
 public:
  static PlayerVentAction::VentDir CalcVentDir(const float horizontal) {
    if (horizontal == 0) return PlayerVentAction::VentDir::kNone;
    if (std::signbit(horizontal)) {
      return PlayerVentAction::VentDir::kPrev;
    }
    return PlayerVentAction::VentDir::kNext;
  }
  static base_engine::Vector2 CalcVentTargetPos(const VentComponent* vent,
                                                Mof::CRectangle clip) {
    return vent->GetGoInPosition() -
           base_engine::Vector2{clip.GetWidth() / 2, clip.GetHeight() / 2};
  }
};

PlayerVentAction::PlayerVentAction(PlayerComponent* player) {
  player_ = player;
}

void PlayerVentAction::Start() {
  if (action_type_ != VentActionType::kNone) return;
  collider_ = player_->GetCollision();
  collider_->SetObjectFilter(CollisionLayer::kNone);
  collider_->SetTrigger(true);
  player_->GetAnimator()->ChangeMotion("Join");

  physics_body_ = player_->PhysicsBody();
  vent_ = nullptr;
  end_ = false;
}

void PlayerVentAction::Update() {
  physics_body_->SetForce({0, 0});
  const auto horizontal = player_->GetHorizontal();

  switch (action_type_) {
    case VentActionType::kIn:
      InActionUpdate();
      break;
    case VentActionType::kOut:
      OutActionUpdate();
      break;
    case VentActionType::kStay:

      if (player_->IsActionKey()) {
        action_type_ = VentActionType::kOut;
        current_frame_ = 0;
        const auto sprite = player_->GetOwner()
                                ->GetComponent<base_engine::SpriteComponent>()
                                .lock();
        sprite->SetEnabled(true);
        player_->GetAnimator()->ChangeMotion("Leave");
        return;
      }
      {
        const auto horizontal = player_->GetHorizontal();
        if (const auto vent_to =
                GetVentMoveTo(VentCalcUtilities::CalcVentDir(horizontal));
            !vent_to.expired()) {
          VentMove(vent_to);
        }
      }

      break;
    case VentActionType::kNone:
    default:
      break;
  }
}

void PlayerVentAction::ProcessInput() {}

void PlayerVentAction::End() {
  if (action_type_ != VentActionType::kOut) return;

  collider_->SetObjectFilter(kPlayerObjectFilter);
  collider_->SetTrigger(false);
}

void PlayerVentAction::OnEvent(const VentComponent* const v) {
  if (action_type_ != VentActionType::kNone) return;
  vent_ = v;
  start_pos_ = player_->GetOwner()->GetPosition();
  const auto sprite =
      player_->GetOwner()->GetComponent<base_engine::SpriteComponent>().lock();
  const auto clip = sprite->GetClipRect();
  target_pos_ = VentCalcUtilities::CalcVentTargetPos(v, clip);
  action_type_ = VentActionType::kIn;
  current_frame_ = 0;

  if (start_pos_.x < target_pos_.x) {
    player_->LookAtRight();
  } else if (start_pos_.x > target_pos_.x) {
    player_->LookAtLeft();
  }
}

void PlayerVentAction::InActionUpdate() {
  ++current_frame_;
  if (current_frame_ >= kMaxFrame) {
    current_frame_ = kMaxFrame;
    action_type_ = VentActionType::kStay;
    const auto sprite = player_->GetOwner()
                            ->GetComponent<base_engine::SpriteComponent>()
                            .lock();
    sprite->SetEnabled(false);
  }
  const float t1 = static_cast<float>(current_frame_) / kMaxFrame;
  const float t2 = t1 * t1;

  player_->GetOwner()->SetPosition(
      Mof::CVector2Utilities::Lerp(start_pos_, target_pos_, t2));
}

void PlayerVentAction::OutActionUpdate() {
  ++current_frame_;
  if (current_frame_ >= kMaxFrame) {
    current_frame_ = kMaxFrame;
    action_type_ = VentActionType::kNone;
    end_ = true;
  }
}

std::weak_ptr<VentComponent> PlayerVentAction::GetVentMoveTo(
    VentDir dir) const {
  std::weak_ptr<base_engine::Actor> move_to;

  switch (dir) {
    case VentDir::kNone:
      break;
      return {};
    case VentDir::kPrev:
      move_to = vent_->GetLeft();
      break;
    case VentDir::kNext:
      move_to = vent_->GetRight();
      break;
    default:;
  }

  if (move_to.expired()) return {};
  return move_to.lock()->GetComponent<VentComponent>();
}

void PlayerVentAction::VentMove(const std::weak_ptr<VentComponent>& vent) {
  vent_ = vent.lock().get();
  const auto pre_pos = target_pos_;

  const auto sprite =
      player_->GetOwner()->GetComponent<base_engine::SpriteComponent>().lock();
  const auto clip = sprite->GetClipRect();
  target_pos_ = VentCalcUtilities::CalcVentTargetPos(vent_, clip);
  start_pos_ += target_pos_ - pre_pos;
  player_->GetOwner()->SetPosition(target_pos_);
}
