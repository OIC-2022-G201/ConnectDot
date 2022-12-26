#include "PlayerIdle.h"

#include "BeaconActor.h"
#include "CollisionLayer.h"
#include "GridSnapComponent.h"
#include "ObjectTileMapComponent.h"
#include "PhysicsFixture.h"
#include "PhysicsWorldCallBack.h"
#include "PlayerComponent.h"
#include "ResultModel.h"
#include "ServiceLocator.h"
GridPosition g_position{0, 0};

player::PlayerIdle::PlayerIdle(PlayerComponent* player) : player_(player) {
  player_->GetGame()->debug_render_.emplace_back([] {
    Mof::CGraphicsUtilities::RenderString(0, 600, "%d,%d", g_position.x,
                                          g_position.y);
  });
}

void player::PlayerIdle::Start() {
  body_ = player_->PhysicsBody();
  is_jump_ = false;
  is_move_ = false;
  is_sneak_ = false;
  player_->GetAnimator()->ChangeMotion("Tati");
}
class BeaconQueryCallBack : public base_engine::physics::PhysicsQueryCallback {
 public:
  bool ReportFixture(base_engine::physics::PhysicsFixture* fixture) override {
    const auto actor = fixture->collision_->GetActor();

    if (fixture->collision_->GetTargetFilter() == kPlayerObjectFilter &&
        actor->GetTag() == "Beacon") {
      auto pos = GridPosition::VectorTo(actor->GetPosition());
      ServiceLocator::Instance()
          .Resolve<tile_map::ObjectTileMapComponent>()
          ->SetCell(pos.x, pos.y, 0);
      actor->GetGame()->RemoveActor(actor);

      return false;
    }
    return true;
  }
};
void player::PlayerIdle::Update() {
  g_position = GridPosition::VectorTo(player_->GetOwner()->GetPosition());

  if (player_->IsPlaceBeaconKey() && player_->GetBeacon() > 0) {
    PlaceBeacon();
  }
  if (player_->IsCollectBeaconKey()) {
    auto pos = player_->GetOwner()->GetPosition();
    BeaconQueryCallBack call_back;
    BASE_ENGINE(Collider)->QueryAABB(
        &call_back, {{pos.x, pos.y}, {pos.x + 128, pos.y + 256}});
  }
}

void player::PlayerIdle::ProcessInput() {
  is_jump_ = player_->IsJumpKey();
  is_move_ = player_->GetHorizontal() != 0 || body_->GetForce().x != 0;
  is_sneak_ = player_->IsSneakKey();
}

void player::PlayerIdle::End() {}

void player::PlayerIdle::OnEvent(base_engine::CollisionComponent* collision) {}

void player::PlayerIdle::PlaceBeacon() const {
  auto pos = GridPosition::VectorTo(player_->GetOwner()->GetPosition());
  pos.x += player_->IsRight() ? 1 : 0;
  pos.y += 1;
  if (!player_->CanPlace(pos)) return;
  player_->SetBeacon(player_->GetBeacon() - 1);
  ServiceLocator::Instance()
      .Resolve<tile_map::ObjectTileMapComponent>()
      ->SetCell(pos.x, pos.y, 1);
  const auto score = ServiceLocator::Instance().Resolve<ResultModel>();
  score->IncrementBeaconUsedTimes();
  const auto beacon = new BeaconActor(player_->GetGame());
  const auto grid = beacon->GetComponent<grid::GridSnapComponent>().lock();
  grid->SetSnapGridPosition(pos);
  beacon->SetSequential((player_->MaxBeacon() - player_->GetBeacon()) * 10);
}
