#pragma once
#include "Actor.h"
#include "Component.h"
#include "ISpriteAnimationComponent.h"
#include "LoadObjectParameter.h"
#include "SpriteComponent.h"

class ConveyorActor final : public base_engine::Actor {
public:
	explicit ConveyorActor(base_engine::Game* game)
		: Actor(game) {
	}
 void Create(const LoadObject& object);

	void Start() override;
	void Input() override;
	void Update() override;
};
class ConveyorComponent final : public base_engine::Component {
 public:
  explicit ConveyorComponent(base_engine::Actor* owner,
                                     const int update_order = 100)
      : Component(owner, update_order) {}

  void SetDir(const stage::part::Dir dir);
  void SetVariablePosType(const stage::part::VariableSizeType type);
  void SetElectric(const bool flg);

  void SetAnimation(base_engine::ISpriteAnimationComponent* animation,
                    base_engine::SpriteComponent* sprite)
  {
    animation_ = animation;
    sprite_ = sprite;
  }
  [[nodiscard]] bool GetElectric() const { return electric_power_; }
  void OnCollision(const base_engine::SendManifold& manifold) override;

 private:
  void ChangeAnimation();

  base_engine::ISpriteAnimationComponent* animation_;
  base_engine::SpriteComponent* sprite_;
  bool electric_power_ = false;
  stage::part::Dir dir_;
  stage::part::VariableSizeType type_;
};