﻿#include "EnemyActor.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "SpriteComponent.h"
#include "TexturePaths.h"
#include "EnemyComponent.h"
#include "SecondEnemyComponent.h"
#include "PhysicsBodyComponent.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ShapeRenderComponent.h"
#include "VisionCreateComponent.h"
#include "MofSpriteAnimationComponent.h"
#include "ReleaseInfo.h"

using namespace base_engine;
using namespace draw_order;

namespace enemy {
    EnemyActor::EnemyActor(Game* game) : Actor(game) {}

    EnemyActor::~EnemyActor() {

    }

    void EnemyActor::Start() {

    }

    void EnemyActor::Update() {

    }

    void EnemyActor::Create(const LoadObject& object)
    {
        const auto sprite = new SpriteComponent(this, kEnemyDrawOrder);
        const auto animation = new MofSpriteAnimationComponent(this);
        const auto enemy_vision_ = new VisionCreateComponent(this, 102);

        int type_number_ = std::get<int>(object.parameters[2]);

        if (type_number_ == 1) 
            const auto enemy_component_ = new SecondEnemyComponent(this, 101);
        else
            const auto enemy_component_ = new EnemyComponent(this, 101);
        
        const auto collision_ = new CollisionComponent(this);
        collision_->SetObjectFilter(kEnemyObjectFilter);
        collision_->SetTargetFilter(kEnemyTargetFilter);
        collision_->SetShape(std::make_shared<Rect>(0, 0, 256, 256));

        if (kIsCollisionRenderMode)
        {
            const auto debugCollisionRender = new ShapeRenderComponent(this, 200);
            debugCollisionRender->SetColor(MOF_COLOR_RED);
        }
        const auto body_ = new PhysicsBodyComponent(this);

        auto pos = std::get<LoadObject::Transform>(object.parameters[1]).value;
        const auto grid = new grid::GridSnapComponent(this);
        grid->SetAutoSnap(grid::AutoSnap::No).SetSnapGridPosition({ pos.x, pos.y });

        SetName("Enemy");
        SetTag("Enemy");
    }
}