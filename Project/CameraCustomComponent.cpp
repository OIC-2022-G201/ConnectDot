#include "CameraCustomComponent.h"

CameraCustomComponent::CameraCustomComponent(base_engine::Actor* owner):Component(owner) {
	offset_ = base_engine::Vector2{ 0, -64 - 32 };
}

void CameraCustomComponent::Update() {
	if (GetOwner().expired()) return;

	const auto actor = actor_weak_.lock();
	const auto actor_pos = inside_camera_room_ ? target_actor_pos_ : actor->GetPosition() + offset_;
	MoveCamera(actor_pos);
}

void CameraCustomComponent::MoveCamera(base_engine::Vector2 target_pos) {

	base_engine::Vector2 current_pos = owner_->GetPosition();
	base_engine::Vector2 targetDirection = (target_pos - current_pos);

	inside_camera_room_ = camera_room_.CollisionPoint(actor_weak_.lock()->GetPosition());
	if (inside_camera_room_) {
		target_actor_pos_ = target_pos;
	}

	float interp_velocity =
		base_engine::VectorUtilities::Length(targetDirection) * 5.0f;

	target_pos_ =
		current_pos + (base_engine::VectorUtilities::Normalize(targetDirection) *
			interp_velocity * 0.017f);

	auto move_pos = base_engine::Vector2{
		std::lerp(current_pos.x, target_pos_.x, 0.6f),
		std::lerp(current_pos.y, target_pos_.y,
				  current_pos.y > target_pos_.y ? 0.2f : 0.6f) };

	if (!camera_window_.CollisionPoint(move_pos)) {
		if (move_pos.x < camera_window_.Left) move_pos.x = camera_window_.Left;
		else if (move_pos.x > camera_window_.Right) move_pos.x = camera_window_.Right;
		if (move_pos.y < camera_window_.Top) move_pos.y = camera_window_.Top;
		else if (move_pos.y > camera_window_.Bottom) move_pos.y = camera_window_.Bottom;
	}

	owner_->SetPosition(move_pos);
}