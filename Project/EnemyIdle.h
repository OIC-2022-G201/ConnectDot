#pragma once

#include "EnemyState.h"
#include "PhysicsBodyComponent.h"
#include "EnemyVisionComponent.h"
namespace enemy {
	class EnemyIdle
	{
		class SecondEnemyComponent* enemy_;
		std::weak_ptr<base_engine::PhysicsBodyComponent> body_;
		EnemyVisionComponent* vision_ = nullptr;
		bool is_find_ = false;

	public:
		explicit EnemyIdle(SecondEnemyComponent* enemy) :enemy_(enemy) {};
		void Start();
		void Update();
		void ProcessInput();
		void OnEvent(base_engine::CollisionComponent* collision);
		void End();

		template<typename Machine>
		void Transition(Machine& machine) const;
	};

	template<typename Machine>
	void EnemyIdle::Transition(Machine& machine) const
	{
		if (is_find_) machine.template TransitionTo<EnemyChase2>();
	}
}