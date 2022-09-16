#pragma once
#include <variant>

#include "Actor.h"
#include "BeaconReceiver.h"
#include "ReactiveProperty.h"
#include "ShapeRenderComponent.h"
#include "Subject.h"
#include "TupleHasElement.h"


class BeaconActor final : public base_engine::Actor {
 public:
  using BeaconPartTuple =
      std::tuple<class BeaconReceiver*, class BeaconTransmitter*,
                 base_engine::ShapeRenderComponent*>;

  explicit BeaconActor(base_engine::Game* game);

  ~BeaconActor() override;

  void Start() override;
  void Input() override;
  void Update() override;

 public:
  template <class BeaconPart,
            std::enable_if_t<tuple_holds_v<BeaconPartTuple, BeaconPart>, bool> =
                false>
  void RegistryPart(BeaconPart part) {
    auto&& n = std::get<BeaconPart>(tuple_);
    std::get<BeaconPart>(tuple_) = part;
  }
  void SetElectricPower(bool flg) { electric_power_ = flg;  }
  [[nodiscard]] auto&& ElectricPowerTrigger() {
    return electric_power_.ToReadOnly();
  }

 private:
  observable::ReactiveProperty<bool> electric_power_ = false;

  BeaconPartTuple tuple_;
};
