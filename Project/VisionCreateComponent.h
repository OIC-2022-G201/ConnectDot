#pragma once
#include <memory>

#include "Component.h"
#include"EnemyVisionActor.h"
namespace enemy
{
	class VisionCreateComponent final : public base_engine::Component
	{
		std::weak_ptr<base_engine::CollisionComponent> collision_;
		EnemyVisionActor* dummy;
	public:
		VisionCreateComponent(base_engine::Actor* owner_, int update_order_) :Component(owner_, update_order_) {};
		~VisionCreateComponent() {};
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void OnCollision(const base_engine::SendManifold& manifold) override;
	};
}
