#pragma once
#include "Actor.h"
#include "Rect.h"

namespace enemy {
	class EnemyVisionActor : public base_engine::Actor
	{
	public:
		explicit EnemyVisionActor(base_engine::Game* game);
		~EnemyVisionActor() override;
		void Start() override;
		void Update() override;
	};
}

