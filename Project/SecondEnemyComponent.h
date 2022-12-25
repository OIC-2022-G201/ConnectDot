#pragma once

#include "Component.h"
#include "StateMachine.h"
#include "Enemy.h"
#include "EnemyIdle.h"
#include "EnemyChase2.h"
#include "EnemyBack.h"
#include "VisionCreateComponent.h"
#include "BaseBodyCreateComponent.h"
#include "SpriteComponent.h"

using namespace base_engine;

namespace enemy {
	class SecondEnemyComponent:public Component
	{
		std::weak_ptr<PhysicsBodyComponent> physics_body_;
		std::weak_ptr<CollisionComponent> collision_;
		til::Machine<EnemyIdle, EnemyChase2, EnemyBack> machine_
					= til::Machine{ EnemyIdle{this}, EnemyChase2{this}, EnemyBack{this} };
		bool direction_ = Left;
		BaseBodyCreateComponent* base_body_;
		std::weak_ptr<SpriteComponent> sprite_;

	public:
		SecondEnemyComponent(Actor* owner, int update_order)
			:Component(owner, update_order) {};
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void OnCollision(const SendManifold& manifold) override;
		std::weak_ptr<PhysicsBodyComponent> GetPhysicsBody() { return physics_body_; }
		std::weak_ptr<CollisionComponent> GetCollision() { return collision_; }
		//false == Left, true == Right
		bool GetDirection() { return direction_; }
		void SetDirection(bool dir) { direction_ = dir; }
		void ReverseDirection() { direction_ = !direction_; }
		EnemyVisionComponent* GetVision() { return owner_->GetComponent<VisionCreateComponent>().lock()->GetVisionParent()->GetComponent<EnemyVisionComponent>().lock().get(); }
		Actor* GetBodyActor() { return base_body_->GetBodyParent(); }
		SpriteComponent* GetSprite() { return sprite_.lock().get(); }
	};
}