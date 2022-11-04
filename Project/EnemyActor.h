// @file EnemyActor.h
// @brief 
// @author ICE
// @date 2022/09/27
// 
// @details

#pragma once
#include "Actor.h"
class Strategy;
namespace enemy {
    class EnemyActor : public base_engine::Actor
    {
        class EnemyComponent* enemy_component_;
        class EnemyVisionActor* enemy_vision_;
    public:
        explicit EnemyActor(base_engine::Game* game);

        ~EnemyActor() override;

        void Start() override;

        void Update() override;

        static void Create();

    private:
    };
}