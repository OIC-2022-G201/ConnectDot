#pragma once
#include "Component.h"

namespace enemy
{
	class BaseBodyComponent:public base_engine::Component
	{
		base_engine::Actor* parent_;


	public:
		BaseBodyComponent(base_engine::Actor* owner, int update_order)
			:Component(owner, update_order) {};
		void Start() override;
		void Update() override;
		void ProcessInput() override;
		void OnCollision(const base_engine::SendManifold& manifold) override;
		void SetParent(base_engine::Actor* parent) { parent_ = parent; }
	};
}

