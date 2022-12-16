#pragma once

#include "Actor.h"
#include "SpriteComponent.h"

using namespace base_engine;
namespace enemy
{
	class EnemyNeck:public Actor
	{
		SpriteComponent* sprite_;
		Vector2 head_pos_ = { 0,0 };
		Vector2 body_pos_ = { 0,0 };
	public:
		explicit EnemyNeck(Game* game) :Actor(game) {};
		void Start() override;
		void Update() override;
		void SetHeadPosition(Vector2 head) { head_pos_ = head; }
		void SetBodyPosition(Vector2 body) { body_pos_ = body; }
	};
}