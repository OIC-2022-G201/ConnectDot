#include "EnemyComponent.h"

namespace enemy {
	void EnemyComponent::Start() {
		physics_body_ = owner_->GetComponent<base_engine::PhysicsBodyComponent>();
		collision_ = owner_->GetComponent<base_engine::CollisionComponent>();
		machine_.TransitionTo<EnemyMove>();
	}

	void EnemyComponent::ProcessInput() {
		machine_.ProcessInput();
	}

	void EnemyComponent::Update() {
		machine_.Update();
	}

	void EnemyComponent::OnCollision(const base_engine::SendManifold& manifold) {
		machine_.OnEvent(manifold.collision_b);
	}
}