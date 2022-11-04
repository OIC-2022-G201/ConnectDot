#pragma once
#include "Component.h"
#include "StateMachine.h"
#include "PhysicsBodyComponent.h"
#include "EnemyMove.h"
#include "EnemyTurn.h"

namespace enemy {
	class EnemyComponent : base_engine::Component {
		std::weak_ptr<base_engine::PhysicsBodyComponent> physics_body_;
		std::weak_ptr<base_engine::CollisionComponent> collision_;
		til::Machine<EnemyMove, EnemyTurn> machine_ = til::Machine{ EnemyMove{this}, EnemyTurn{this} };

	public:
		EnemyComponent(base_engine::Actor* owner, int update_order)
			:Component(owner, update_order) {}
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void OnCollision(const base_engine::SendManifold& manifold) override;
		std::weak_ptr<base_engine::PhysicsBodyComponent> PhysicsBody() { return physics_body_; }
		base_engine::CollisionComponent* GetCollision() { return collision_.lock().get(); }
		void SetFindState() { machine_.TransitionTo<EnemyTurn>(); }////////////////////////////////////////////////////////////////////////////
	};
}
