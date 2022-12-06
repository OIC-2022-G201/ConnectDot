#pragma once

#include "Component.h"
#include "StateMachine.h"
#include "Enemy.h"
#include "EnemyIdle.h"
#include "EnemyChase2.h"
#include "EnemyBack.h"
#include "VisionCreateComponent.h"
#include "BaseBodyCreateComponent.h"

namespace enemy {
	class SecondEnemyComponent:public base_engine::Component
	{
		std::weak_ptr<base_engine::PhysicsBodyComponent> physics_body_;
		std::weak_ptr<base_engine::CollisionComponent> collision_;
		til::Machine<EnemyIdle, EnemyChase2, EnemyBack> machine_
					= til::Machine{ EnemyIdle{this}, EnemyChase2{this}, EnemyBack{this} };
		bool direction_ = Left;

	public:
		SecondEnemyComponent(base_engine::Actor* owner, int update_order)
			:Component(owner, update_order) {};
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void OnCollision(const base_engine::SendManifold& manifold) override;
		std::weak_ptr<base_engine::PhysicsBodyComponent> GetPhysicsBody() { return physics_body_; }
		std::weak_ptr<base_engine::CollisionComponent> GetCollision() { return collision_; }
		//false == Left, true == Right
		bool GetDirection() { return direction_; }
		void SetDirection(bool dir) { direction_ = dir; }
		void ReverseDirection() { direction_ = !direction_; }
		EnemyVisionComponent* GetVision() { return owner_->GetComponent<VisionCreateComponent>().lock()->GetParent()->GetComponent<EnemyVisionComponent>().lock().get(); }
	};
}