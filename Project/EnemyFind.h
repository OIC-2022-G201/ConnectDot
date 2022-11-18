#pragma once

#include "PhysicsBodyComponent.h"
#include "EnemyMove.h"

namespace enemy {
	class EnemyFind
	{
		class EnemyComponent* enemy_;
		std::weak_ptr<base_engine::PhysicsBodyComponent> body_;

	public:
		explicit EnemyFind(EnemyComponent* enemy) :enemy_(enemy) {};
		void Start();
		void Update();
		void ProcessInput();
		void OnEvent(base_engine::CollisionComponent* collision);
		void End();

		template <typename Machine>
		void Transition(Machine& machine) const;
	};

	template <typename Machine>
	void EnemyFind::Transition(Machine& machine) const
	{
		machine.template TransitionTo<EnemyChase>();
	}

}

