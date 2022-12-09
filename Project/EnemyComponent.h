#pragma once

#include "Component.h"
#include "StateMachine.h"
#include "EnemyMove.h"
#include "EnemyTurn.h"
#include "EnemyFind.h"
#include "EnemyChase.h"
#include "Enemy.h"
#include "VisionCreateComponent.h"

using namespace base_engine;

namespace enemy {
	class EnemyComponent : public Component {
		std::weak_ptr<PhysicsBodyComponent> physics_body_;
		std::weak_ptr<CollisionComponent> collision_;
		til::Machine<EnemyMove, EnemyTurn, EnemyFind, EnemyChase> machine_
					= til::Machine{ EnemyMove{this}, EnemyTurn{this}, EnemyFind{this}, EnemyChase{this} };
		bool direction = Left;

	public:
		EnemyComponent(Actor* owner, int update_order)
			:Component(owner, update_order) {}
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void OnCollision(const SendManifold& manifold) override;
		std::weak_ptr<PhysicsBodyComponent> PhysicsBody() { return physics_body_; }
		CollisionComponent* GetCollision() { return collision_.lock().get(); }
		//false == Left, true == Right
		bool GetDirection() { return direction; }
		void SetDirection(bool dir) { direction = dir; }
		void ReverseDirection() { direction = !direction; }
		EnemyVisionComponent* GetVision() { return owner_->GetComponent<VisionCreateComponent>().lock()->GetParent()->GetComponent<EnemyVisionComponent>().lock().get(); }
	};
}
