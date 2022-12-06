#pragma once

#include "EnemyState.h"
#include "PhysicsBodyComponent.h"
#include "EnemyVisionComponent.h"

namespace enemy
{
	class EnemyChase
	{
		class EnemyComponent* enemy_;
		EnemyVisionComponent* vision_ = nullptr;
		std::weak_ptr<base_engine::PhysicsBodyComponent> body_;
		bool is_find_ = true;

	public:
		explicit EnemyChase(EnemyComponent* enemy) :enemy_(enemy) {};
		void Start();
		void Update();
		void ProcessInput();
		void OnEvent(base_engine::CollisionComponent* collision);
		void End();

		template <typename Machine>
		void Transition(Machine& machine) const;

	};

	template<typename Machine>
	void EnemyChase::Transition(Machine& machine) const {
		if (!is_find_) machine.template TransitionTo<EnemyMove>();
	}
}