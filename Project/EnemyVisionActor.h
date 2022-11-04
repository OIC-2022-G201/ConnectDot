#pragma once
#include "Actor.h"

#include "CollisionComponent.h"
#include "ShapeRenderComponent.h"
#include "Rect.h"
namespace enemy {
	class EnemyVisionActor : base_engine::Actor
	{
		base_engine::Actor* parent_ = nullptr;
		base_engine::CollisionComponent* collision_;
		base_engine::ShapeRenderComponent* debug_render_;
		std::shared_ptr<base_engine::Rect> find_rect_, chase_rect_;
	public:
		explicit EnemyVisionActor(base_engine::Game* game);
		~EnemyVisionActor() override;
		void Start() override;
		void Update() override;

		void SetParent(base_engine::Actor* parent) { parent_ = parent; }
	};
}

