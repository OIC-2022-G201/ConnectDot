#pragma once
#include "Component.h"

using namespace base_engine;

namespace enemy {
	class BaseBodyCreateComponent :public Component
	{
		Actor* body_parent_;

	public:
		BaseBodyCreateComponent(Actor* owner, int update_order)
			:Component(owner, update_order) {};
		void Start() override;
		void Update() override;
		void ProcessInput() override;
		void OnCollision(const SendManifold& manifold) override {};
		Actor* GetBodyParent() { return body_parent_; }
	};
}