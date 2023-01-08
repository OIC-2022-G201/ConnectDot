#pragma once
#include <variant>

#include "Actor.h"
#include "ISpriteAnimationComponent.h"
#include "ReactiveProperty.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"
#include "TupleHasElement.h"

class BeaconActor final : public base_engine::Actor{
 public:
  using BeaconPartTuple =
      std::tuple<class BeaconReceiver*, class BeaconTransmitter*,
                 base_engine::ShapeRenderComponent*>;

  explicit BeaconActor(base_engine::Game* game);

  ~BeaconActor() override;
  void SetSequential(const int sequential) { sequential_ = sequential; }
  int Sequential() const { return sequential_; }
  void Start() override;
  void Input() override;
  void Update() override;

  template <class BeaconPart,
            std::enable_if_t<tuple_holds_v<BeaconPartTuple, BeaconPart>, bool> =
	            false>
  void RegistryPart(BeaconPart part) {
    auto&& n = std::get<BeaconPart>(tuple_);
    std::get<BeaconPart>(tuple_) = part;
  }
  void SetElectricPower(bool flg) { electric_power_ = flg; }
  [[nodiscard]] auto&& ElectricPowerTrigger() {
    return electric_power_.ToReadOnly();
  }
  [[nodiscard]] auto&& LevelUpTrigger() { return level_.ToReadOnly();
  }
  void LevelUp();
  void SetOutline(const bool flg) const;
  bool IsOutline() const;

private:
  observable::ReactiveProperty<bool> electric_power_ = false;
  observable::ReactiveProperty<int> level_ = 1;
  int sequential_ = 0;
  BeaconPartTuple tuple_;
  bool is_deployed_ = false;
  base_engine::ISpriteAnimationComponent* animation_;
  base_engine::SpriteComponent* sprite_;

  base_engine::SpriteComponent* sprite_outline_;


};
