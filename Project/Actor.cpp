#include "Actor.h"

#include "Component.h"
#include "Game.h"
namespace base_engine {
Actor::Actor(Game* game)
    : state_(kActive), rotation_(0.0f), scale_(1.0f), game(game) {
  game->AddActor(this);
}

Actor::~Actor() {
  game->RemoveActor(this);

  while (!components_.empty()) {
    delete components_.back();
  }
}

void Actor::StartActor()
{
  if (state_ == kActive) {
    for (auto comp : components_) {
      comp->Start();
    }

    Start();
  }
}

void Actor::ProcessInput() {
  if (state_ == kActive) {
    for (auto comp : components_) {
      comp->ProcessInput();
    }

    Input();
  }
}

void Actor::UpdateActor() {
  if (state_ == kActive) {
    for (auto component : components_) {
      component->Update();
    }

    Update();
  }
}

float Actor::GetRotation() const
{ return rotation_; }

void Actor::AddComponent(Component* component) {
  // ソート済み配列の挿入場所を探す
  // (自分より順番の大きい最初の要素を探す)
  int myOrder = component->GetUpdateOrder();
  auto iter = components_.begin();
  for (; iter != components_.end(); ++iter) {
    if (myOrder < (*iter)->GetUpdateOrder()) {
      break;
    }
  }

  // 探し出した要素の前に自分を挿入
  components_.insert(iter, component);
}

void Actor::RemoveComponent(Component* component) {
  auto iter = std::find(components_.begin(), components_.end(), component);
  if (iter != components_.end()) {
    components_.erase(iter);
  }
}

Actor& Actor::SetName(const std::string_view name)
{
    name_ = name;

    return *this;
}
}  // namespace base_engine