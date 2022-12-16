#pragma once
#include "Game.h"
#include "ISceneFactory.h"

namespace scene
{
	constexpr std::string_view kInvader = "Invader";
}

class InvaderSceneFactory :public ISceneFactory
{
public:
  explicit InvaderSceneFactory(base_engine::Game* game) : game_(game) {}

	void Factory() override;

private:
        base_engine::Game* game_ = nullptr;
};
