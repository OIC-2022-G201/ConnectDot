#include "DataChipActor.h"

#include "GridSnapComponent.h"
#include "Rect.h"

using namespace base_engine;
void DataChipActor::Create(const LoadObject& object)
{
  {
    constexpr auto cell = stage::kStageCellSize<base_engine::Floating>;
    const auto rect = std::make_shared<base_engine::Rect>(0, 0, cell.x, cell.y * 2);

    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kFieldObjectFilter);
    collision->SetTargetFilter(kFieldTargetFilter);
    collision->SetTrigger(false);
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
  }
  SetName("DataChip");
  SetTag("Field");
}

void DataChipActor::Start() {

}

void DataChipActor::Input() {
	
}

void DataChipActor::Update() {
	
}
