#pragma once

#include "EnemyState.h"
#include "PhysicsBodyComponent.h"

namespace enemy {
	class EnemyMove {
		class EnemyComponent* enemy_;
		std::weak_ptr<base_engine::PhysicsBodyComponent> body_;
		bool is_find_ = false;
		bool is_turn_ = false;
		std::shared_ptr<base_engine::Rect> find_rect_;

		int direction = 1;

	public:
		explicit EnemyMove(EnemyComponent* enemy) :enemy_(enemy) {};
		void Start();
		void Update();
		void ProcessInput();
		void OnEvent(base_engine::CollisionComponent* collision);
		void End();

		template <typename Machine>
		void Transition(Machine& machine) const;
	};

	template<typename Machine>
	void enemy::EnemyMove::Transition(Machine& machine) const {
		//if(is_find_) machine.template TransitionTo<EnemyFind>;
		if (is_turn_) machine.template TransitionTo<EnemyTurn>();
	}
}