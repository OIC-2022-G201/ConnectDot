﻿// @file EnemyActor.h
// @brief 
// @author ICE
// @date 2022/09/27
// 
// @details

#pragma once
#include "Actor.h"
class Strategy;
class EnemyActor : public base_engine::Actor
{
public:
    explicit EnemyActor(base_engine::Game* game);

    ~EnemyActor() override;

    void Start() override;

    void Update() override;

    static void Create();

private:
};