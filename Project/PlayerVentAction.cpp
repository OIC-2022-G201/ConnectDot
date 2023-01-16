#include "PlayerVentAction.h"

#include "CollisionLayer.h"
#include "PlayerComponent.h"
#include "SpriteComponent.h"
using namespace player;
constexpr size_t kMaxFrame = 38;
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

  end_ = false;
}

void PlayerVentAction::Update() {
  physics_body_->SetForce({0, 0});
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
  start_pos_ = player_->GetOwner()->GetPosition();
  const auto sprite =
      player_->GetOwner()->GetComponent<base_engine::SpriteComponent>().lock();
  const auto clip = sprite->GetClipRect();
  target_pos_ = v->GetGoInPosition() -
                base_engine::Vector2{clip.GetWidth() / 2, clip.GetHeight() / 2};
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

  const float t1 = static_cast<float>(current_frame_) / kMaxFrame;
  const float t2 = -(t1 * t1) + 2 * t1;

  //player_->GetOwner()->SetPosition(Mof::CVector2Utilities::Lerp(
  //    target_pos_, target_pos_ + Mof::Vector2{100, 0}, t2));
}
