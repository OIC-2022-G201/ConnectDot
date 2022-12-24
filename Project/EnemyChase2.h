#pragma once

#include "EnemyState.h"
#include "PhysicsBodyComponent.h"
#include "EnemyVisionComponent.h"
#include "SpriteComponent.h"

namespace enemy {
	class EnemyChase2
	{
		class SecondEnemyComponent* enemy_;
		std::weak_ptr<PhysicsBodyComponent> body_;
		EnemyVisionComponent* vision_ = nullptr;
		SpriteComponent* sprite_;
		bool is_find_ = true;

	public:
		explicit EnemyChase2(SecondEnemyComponent* enemy) :enemy_(enemy) {};
		void Start();
		void Update();
		void ProcessInput();
		void OnEvent(CollisionComponent* collision);
		void End();

		template<typename Machine>
		void Transition(Machine& machine) const;
	};

	template<typename Machine>
	void EnemyChase2::Transition(Machine& machine) const
	{
		if (!is_find_) machine.template TransitionTo<EnemyBack>();
	}
}
