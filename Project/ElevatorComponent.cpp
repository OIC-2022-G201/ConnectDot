#include "ElevatorComponent.h"

#include <filesystem>

#include "BaseEngineCore.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ElevatorReceiver.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LoadObjectParameter.h"
#include "PlayerComponent.h"
#include "PositionYTween.h"
#include "ReceiverComponent.h"
#include "SignboardReceiver.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"

using namespace base_engine;
using namespace draw_order;
class DummyChildActor : public Actor {
 public:
  explicit DummyChildActor(Game* game) : Actor(game) {}

  void Start() override { SetPosition(GetParent().lock()->GetPosition()); }
  void Update() override { SetPosition(GetParent().lock()->GetPosition()); }
};

ElevatorActor::ElevatorActor(base_engine::Game* game) : Actor(game) {}

void ElevatorActor::Create(const LoadObject& object) {
  {
    const auto dummy = new DummyChildActor(GetGame());
    dummy->SetTag("Field");

    AddChild(dummy->GetId());
    constexpr auto cell = stage::kStageCellSize<Floating>;
    const auto rect =
        std::make_shared<Rect>(0, cell.y * 2, cell.x * 2, cell.y * 3);

    const auto collision = new CollisionComponent(dummy);
    collision->SetShape(rect);
    collision->SetObjectFilter(kFieldObjectFilter);
    collision->SetTargetFilter(kFieldTargetFilter);
    collision->SetTrigger(false);
  }
  {
    constexpr auto cell = stage::kStageCellSize<Floating>;
    const auto rect =
        std::make_shared<Rect>(0, cell.y * 1, cell.x * 2, cell.y * 2);

    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kLeverObjectFilter);
    collision->SetTargetFilter(kLeverTargetFilter);
    collision->SetTrigger(true);
  }
  {
    const auto sprite = new SpriteComponent(this, kSignboardDrawOrder);
    const auto& path =
        std::get<LoadObject::TexturePath>(object.parameters[0]).value;
    sprite->SetImage(BASE_ENGINE(Texture)->Get(path));
    sprite->SetOffset({0, 24});
  }

  {
    auto pos = std::get<LoadObject::Transform>(object.parameters[2]).value;
    SetPosition(GridPosition::GridTo({pos.x, pos.y}));
  }
  {
    auto elevator = new ElevatorComponent(this);

    auto pos = std::get<Point2I>(object.parameters[4]);
    elevator->AddFloor(GridPosition::VectorTo(GetPosition()));
    elevator->AddFloor({pos.x, pos.y});
    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<ElevatorReceiver>(elevator, this);
  }
  SetName("ElevatorActor");
  SetTag("Field");
}

ElevatorComponent::ElevatorComponent(base_engine::Actor* owner,
                                     const int update_order)
    : Component(owner, update_order) {}

void ElevatorComponent::Start() {}

void ElevatorComponent::Action(base_engine::Actor* actor) {
  if (!electric_power_) return;
  if (busy_) return;

  current_floor_++;
  if (current_floor_ > positions_.size()) {
    current_floor_ = 1;
  }
  busy_ = true;
  ma_tween::PositionYTween::TweenLocalPositionY(
      owner_, GridPosition::GridTo(positions_[current_floor_ - 1]).y, 10)
      .SetOnComplete([this] { busy_ = false; });
}
