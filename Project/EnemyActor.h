// @file EnemyActor.h
// @brief 
// @author ICE
// @date 2022/09/27
// 
// @details

#pragma once
#include "Actor.h"
#include "LoadObjectParameter.h"

class Strategy;
namespace enemy {
    class EnemyActor : public base_engine::Actor
    {
    public:
        explicit EnemyActor(base_engine::Game* game);

        ~EnemyActor() override;

        void Start() override;

        void Update() override;

        void Create(const LoadObject& object);

    private:
    };
}