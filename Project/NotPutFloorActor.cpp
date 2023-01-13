#include "NotPutFloorActor.h"

#include "GridSnapComponent.h"
#include "Rect.h"
#include "ReleaseInfo.h"
#include "ShapeRenderComponent.h"
#include "ComponentServiceLocator.h"
#include "ObjectTileMapComponent.h"
#include "ShapeRenderComponent.h"

using namespace base_engine;

void NotPutFloorActor::Create(const LoadObject& object)
{

    if(true/*kIsCollisionRenderMode*/)
    {
    	constexpr auto cell = stage::kStageCellSize<Floating>;
        const auto rect = std::make_shared<Rect>(0, 0, cell.x, cell.y);
        auto render = new ShapeRenderComponent(this, 110);
        render->SetShape(rect);
        render->SetColor(MOF_COLOR_YELLOW);
        render->SetFillMode(FillMode::No);

    }

    auto pos = std::get<LoadObject::Transform>(object.parameters[1]).value;
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::Yes).SetSnapGridPosition({ pos.x, pos.y });

    auto map = ComponentServiceLocator::Instance().Resolve<tile_map::ObjectTileMapComponent>();
    map->SetCell(pos.x, pos.y, tile_map::kNotPutCell);

    SetName("NotPutFloorActor");
}
