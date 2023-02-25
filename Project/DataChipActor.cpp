#include "DataChipActor.h"

#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "GridSnapComponent.h"
#include "Rect.h"
#include "ResourceContainer.h"
#include "ResultModel.h"
#include "SpriteComponent.h"

using namespace base_engine;
void DataChipActor::Create(const LoadObject& object) {
  {
    constexpr auto cell = stage::kStageCellSize<base_engine::Floating>;
    const auto rect = std::make_shared<Rect>(0, 0, cell.x, cell.y * 2);

    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kChipObjectFilter);
    collision->SetTargetFilter(kChipTargetFilter);
    collision->SetTrigger(true);
  }
  {
    const auto sprite = new SpriteComponent(this);
    using RC = ResourceContainer;
    const auto image =
        *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("DataChip");
    sprite->SetImage(image);
  }
  {
	  new DataChipComponent(this);
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
  }
  SetName("DataChip");
  SetTag("Item");
}

void DataChipActor::Start() {}

void DataChipActor::Input() {}

void DataChipActor::Update() {}

void DataChipComponent::Start() {}

void DataChipComponent::OnCollision(const base_engine::SendManifold& manifold) {
  if (manifold.collision_b->GetActor()->GetTag() == "Player") {
    ComponentServiceLocator::Instance()
        .Resolve<ResultModel>()
        ->SetPicUpDataChip(true);
    owner_->GetGame()->RemoveActor(owner_);
  }
}
