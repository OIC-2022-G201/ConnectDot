#pragma once
#include "Component.h"
#include "SendManifold.h"
#include "Rect.h"
#include  <memory>
class EnemyVisionComponent : public base_engine::Component
{
	bool is_find_ = false, is_change_ = false;
	base_engine::Actor* parent_;

	base_engine::CollisionComponent* collision_;
	std::shared_ptr<base_engine::Rect> find_rect_, chase_rect_;
	base_engine::ShapeRenderComponent* debug_render_;

public:
	explicit EnemyVisionComponent(base_engine::Actor* owner, int update_order) :Component(owner, update_order) {};
	~EnemyVisionComponent() {};
	void Start() override;
	void ProcessInput() override;
	void Update() override;
	void SetParent(base_engine::Actor* parent) { parent_ = parent; }
	void OnCollision(const base_engine::SendManifold& manifold) override;
	bool IsFindPlayer() { return is_find_; }
};

