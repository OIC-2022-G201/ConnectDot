#include "EnemyActor.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "GridPosition.h"
#include "IBaseEngineTexture.h"
#include "SpriteComponent.h"
#include "TexturePaths.h"
#include "EnemyComponent.h"
#include "PhysicsBodyComponent.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ShapeRenderComponent.h"
#include "VisionCreateComponent.h"

using namespace base_engine;
using namespace draw_order;

namespace enemy {
    EnemyActor::EnemyActor(base_engine::Game* game) : Actor(game) {}

    EnemyActor::~EnemyActor() {}

    void EnemyActor::Start() {
        {
            const auto sprite = new SpriteComponent(this, kEnemyDrawOrder);
            sprite->SetImage(BASE_ENGINE(Texture)->Get(texture::kEnemyTextureKey));
            enemy_component_ = new enemy::EnemyComponent(this, 101);
            auto enemy_vision = new VisionCreateComponent(this, 102);
        }
        {
            auto body_ = new PhysicsBodyComponent(this);
            auto collision_ = new CollisionComponent(this);
            const auto shape_enemy = std::make_shared<Rect>(0, 0, 256, 256);
            collision_->SetShape(shape_enemy);
            collision_->SetObjectFilter(kEnemyObjectFilter);
            collision_->SetTargetFilter(kEnemyTargetFilter);

            auto debugCollisionRender = new ShapeRenderComponent(this, 501);
            debugCollisionRender->SetShape(shape_enemy);
            debugCollisionRender->SetColor(MOF_COLOR_RED);
        }

        SetName("Enemy");
        SetTag("Enemy");
        SetPosition(GridPosition::GridTo({ 9,6 }));
    }

    void EnemyActor::Update() {

    }

    void EnemyActor::Create() {}
}