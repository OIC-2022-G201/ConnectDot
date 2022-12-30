#include "Actor.h"

#include "Component.h"
#include "Game.h"
namespace base_engine {
Actor::Actor(Game* game)
    : state_(kStart), rotation_(0.0f), scale_(1.0f), game(game) {
  game->AddActor(this);
}

Actor::Actor(Game* game, const std::weak_ptr<Scene> scene)
{
  game->AddActor(this, scene);
}

Actor::~Actor() {
  components_.clear();
  if (!parent_.expired()) {
    RemoveChild(id_);
  }
  for (const auto& child : children_) {
    if (child.expired()) continue;
    game->RemoveActor(child.lock().get());
  }
}

void Actor::StartActor() {
  if (state_ == kStart) {
    Start();
    for (const auto& comp : components_) {
      comp->Start();
    }

    state_ = kActive;
  }
}

void Actor::ProcessInput() {
  if (state_ == kActive) {
    Input();
    for (const auto& comp : components_) {
      comp->ProcessInput();
    }
  }
}

void Actor::UpdateActor() {
  if (state_ == kActive) {
    Update();
    for (const auto& component : components_) {
      if(component) component->Update();
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
  if (const auto iter = std::ranges::find_if(
          components_,
          [component](const ComponentPtr& n) { return n.get() == component; });
      iter != components_.end()) {
    components_.erase(iter);
  }
}

Actor& Actor::SetName(const std::string_view name) {
  name_ = name;

  return *this;
}
void Actor::SetTag(std::string_view tag) { tag_ = tag; }
std::string_view Actor::GetTag() const { return tag_; }

std::weak_ptr<Actor> Actor::GetChildByName(const std::string_view name) const {
  for (const auto& child : children_) {
    if (child.expired()) continue;
    if (child.lock()->GetName() == name) {
      return child;
    }
  }
  return std::weak_ptr<Actor>{};
}

bool Actor::RemoveChild(const ActorId id) {
  auto it = children_.begin();
  while (it != children_.end()) {
    if (it->expired() || it->lock()->id_ != id) {
      ++it;
      continue;
    }
    it->lock()->parent_.reset();
    children_.erase(it);
    break;
  }
  return false;
}

void Actor::AddChild(const std::weak_ptr<Actor>& actor) {
  if (actor.expired()) return;
  children_.push_back(actor);
  actor.lock()->parent_ = game->GetActor(id_);
}

void Actor::AddChild(const ActorId& id) {
  const std::weak_ptr<Actor> actor = game->GetActor(id);
  if (actor.expired()) return;
  children_.push_back(actor);
  actor.lock()->parent_ = game->GetActor(id_);
}

std::weak_ptr<Actor> Actor::GetChildByTag(const std::string_view tag) const {
  for (const auto& child : children_) {
    if (child.expired()) continue;
    if (child.lock()->GetTag() == tag) {
      return child;
    }
  }
  return std::weak_ptr<Actor>{};
}

std::weak_ptr<Actor> Actor::GetParent() const { return parent_; }

void Actor::SetEnable(bool b_enable)
{
	if (b_enable == b_enable_) return;
	b_enable_ = b_enable;
	if (b_enable_) {
		OnEnable();
	} else {
		OnDisable();
	}
}
}  // namespace base_engine