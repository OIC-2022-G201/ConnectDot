#include "Actor.h"

#include "Component.h"
#include "Game.h"
namespace base_engine {
Actor::Actor(Game* game)
    : state_(kStart), rotation_(0.0f), scale_(1.0f), game(game) {
  game->AddActor(this);
}

Actor::~Actor() {
  game->RemoveActor(this);

  while (!components_.empty()) {
    delete components_.back();
  }
}

void Actor::StartActor() {
  if (state_ == kStart) {
    Start();
    for (auto comp : components_) {
      comp->Start();
    }

    state_ = kActive;
  }
}

void Actor::ProcessInput() {
  if (state_ == kActive) {
    Input();
    for (auto comp : components_) {
      comp->ProcessInput();
    }
  }
}

void Actor::UpdateActor() {
  if (state_ == kActive) {
    Update();
    for (auto component : components_) {
      component->Update();
    }
  }
}

float Actor::GetRotation() const { return rotation_; }

void Actor::AddComponent(Component* component) {
  pending_components_.emplace_back(component);
}
void Actor::AddComponent() {
  // ƒ\[ƒgÏ‚İ”z—ñ‚Ì‘}“üêŠ‚ğ’T‚·
  // (©•ª‚æ‚è‡”Ô‚Ì‘å‚«‚¢Å‰‚Ì—v‘f‚ğ’T‚·)
  for (size_t i = 0; i < std::ssize(pending_components_); ++i) {
    int myOrder = pending_components_[i]->GetUpdateOrder();
    auto iter = components_.begin();
    for (; iter != components_.end(); ++iter) {
      if (myOrder < (*iter)->GetUpdateOrder()) {
        break;
      }
    }
    // ’T‚µo‚µ‚½—v‘f‚Ì‘O‚É©•ª‚ğ‘}“ü
    components_.insert(iter, pending_components_[i]);

    if (state_ == kActive) pending_components_[i]->Start();
  }
  pending_components_.clear();
}
void Actor::RemoveComponent(Component* component) {
  auto iter = std::find(components_.begin(), components_.end(), component);
  if (iter != components_.end()) {
    components_.erase(iter);
  }
}

Actor& Actor::SetName(const std::string_view name) {
  name_ = name;

  return *this;
}
void Actor::SetTag(std::string_view tag) { tag_ = tag; }
std::string_view Actor::GetTag() const { return tag_; }
}  // namespace base_engine