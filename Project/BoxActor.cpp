#include "BoxActor.h"

#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "GimmickCreateHelper.h"
#include "GridSnapComponent.h"
#include "PhysicsBodyComponent.h"
#include "ResourceContainer.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"

using namespace base_engine;
void BoxActor::Start() {}

void BoxActor::Input() {}

void BoxActor::Update() {
  const auto power_x = body_->GetForce().x;
  body_->AddForce({-power_x * 0.2f, 0.12f});
}

void BoxActor::Create(const LoadObject& object) {
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
  }

  {
    GimmickCreateHelper::SpriteCreateKey(this, "Box", object.object.color_type,
                                         100);
  }
  {
    const auto collision = new CollisionComponent(this);
    const auto shape_enemy = std::make_shared<Rect>(0, 0, 128, 128);
    collision->SetShape(shape_enemy);
    collision->SetObjectFilter(kBoxObjectFilter);
    collision->SetTargetFilter(kBoxTargetFilter);
    collision->SetTrigger(false);
  }
  {
	  body_ = new PhysicsBodyComponent(this);
    body_->SetType(physics::BodyMotionType::kKinematic);
  }
  SetName("Field");
  SetTag("Field");
}
