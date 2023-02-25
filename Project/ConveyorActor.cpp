#include "ConveyorActor.h"

#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ConveyorReceiver.h"
#include "DrawOrder.h"
#include "GimmickCreateHelper.h"
#include "GridSnapComponent.h"
#include "PhysicsBodyComponent.h"
#include "ReceiverComponent.h"
#include "Rect.h"
using namespace base_engine;
using namespace draw_order;

void ConveyorActor::Create(const LoadObject& object) {
  {
    constexpr auto cell = stage::kStageCellSize<Floating>;
    const auto rect = std::make_shared<Rect>(0, 0, cell.x, cell.y);

    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kConveyorObjectFilter);
    collision->SetTargetFilter(kConveyorTargetFilter);
    collision->SetTrigger(false);
  }

  {
    auto block = new ConveyorComponent(this);
    {
      const auto path = "Conveyer";
      const auto [sprite, animation] = GimmickCreateHelper::AnimationCreateKey(
          this, path, object.object.color_type, true, kVentDrawOrder);
      block->SetAnimation(animation, sprite);
      SetScale(0.5);
      for (auto&& part : object.object.parts) {
        if (const auto pos_part =
                std::get_if<stage::part::VariableSizePart>(&part)) {
          const auto type = pos_part->GetType();
          block->SetVariablePosType(type);
        }
      }
    }
    for (auto&& part : object.object.parts) {
      if (const auto dir_part = std::get_if<stage::part::DirPart>(&part)) {
        block->SetDir(dir_part->GetDir());
      }
    }

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<ConveyorReceiver>(block, this);
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
  }
  SetName("Field");
  SetTag("Field");
}

void ConveyorActor::Start() {}

void ConveyorActor::Input() {}

void ConveyorActor::Update() {}

void ConveyorComponent::SetDir(const stage::part::Dir dir) {
  dir_ = dir;
  ChangeAnimation();
}

void ConveyorComponent::SetVariablePosType(
    const stage::part::VariableSizeType type) {
  type_ = type;
  ChangeAnimation();
}

void ConveyorComponent::SetElectric(const bool flg) {
  electric_power_ = flg;
  if (flg) {
    ChangeAnimation();
  } else {
    animation_->Stop(false);
  }
}

void ConveyorComponent::OnCollision(const base_engine::SendManifold& manifold) {
  if (!electric_power_) return;

  const auto physics_weak =
      manifold.collision_b->GetActor()->GetComponent<PhysicsBodyComponent>();
  if (physics_weak.expired()) return;
  const auto physics = physics_weak.lock();
  if (abs(physics->GetForce().x) > 1.2f) return;
  physics->AddForce({((dir_ == stage::part::Dir::kRight) ? 1.2f : -1.2f), 0});
}

void ConveyorComponent::ChangeAnimation() {
  std::string name;
  if (this->type_ == stage::part::VariableSizeType::kMiddle) {
    name = "Midway";
  } else {
    name = "Edge";
  }
  if (this->type_ == stage::part::VariableSizeType::kLeft) {
    sprite_->SetFlip(Flip::kHorizontal);
    if (this->dir_ == stage::part::Dir::kRight) {
      name += "_Reverse";
    }
  } else {
    if (this->dir_ == stage::part::Dir::kLeft) {
      name += "_Reverse";
    }
  }
  animation_->Play(name);
  if (!electric_power_) animation_->Stop();
}
