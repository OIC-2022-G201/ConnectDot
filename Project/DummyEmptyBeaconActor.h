// @DummyEmptyBeaconActor.h
// @brief
// @author
// @date 2023/01/08
//
// @details

#pragma once
#include <variant>

#include "Actor.h"
#include "PlayerComponent.h"
#include "ReceiverComponent.h"
#include "ShapeRenderComponent.h"
#include "TupleHasElement.h"

class DummyEmptyBeaconActor final : public base_engine::Actor {
 public:
  using BeaconPartTuple =
      std::tuple<class BeaconDummyReceiver*, class BeaconDummyTransmitter*,
                 base_engine::ShapeRenderComponent*>;

  explicit DummyEmptyBeaconActor(base_engine::Game* game);

  ~DummyEmptyBeaconActor() override;
  void SetSequential(const int sequential);
  int Sequential() const;
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
  void SetPlayer(player::PlayerComponent* player) { player_ = player; }
  bool IsElectric() const { return electric_power_; }
  void SetElectric(bool flg) { electric_power_ = flg; }
 private:
  player::PlayerComponent* player_ = nullptr;
  bool electric_power_ = false;
  int sequential_ = 0;
  BeaconPartTuple tuple_;
  ReceiverComponent* receiver_;
  TransmitterComponent* transmitter_;
  base_engine::CollisionComponent* collision_;
  std::optional<GridPosition> prev_pos_ = std::nullopt;
};
