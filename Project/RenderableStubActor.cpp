#include "RenderableStubActor.h"

#include "BaseEngineCore.h"
#include "CollisionComponent.h"
#include "DrawOrder.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LoadObjectParameter.h"
#include "MachineConst.h"
#include "SpriteComponent.h"
#include "TexturePaths.h"
using namespace base_engine;
using namespace electronics::signboard;
using namespace draw_order;
RenderableStubActor::RenderableStubActor(base_engine::Game* game)
    : Actor(game) {}

void RenderableStubActor::Create(const LoadObject& object) {
  {
    const auto sprite = new SpriteComponent(this, kStageOrder);
    const auto& path =
        std::get<LoadObject::TexturePath>(object.parameters[0]).value;

    sprite->SetImage(BASE_ENGINE(Texture)->Get(path));
  }
  {
    auto pos = std::get<LoadObject::Transform>(object.parameters[2]).value;
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::Yes).SetSnapGridPosition({pos.x, pos.y});
  }
  SetName("DoorStubActor");
}
