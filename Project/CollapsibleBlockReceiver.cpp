#include "CollapsibleBlockReceiver.h"

#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "MofSpriteAnimationComponent.h"
#include "ObjectTileMapComponent.h"

CollapsibleBlockReceiver::CollapsibleBlockReceiver(
    CollapsibleBlockComponent* component, base_engine::Actor* actor)
    : component_(component), owner_(actor) {}

int CollapsibleBlockReceiver::Sequential() { return 1000; }

bool CollapsibleBlockReceiver::PowerJoinCondition() { return true; }

void CollapsibleBlockReceiver::OnPowerEnter(TransmitterComponent* transmitter) {
  const auto collision =
      owner_->GetComponent<base_engine::CollisionComponent>().lock();

  collision->SetObjectFilter(kFieldObjectFilter);
  collision->SetTrigger(false);
  owner_->GetComponent<base_engine::MofSpriteAnimationComponent>().lock()->Play(
      "Animation");
  const auto pos = GridPosition::VectorTo(owner_->GetPosition());
  ComponentServiceLocator::Instance()
      .Resolve<tile_map::ObjectTileMapComponent>()
      ->SetCell(pos, tile_map::kCanOnPlace);
}

void CollapsibleBlockReceiver::OnPowerChanged(
    TransmitterComponent* transmitter) {}

void CollapsibleBlockReceiver::OnPowerExit(TransmitterComponent* transmitter) {
  const auto collision =
      owner_->GetComponent<base_engine::CollisionComponent>().lock();
  collision->SetObjectFilter(CollisionLayer::kNone);

  collision->SetTrigger(true);
  owner_->GetComponent<base_engine::MofSpriteAnimationComponent>().lock()->Play(
      "Door", -1);
  const auto pos = GridPosition::VectorTo(owner_->GetPosition());
  ComponentServiceLocator::Instance()
      .Resolve<tile_map::ObjectTileMapComponent>()
      ->SetCell(pos, tile_map::kEmptyCell);
}

bool CollapsibleBlockReceiver::IsWireless() { return false; }

base_engine::Vector2 CollapsibleBlockReceiver::GetPosition() const {
  return {};
}
