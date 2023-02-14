#include "CameraCustomComponent.h"

CameraCustomComponent::CameraCustomComponent(base_engine::Actor* owner):Component(owner) {
	offset_ = base_engine::Vector2{ 0, -64 - 32 };
}

void CameraCustomComponent::Update() {
	if (GetOwner().expired()) return;
	MoveCamera();
}

void CameraCustomComponent::MoveCamera() {
	const auto actor = actor_weak_.lock();
	const auto actor_pos = actor->GetPosition() + offset_;
	base_engine::Vector2 current_pos = owner_->GetPosition();
	targetDirection = (actor_pos - current_pos);

	bool inside_x = (targetDirection.x > camera_window_.Left && targetDirection.x < camera_window_.Right);
	bool inside_y = (targetDirection.y > camera_window_.Top && targetDirection.y < camera_window_.Bottom);

	if (inside_x && inside_y) return;

	const float interp_velocity =
		base_engine::VectorUtilities::Length(CalcuDirection(inside_x, inside_y)) * 5.0f;

	target_pos_ =
		current_pos + (base_engine::VectorUtilities::Normalize(targetDirection) *
			interp_velocity * 0.017f);

	auto move_pos = base_engine::Vector2{
		std::lerp(current_pos.x, target_pos_.x, 0.6f),
		std::lerp(current_pos.y, target_pos_.y,
				  current_pos.y > target_pos_.y ? 0.2f : 0.6f) };

	if (!camera_room_.CollisionPoint(move_pos)) {
		if (move_pos.x < camera_room_.Left) move_pos.x = camera_room_.Left;
		else if (move_pos.x > camera_room_.Right) move_pos.x = camera_room_.Right;
		if (move_pos.y < camera_room_.Top) move_pos.y = camera_room_.Top;
		else if (move_pos.y > camera_room_.Bottom) move_pos.y = camera_room_.Bottom;
	}

	owner_->SetPosition(move_pos);
}

base_engine::Vector2 CameraCustomComponent::CalcuDirection(bool inside_x, bool inside_y) {
	base_engine::Vector2 dir = base_engine::Vector2(0, 0);
	if (!inside_x) {
		if (targetDirection.x < camera_window_.Left) {
			dir.x = targetDirection.x - camera_window_.Left;
		}
		else if(targetDirection.x > camera_window_.Right){
			dir.x = targetDirection.x - camera_window_.Right;
		}
	}
	if (!inside_y) {
		if (targetDirection.y < camera_window_.Top) {
			dir.y = targetDirection.y - camera_window_.Top;
		}
		else if (targetDirection.x > camera_window_.Bottom) {
			dir.y = targetDirection.y - camera_window_.Bottom;
		}
	}
	return dir;
}