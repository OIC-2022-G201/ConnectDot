#pragma once
#include "Actor.h"

class testActor : public base_engine::Actor {
public:
	explicit testActor(base_engine::Game* game);	//explicit�͈Öق̌^�ϊ����N���Ȃ��Ȃ�
	~testActor() override;
	void Start() override;
	void Update() override;
};

