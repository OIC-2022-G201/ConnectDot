#pragma once

#include "EnemyState.h"
#include "PhysicsBodyComponent.h"
#include "EnemyVisionComponent.h"
#include "SpriteComponent.h"
namespace enemy {
	class EnemyBack
	{
		class SecondEnemyComponent* enemy_;
		std::weak_ptr<PhysicsBodyComponent> body_;
		EnemyVisionComponent* vision_ = nullptr;
		SpriteComponent* sprite_ = nullptr;
		bool is_arrive_ = false, is_find_ = false;

	public:
		explicit EnemyBack(SecondEnemyComponent* enemy) :enemy_(enemy) {};
		void Start();
		void Update();
		void ProcessInput();
		void OnEvent(CollisionComponent* collision);
		void End();

		template<typename Machine>
		void Transition(Machine& machine) const;
	};

	template<typename Machine>
	void EnemyBack::Transition(Machine& machine) const
	{
		if (is_arrive_) machine.template TransitionTo<EnemyIdle>();
		if (is_find_) machine.template TransitionTo<EnemyChase2>();
	}
}

