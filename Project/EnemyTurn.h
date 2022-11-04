#pragma once

#include "EnemyState.h"
#include "PhysicsBodyComponent.h"

namespace enemy {
	class EnemyTurn
	{
		class EnemyComponent* enemy_;
		std::weak_ptr<base_engine::PhysicsBodyComponent> body_;

		bool is_move_ = false;

	public:
		explicit EnemyTurn(EnemyComponent* enemy) :enemy_(enemy) {};
		void Start();
		void Update();
		void ProcessInput();
		void End();

		template<typename Machine>
		void Transition(Machine& machine)const
		{
			if (is_move_) machine.template TransitionTo<EnemyMove>();
		}
	};
}
