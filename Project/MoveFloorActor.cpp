#include "MoveFloorActor.h"


#include <memory>
#include <Mof.h>

#include "BaseEngineCore.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ReceiverComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
#include "MoveFloorReceiver.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "LeverActor.h"
#include "IPlayerAction.h"

using namespace base_engine;
using namespace  electronics;
using namespace  mofl;
using namespace draw_order;
MoveFloorActor::MoveFloorActor(base_engine::Game* game):Actor(game){}

void MoveFloorActor::Start(){
  {
    const auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
    const auto circle = std::make_shared<base_engine::Circle>(
        cell_half.x, cell_half.y, electronics::kPowerRadius);
    const auto shape = new base_engine::ShapeRenderComponent(this, 110);
    shape->SetShape(circle);
    shape->SetFillMode(electronics::kElectricAreaFillMode)
        .SetColor(electronics::kElectricAreaColor);
    const auto rect= std::make_shared<Rect>(0, 0, 128, 128);
    const auto collision = new base_engine::CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kMoveFloorObjectFilter);
    collision->SetTargetFilter(kMoveFloorTargetFilter);
    
  }
  {
    const auto rect = std::make_shared<base_engine::Rect>(
        0, 0, stage::kStageCellSize<base_engine::Floating>.x,
        stage::kStageCellSize<base_engine::Floating>.y);

    const auto shape_rect = new base_engine::ShapeRenderComponent(
        this, draw_order::kPylonDrawOrder);
    shape_rect->SetShape(rect);
    shape_rect->SetFillMode(base_engine::FillMode::Yes)
        .SetColor(MOF_ARGB(255, 255, 0, 0));
  }
  SetName("MoveFloor");
  SetTag("Field");
  {
  	grid_ = new grid::GridSnapComponent(this);
    grid_->SetAutoSnap(grid::AutoSnap::No).SetSnapGridPosition({mx_, my_});
  }
  {
    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<MoveFloorReceiver>(this,target_);
  }
  
}

void MoveFloorActor::Update()
{ 
    if (g_pInput->IsKeyPush(MOFKEY_0))
    {
      auto g_pos = GridPosition::VectorTo(GetPosition());;
      g_pos.x++;
      grid_->SetSnapGridPosition(g_pos);
    } }

void MoveFloorActor::SetSwitch()
{
  auto g_pos = GridPosition::VectorTo(GetPosition());
  g_pos.x++;
  grid_->SetSnapGridPosition(g_pos);
}
