#pragma once
#include "Component.h"
#include "SendManifold.h"
#include "Rect.h"
#include  <memory>

namespace enemy
{
	class EnemyVisionComponent : public base_engine::Component
	{
		bool is_find_ = false, is_change_ = false, direction = false, prev_direction = false;
		int reverse_width_;
		base_engine::Actor* parent_;

		base_engine::CollisionComponent* collision_;
		std::shared_ptr<base_engine::Rect> find_rect_, chase_rect_;
		base_engine::ShapeRenderComponent* debug_render_;
		base_engine::Vector2 player_center_ = {0, 0};

	public:
		explicit EnemyVisionComponent(base_engine::Actor* owner, int update_order) :Component(owner, update_order) {};
		~EnemyVisionComponent() {};
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void SetParent(base_engine::Actor* parent) { parent_ = parent; }
		void OnCollision(const base_engine::SendManifold& manifold) override;
		bool IsFindPlayer() { return is_find_; }
		base_engine::Vector2 GetPlayerCenter() { return player_center_; }
		void SetFindRect(std::shared_ptr<base_engine::Rect> rect) { find_rect_ = rect; }
		void SetChaseRect(std::shared_ptr<base_engine::Rect> rect) { chase_rect_ = rect; }
		void SetReverseWidth(int width) { reverse_width_ = width; }
	};
}
