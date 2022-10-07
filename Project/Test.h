#pragma once
#include "Actor.h"
class Strategy;
class Test final : public base_engine::Actor
{
public:
		explicit Test(base_engine::Game* game);

		~Test() override;

		void Start() override;

		void Update() override;

private:
	int kaki = 1;
};
