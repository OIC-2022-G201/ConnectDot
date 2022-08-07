#include "BeaconActor.h"

#include "ShapeRenderComponent.h"
#include "Rect.h"

BeaconActor::BeaconActor(base_engine::Game* game): Actor(game)
{}

bool BeaconActor::PowerJoinCondition()
{ return true; }

void BeaconActor::OnPowerEnter()
{}

void BeaconActor::OnPowerChanged()
{}

void BeaconActor::OnPowerExit()
{}

BeaconActor::~BeaconActor()
{}

void BeaconActor::Start()
{
    auto shape = new base_engine::ShapeRenderComponent(this, 110);
    shape->SetShape(std::make_shared<base_engine::Rect>(0, 0, 50, 50));
    shape->SetFillMode(base_engine::FillMode::Yes).SetColor(MOF_COLOR_GREEN);
  
}

void BeaconActor::Input()
{}

void BeaconActor::Update()
{}

std::vector<IReceivablePower*> BeaconActor::GetTarget()
{
  return SendTargetList();
}

void BeaconActor::Sending()
{}
