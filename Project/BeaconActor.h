#pragma once
#include <variant>

#include "Actor.h"
#include "BeaconReceiver.h"
#include "TupleHasElement.h"
#include "Subject.h"
class BeaconActor final : public base_engine::Actor {
 public:
  using BeaconPartTuple =
      std::tuple<class BeaconReceiver*,class BeaconTransmitter*>;

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

  observable::IObservable<int>* Test() {
      return &sub;
  }
 private:
  observable::Subject<int> sub;
  BeaconPartTuple tuple_;
};
