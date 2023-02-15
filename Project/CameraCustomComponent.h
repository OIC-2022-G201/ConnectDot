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
	base_engine::Rect camera_room_ = base_engine::Rect(1000,0, 2000, 2000);
	base_engine::Rect camera_window_ = base_engine::Rect(-200, -300, 200, 10);
	base_engine::Vector2 targetDirection;

	void MoveCamera();
	base_engine::Vector2 CalcuDirection(bool inside_x,bool inside_y);
};