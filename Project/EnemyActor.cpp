#include "EnemyActor.h"

#include "BaseEngineCore.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "EnemyComponent.h"
#include "EnemyMoveRail.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "MofSpriteAnimationComponent.h"
#include "PhysicsBodyComponent.h"
#include "ReleaseInfo.h"
#include "ResourceContainer.h"
#include "SecondEnemyComponent.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"
#include "TexturePaths.h"
#include "VisionCreateComponent.h"

using namespace base_engine;
using namespace draw_order;

namespace enemy {
EnemyActor::EnemyActor(Game* game) : Actor(game) {}

EnemyActor::~EnemyActor() {}

void EnemyActor::Start() {}

void EnemyActor::Update() {}

void EnemyActor::Create(const LoadObject& object) {
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
  }

  {
    using RC = ResourceContainer;
    const auto image =
        *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("Enemy");
    const auto sprite = new SpriteComponent(this);
    sprite->SetImage(image);
  }
  for (auto& part : object.object.parts) {
    if (const auto route_part = std::get_if<stage::part::RoutePart>(&part)) {
      const auto move = new EnemyMoveRail(this);
      move->SetRoute(route_part->Route());
      move->SetType(route_part->RouteType());
    }
  }
  {
    const auto collision = new CollisionComponent(this);
    const auto shape_enemy = std::make_shared<Rect>(0,0,128,128);
    collision->SetShape(shape_enemy);
    collision->SetObjectFilter(kEnemyObjectFilter);
    collision->SetTargetFilter(kEnemyTargetFilter);
    collision->SetTrigger(true);
    if (kIsCollisionRenderMode) {
      const auto debug_collision_render = new ShapeRenderComponent(this, 500);
      debug_collision_render->SetShape(shape_enemy);
      debug_collision_render->SetColor(MOF_COLOR_GREEN);
    }
  }
  SetName("Enemy");
  SetTag("Enemy");
}
}  // namespace enemy