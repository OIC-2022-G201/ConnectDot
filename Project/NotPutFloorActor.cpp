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

    if(kIsCollisionRenderMode)
    {
    	constexpr auto cell = stage::kStageCellSize<Floating>;
        const auto rect = std::make_shared<Rect>(0, 0, cell.x, cell.y);
        auto render = new ShapeRenderComponent(this, 110);
        render->SetShape(rect);
        render->SetColor(MOF_COLOR_YELLOW);
        render->SetFillMode(FillMode::No);

    }


    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::Yes)
        .SetSnapGridPosition({object.object.x, object.object.y});

    auto map = ComponentServiceLocator::Instance().Resolve<tile_map::ObjectTileMapComponent>();
    map->SetCell(object.object.x, object.object.y, tile_map::kNotPutCell);

    SetName("NotPutFloorActor");
}
