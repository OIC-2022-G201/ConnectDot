#pragma once

#include "EnemyState.h"
#include "PhysicsBodyComponent.h"
#include "EnemyVisionComponent.h"

namespace enemy {
	class EnemyMove {
		class EnemyComponent* enemy_;
		EnemyVisionComponent* vision_ = nullptr;
		std::weak_ptr<base_engine::PhysicsBodyComponent> body_;
		bool is_find_ = false;
		bool is_turn_ = false;

	public:
		explicit EnemyMove(EnemyComponent* enemy) :enemy_(enemy) {};
		void Start();
		void Update();
		void ProcessInput();
		void OnEvent(base_engine::CollisionComponent* collision);
		void End();

		void SetVisionComponent(EnemyVisionComponent* vision) { vision_ = vision; }

		template <typename Machine>
		void Transition(Machine& machine) const;
		
	};

	template<typename Machine>
	void enemy::EnemyMove::Transition(Machine& machine) const {
		if (is_find_) machine.template TransitionTo<EnemyFind>();
		if (is_turn_) machine.template TransitionTo<EnemyTurn>();
	}
}