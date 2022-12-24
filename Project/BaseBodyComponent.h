#pragma once
#include "Component.h"
#include "EnemyNeck.h"

using namespace base_engine;

namespace enemy
{
	class BaseBodyComponent:public Component
	{
		Actor* parent_;
		EnemyNeck* neck_;

	public:
		BaseBodyComponent(Actor* owner, int update_order)
			:Component(owner, update_order) {};
		void Start() override;
		void Update() override;
		void ProcessInput() override;
		void OnCollision(const SendManifold& manifold) override;
		void SetParent(Actor* parent) { parent_ = parent; }
	};
}

