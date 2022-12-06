#pragma once
#include "Actor.h"

namespace enemy {
	class DummyActor : public base_engine::Actor
	{
	public:
		explicit DummyActor(base_engine::Game* game);
		~DummyActor() override;
		void Start() override;
		void Update() override;
	};
}

