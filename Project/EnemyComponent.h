#pragma once

#include "Component.h"
#include "StateMachine.h"
#include "PhysicsBodyComponent.h"
#include "EnemyMove.h"
#include "EnemyTurn.h"
#include "EnemyFind.h"
#include "EnemyChase.h"
#include "Enemy.h"

namespace enemy {
	class EnemyComponent : public base_engine::Component {
		std::weak_ptr<base_engine::PhysicsBodyComponent> physics_body_;
		std::weak_ptr<base_engine::CollisionComponent> collision_;
		til::Machine<EnemyMove, EnemyTurn, EnemyFind, EnemyChase> machine_
					= til::Machine{ EnemyMove{this}, EnemyTurn{this}, EnemyFind{this}, EnemyChase{this} };
		bool direction = Left;

	public:
		EnemyComponent(base_engine::Actor* owner, int update_order)
			:Component(owner, update_order) {}
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void OnCollision(const base_engine::SendManifold& manifold) override;
		std::weak_ptr<base_engine::PhysicsBodyComponent> PhysicsBody() { return physics_body_; }
		base_engine::CollisionComponent* GetCollision() { return collision_.lock().get(); }
		til::Machine<EnemyMove, EnemyTurn, EnemyFind, EnemyChase>* GetMachine() { return &machine_; }
		bool GetDirection() { return direction; }
		void SetDirection(bool dir) { direction = dir; }
		void ReverseDirection() { direction = !direction; }
	};
}
