#include "Component.h"

#include "Actor.h"

namespace base_engine {

Component::Component(Actor* owner, int updateOrder)
    : owner_(owner), update_order_(updateOrder) {

  owner_->AddComponent(this);
}

Component::~Component() { owner_->RemoveComponent(this); }
}  // namespace base_engine