#pragma once
#include "Component.h"
#include "Rect.h"
class CameraCustomComponent final : public base_engine::Component
{
	base_engine::ActorWeakPtr actor_weak_;
	base_engine::Vector2 offset_;
	base_engine::Vector2 target_pos_;

public:
	CameraCustomComponent(base_engine::Actor* owner);
	void Update() override;

	void BindTarget(const base_engine::ActorWeakPtr& weak_ptr) { actor_weak_ = weak_ptr; }
private:
	base_engine::Rect camera_window_ = base_engine::Rect(-50, -50, 4000, 2000);
	base_engine::Rect camera_room_ = base_engine::Rect(2000, -50, 3000, 2000);
	bool inside_camera_room_;
	base_engine::Vector2 target_actor_pos_;

	void MoveCamera(base_engine::Vector2 target_pos);
};