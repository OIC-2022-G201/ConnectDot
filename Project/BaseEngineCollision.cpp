#include "BaseEngineCollision.h"

#include "CollisionComponent.h"
#include "IShape.h"
#include "Player.h"

namespace base_engine {
BaseEngineCollision::~BaseEngineCollision() = default;

void BaseEngineCollision::Collide() {
  size_t body_size = body_list_.size();
  for (int body_a_index = 0; body_a_index < body_size; ++body_a_index) {
    auto body_a = body_list_[body_a_index];

    for (int body_b_index = body_a_index + 1; body_b_index < body_size;
         ++body_b_index) {
      auto body_b = body_list_[body_b_index];
      if (body_a->IsMatch(body_b))
      {
        if (const auto manifold = body_a->Collision(body_b); manifold.has_collision) {
          body_a->CollisionSender(SendManifold{body_a,body_b, manifold});
          body_b->CollisionSender(SendManifold{body_b,body_a, manifold});
          }
      }
    }
  }
}

void BaseEngineCollision::Register(CollisionComponent* component) {
  body_list_.emplace_back(component);
}

void BaseEngineCollision::Remove(CollisionComponent* component) {
  body_list_.erase(remove(body_list_.begin(), body_list_.end(), component),
                   body_list_.end());
}

void BaseEngineCollision::SendComponentsMessage(Component* component,
                                                const SendManifold& manifold) {
  component->OnCollision(manifold);
}
}  // namespace base_engine