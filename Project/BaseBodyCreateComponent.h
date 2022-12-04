#pragma once
#include "Component.h"

namespace enemy {
	class BaseBodyCreateComponent :public base_engine::Component
	{
		base_engine::Actor* parent_;

	public:
		BaseBodyCreateComponent(base_engine::Actor* owner, int update_order)
			:Component(owner, update_order) {};
		void Start() override;
		void Update() override;
		void ProcessInput() override;
		void OnCollision(const base_engine::SendManifold& manifold) override {};
		base_engine::Actor* GetParent() { return parent_; }
	};
}