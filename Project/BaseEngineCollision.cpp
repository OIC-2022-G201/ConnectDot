#include "BaseEngineCollision.h"

#include "Circle.h"
#include "CollisionComponent.h"
#include "Game.h"
#include "IShape.h"
#include "Mof.h"
#include "PhysicsBody2D.h"
#include "PhysicsBodyComponent.h"
#include "PhysicsCircleShape.h"
#include "PhysicsContact.h"
#include "PhysicsFixture.h"
#include "PhysicsPolygonShape.h"
#include "PhysicsWorld.h"

using namespace base_engine::physics;
namespace base_engine {

struct Contact {
  CollisionComponent* a;
  CollisionComponent* b;
  Manifold manifold;
};

BaseEngineCollision::~BaseEngineCollision() = default;

BaseEngineCollision::BaseEngineCollision() {
  world_ = new physics::PhysicsWorld({0, 0});
}

void BaseEngineCollision::Collide() {
  world_->Step(0.017f);
  size_t body_size = body_list_.size();
  std::vector<SendManifold> contacts;
  contacts.reserve(100);
  int n = 0;
  {
    auto contact = world_->m_contactManager.m_contactList;
    while (contact) {
      auto body_a = contact->GetFixtureA()->collision_;
      auto body_b = contact->GetFixtureB()->collision_;
      if (auto manifold = body_a->Collision(body_b); manifold.has_collision) {
        if (!(body_a->GetTrigger() || body_b->GetTrigger())) {
          auto p_a = body_a->GetPhysicsBody();
          auto p_b = body_b->GetPhysicsBody();
          if (p_a) p_a->Solver(manifold, p_b);
          if (p_b) p_b->Solver(manifold, p_a);
          body_a->SyncPosition();
        }
        contacts.emplace_back(body_a, body_b, manifold);
      }
      contact = contact->m_next;
      n++;
    }
  }
  for (int i = contacts.size() - 1; i >= 0; --i) {
    auto& contact = contacts[i];
    auto body_a = contact.collision_a;
    auto body_b = contact.collision_b;
    auto manifold = body_a->Collision(body_b);
    if ( manifold.has_collision) {
        if(!(body_a->GetTrigger() || body_b->GetTrigger()))
        {
            auto p_a = body_a->GetPhysicsBody();
            auto p_b = body_b->GetPhysicsBody();
            if (p_a) p_a->Solver(manifold, p_b);
            if (p_b) p_b->Solver(manifold, p_a);
            body_a->SyncPosition();
        }
      contact = {body_a, body_b, manifold};
    }
  }
  for (const auto& contact : contacts) {
    auto body_a = contact.collision_a;
    auto body_b = contact.collision_b;

    body_a->CollisionSender({body_a, body_b, contact.manifold});
    body_b->CollisionSender({body_b, body_a, contact.manifold});
  }
  connectCount = n;
  for (int i = 0; i < body_size; ++i) {
    body_list_[i]->SyncPosition();
  }
}

void BaseEngineCollision::Register(CollisionComponent* component) {
  body_list_.emplace_back(component);
  BodyDef bd;
  if (const auto pb = component->GetPhysicsBody(); pb) {
    bd.type = static_cast<PhysicsBodyType>(pb->GetType());
  }
  auto p = component->GetActor()->GetPosition();
  bd.position = PVec2{p.x, p.y};
  PhysicsBody* body = world_->CreateBody(&bd);

  PhysicsFixtureDef fixture_def;
  fixture_def.filter.maskTargetBits = component->GetTargetFilter().to_ulong();
  fixture_def.filter.maskObjectBits = component->GetObjectFilter().to_ulong();
  switch (const auto collision_shape = component->GetShape();
          collision_shape->GetType()) {
    case ShapeType::kNone:
      break;
    case ShapeType::kRect: {
      b2PolygonShape shape;
      const auto rect = component->GetShape()->AABB();
      shape.SetAsRect(rect.Left,rect.Top,rect.Right,rect.Bottom);

      fixture_def.shape = &shape;
      fixture_def.collision = component;
      body->CreateFixture(&fixture_def);
    } break;
    case ShapeType::kCircle: {
      physics::b2CircleShape shape;
      const auto circle = static_cast<Circle*>(component->GetShape());
      shape.m_p.x = circle->Position.x;
      shape.m_p.y = circle->Position.y;
      shape.m_radius = static_cast<Circle*>(component->GetShape())->r;

      fixture_def.shape = &shape;
      fixture_def.collision = component;
      body->CreateFixture(&fixture_def);
    } break;
    case ShapeType::kPoint:
      break;
    default:;
  }

  float minX = -6.0f;
  float maxX = 0.0f;
  float minY = 4.0f;
  float maxY = 6.0f;

  component->SetPhysicsBody(body);
}

void BaseEngineCollision::Remove(CollisionComponent* component) {
  body_list_.erase(std::ranges::remove(body_list_, component).begin(),
                   body_list_.end());

  const auto body = component->GetEnginePhysicsBody();
  if (!body)return;
  world_->DestroyBody(body);
}

void BaseEngineCollision::SendComponentsMessage(Component* component,
                                                const SendManifold& manifold) {
  component->OnCollision(manifold);
}

void BaseEngineCollision::SetCallBack(Game* game) {
  game->debug_render_.emplace_back([this] {
    world_->DebugRender(this);
    Mof::CGraphicsUtilities::RenderString(0, 400, MOF_COLOR_BLUE, "count:%d",
                                          connectCount);
  });
}

void BaseEngineCollision::Render(physics::PhysicsFixture* fixture) {
  return;
  
  auto p = fixture->GetBody()->GetPosition();

  switch (fixture->GetType()) {
    case b2Shape::Type::kCircle: {
      auto ciercle = dynamic_cast<b2CircleShape*>(fixture->GetShape());

      CGraphicsUtilities::RenderCircle(
          p.x + ciercle->m_p.x, p.y + ciercle->m_p.y - 500,
          fixture->GetShape()->m_radius, MOF_COLOR_BLUE);
    } break;
    case b2Shape::Type::kEdge:
      break;
    case b2Shape::Type::kPolygon: {
      auto polygon = dynamic_cast<b2PolygonShape*>(fixture->GetShape());
      CGraphicsUtilities::RenderRect(
          p.x + polygon->m_vertices[0].x, p.y + polygon->m_vertices[0].y - 500,
          p.x + polygon->m_vertices[2].x, p.y + polygon->m_vertices[2].y - 500,
          MOF_COLOR_BLUE);
      break;
    }
    case b2Shape::Type::kChain:
      break;
    default:;
  }
}

void BaseEngineCollision::QueryAABB(physics::PhysicsQueryCallback* callback,
                                    const physics::PhysicsAABB& aabb) {
  world_->QueryAABB(callback, aabb);
}

void BaseEngineCollision::RayCast(physics::PhysicsRayCastCallback* callback,
                                  const physics::PVec2& point1,
                                  const physics::PVec2& point2) const {
  world_->RayCast(callback, point1, point2);
}
}  // namespace base_engine