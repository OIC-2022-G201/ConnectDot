#include "MoveFloorStubActor.h"

#include "BaseEngineCore.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LeverStubReceiver.h"
#include "LoadObjectParameter.h"
#include "MachineConst.h"
#include "ObjectTileMapComponent.h"
#include "ReceiverComponent.h"
#include "ReleaseInfo.h"
#include "SignboardReceiver.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace base_engine;
using namespace draw_order;

void MoveFloorStubActor::Create(const LoadObject& object) {
  {
    constexpr auto cell = stage::kStageCellSize<Floating>;
    const auto rect = std::make_shared<Rect>(0, 0, cell.x, cell.y);
    if (kIsCollisionRenderMode) {
      const auto shape = new ShapeRenderComponent(this, 110);
      shape->SetShape(rect);
      shape->SetFillMode(electronics::kElectricAreaFillMode)
          .SetColor(electronics::kElectricAreaColor);
    }
    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kMoveFloorObjectFilter);
    collision->SetTargetFilter(kMoveFloorTargetFilter);
    collision->SetTrigger(false);
  }
  {
    const auto sign = new SpriteComponent(this, kSignboardDrawOrder);
    const auto path = "gimmick/Objects/Movefloor/Movefloor.png";
    sign->SetImage(BASE_ENGINE(Texture)->Get(path));
  }
  {
    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<MoveFloorStubReceiver>(this);
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
    from_position_ = {object.object.x, object.object.y};

    for (auto& part : object.object.parts) {
      auto t = std::get_if<stage::part::TransitionPointPart>(&part);
      if (t) {
        to_position_ = t->GetPos();
        break;
      }
    }
    SetTag("Field");
    SetName("MoveFloor");
  }
  ComponentServiceLocator::Instance()
      .Resolve<tile_map::ObjectTileMapComponent>()
      ->SetCell(from_position_, tile_map::kCanOnPlace);
}

void MoveFloorStubActor::MoveFloorStubReceiver::OnPowerEnter(
    TransmitterComponent* transmitter) {
  const auto grid = actor_->GetComponent<grid::GridSnapComponent>().lock();
  const auto now_pos = grid->GetSnapGridPosition();
  const auto from_pos = actor_->from_position_;
  const auto to_pos = from_pos + actor_->to_position_;

  ComponentServiceLocator::Instance()
      .Resolve<tile_map::ObjectTileMapComponent>()
      ->SetCell(now_pos, tile_map::kEmptyCell);
  const auto v = to_pos - from_pos;
  const auto normal =
      (abs(v.x) > abs(v.y) ? GridPosition{1, 0} : GridPosition{0, 1}) *
      ((v.x > 0) || (v.y > 0) ? 1 : -1);

  const auto move_pos =
      actor_->is_front_ ? (now_pos + normal) : (now_pos - normal);
  grid->SetSnapGridPosition(move_pos);

  ComponentServiceLocator::Instance()
      .Resolve<tile_map::ObjectTileMapComponent>()
      ->SetCell(move_pos, tile_map::kCanOnPlace + 1);
  if (actor_->is_front_) {
    if ((to_pos - move_pos) == GridPosition{0, 0}) actor_->is_front_ = false;
  } else {
    if ((from_pos - move_pos) == GridPosition{0, 0}) actor_->is_front_ = true;
  }
}
