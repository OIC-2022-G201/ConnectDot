#pragma once
#include "Component.h"
#include "SendManifold.h"
#include "Rect.h"
#include  <memory>

using namespace base_engine;

namespace enemy
{
	class EnemyVisionComponent : public Component
	{
		bool is_find_ = false, is_change_ = false, direction = false, prev_direction = false;
		int reverse_width_;
		Actor* vision_parent_;

		CollisionComponent* collision_;
		std::shared_ptr<Rect> find_rect_, chase_rect_;
		ShapeRenderComponent* debug_render_;
		Vector2 player_center_ = {0, 0};

	public:
		explicit EnemyVisionComponent(Actor* owner, int update_order) :Component(owner, update_order) {};
		~EnemyVisionComponent() override {};
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void SetParent(Actor* parent) { vision_parent_ = parent; }
		void OnCollision(const SendManifold& manifold) override;
		bool IsFindPlayer() { return is_find_; }
		Vector2 GetPlayerCenter() { return player_center_; }
		void SetFindRect(std::shared_ptr<Rect> rect) { find_rect_ = rect; }
		void SetChaseRect(std::shared_ptr<Rect> rect) { chase_rect_ = rect; }
		void SetReverseWidth(int width) { reverse_width_ = width; }
	};
}
