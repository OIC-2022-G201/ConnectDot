#include "DummyEmptyBeaconActor.h"

#include "BeaconActor.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ElectronicsPower.h"
#include "MofSpriteAnimationComponent.h"
#include "PowerSupplyUnitActor.h"
#include "ReceiverComponent.h"
#include "ReleaseInfo.h"
#include "StageConstitution.h"
#include "TransmitterComponent.h"
using namespace electronics;
using namespace beacon;
using RC = ResourceContainer;

class DummyReceiverComponent : public ReceiverComponent {
 public:
  DummyReceiverComponent(base_engine::Actor* owner, int update_order)
      : ReceiverComponent(owner, update_order) {}

  void Update() override {
    senders_.clear();
    wait_frame_ = 0;
    if (current_state_ == PowerState::kConnecting &&
        prev_state_ == PowerState::kDisconnect) {
      prev_state_ = PowerState::kDisconnected;
    }
    switch (prev_state_) {
      case PowerState::kDisconnected:
        OnPowerExit();
        wait_frame_ = 0;
        break;
      case PowerState::kConnect:

        OnPowerEnter();
        break;
      case PowerState::kConnecting:
        OnPowerChanged();
        break;
      case PowerState::kDisconnect: {
        if (sender_.expired()) return;

        if (const auto target = sender_.lock()->GetOwner(); !target.expired()) {
          if (const auto beacon =
                  std::dynamic_pointer_cast<BeaconActor>(target.lock())) {
            beacon->SetOutline(false);
          } else if (const auto supply =
                         std::dynamic_pointer_cast<PowerSupplyUnitActor>(
                             target.lock())) {
            supply->SetOutline(false);
          }
        }
      }
        return;
        break;
      default:;
    }
    prev_state_ = PowerState::kDisconnect;
    if (!disconnect_) {
      if (!sender_.expired()) {
        if (const auto target = sender_.lock()->GetOwner(); !target.expired()) {
          if (const auto beacon =
                  std::dynamic_pointer_cast<BeaconActor>(target.lock())) {
            beacon->SetOutline(false);
          } else if (const auto supply =
                         std::dynamic_pointer_cast<PowerSupplyUnitActor>(
                             target.lock())) {
            supply->SetOutline(false);
          }
        }
      }
      sender_.reset();
    } else {
      if (!sender_.expired()) {
        if (const auto target = sender_.lock()->GetOwner(); !target.expired()) {
          if (const auto beacon =
                  std::dynamic_pointer_cast<BeaconActor>(target.lock())) {
            beacon->SetOutline(true);
          } else if (const auto supply =
                         std::dynamic_pointer_cast<PowerSupplyUnitActor>(
                             target.lock())) {
            supply->SetOutline(true);
          }
        }
      }
    }
    disconnect_ = false;
  }

  void Connecting(std::weak_ptr<TransmitterComponent> sender_weak) override {
    if (sender_weak.expired()) return;
    const auto sender = sender_weak.lock();
    senders_.emplace_back(sender);
    if (senders_.size() > 1) {
      int n = 4;
    } else {
    }

    if (sender_.expired() || sender_.lock()->GetOwner().expired()) {
      sender_.reset();

    }
    if (sender_.expired()) {
      sender_ = sender;
      if (const auto target = sender_.lock()->GetOwner(); !target.expired()) {
        if (const auto beacon =
                std::dynamic_pointer_cast<BeaconActor>(target.lock())) {
          beacon->SetOutline(true);
        } else if (const auto supply =
                       std::dynamic_pointer_cast<PowerSupplyUnitActor>(
                           target.lock())) {
          supply->SetOutline(true);
        }
      }
    }
    disconnect_ |= EqualSender(sender_weak);

    if (sender_.lock()->GetOwner().expired()) {
      sender_.reset();
      return;
    }
    if (const auto prev_receiver = sender_.lock()
                                       ->GetOwner()
                                       .lock()
                                       ->GetComponent<ReceiverComponent>();
        !prev_receiver.expired()) {
      const auto target_weak = sender_weak.lock()
                                   ->GetOwner()
                                   .lock()
                                   ->GetComponent<ReceiverComponent>();
      if (!target_weak.expired()) {
        if (prev_receiver.lock()->Sequential() >
            target_weak.lock()->Sequential()) {
          if (const auto target = sender_.lock()->GetOwner();
              !target.expired()) {
            if (const auto beacon =
                    std::dynamic_pointer_cast<BeaconActor>(target.lock())) {
              beacon->SetOutline(false);
            } else if (const auto supply =
                           std::dynamic_pointer_cast<PowerSupplyUnitActor>(
                               target.lock())) {
              supply->SetOutline(false);
            }
          }
          sender_ = sender;
          if (const auto target = sender_.lock()->GetOwner();
              !target.expired()) {
            if (const auto beacon =
                    std::dynamic_pointer_cast<BeaconActor>(target.lock())) {
              beacon->SetOutline(true);
            } else if (const auto supply =
                           std::dynamic_pointer_cast<PowerSupplyUnitActor>(
                               target.lock())) {
              supply->SetOutline(true);
            }
          }
        }
      }
    }
    if (prev_state_ != PowerState::kDisconnect) return;

    switch (current_state_) {
      case PowerState::kDisconnected: {
      } break;
      case PowerState::kDisconnect:
        wait_frame_ = 0;
        current_state_ = PowerState::kConnect;
        break;
      case PowerState::kConnect: {
        current_state_ = PowerState::kConnecting;

      } break;

      case PowerState::kConnecting:

        break;
      default:;
    }
    prev_state_ = current_state_;
  }

 private:
  bool disconnect_ = true;
};

class TransmitterDummyComponent : public TransmitterComponent {
 public:
  TransmitterDummyComponent(base_engine::Actor* owner, int update_order)
      : TransmitterComponent(owner, update_order) {}

  void Update() override {
    for (const auto& prev_target : prev_target_) {
      if (prev_target.expired()) continue;
      if (const auto target = prev_target.lock()->GetOwner();
          !target.expired()) {
        if (const auto beacon =
                std::dynamic_pointer_cast<BeaconActor>(target.lock())) {
          beacon->SetOutline(false);
        } else if (const auto supply =
                       std::dynamic_pointer_cast<PowerSupplyUnitActor>(
                           target.lock())) {
          supply->SetOutline(false);
        };
      }
    }
    const auto weak_ptr = owner_->GetComponent<TransmitterComponent>();

    for (const auto& receiver_weak : target_) {
      if (receiver_weak.expired()) continue;
      if (receiver_weak.lock()->Level() > Level()) continue;
      if (CoercionCondition(receiver_weak)) {
        connect_bindable_->BindConnect(receiver_weak.lock(), weak_ptr);
      }
    }
    prev_target_ = target_;
    std::erase_if(target_, [](const std::weak_ptr<ReceiverComponent>& a) {
      return a.expired();
    });
    std::erase_if(target_,
                  [&weak_ptr, this](const std::weak_ptr<ReceiverComponent>& a) {
                    return connect_bindable_->Constraints(a, weak_ptr);
                  });
    for (const auto& value : target_) {
      connect_bindable_->BindConnect(value.lock(), weak_ptr);
    }
    target_.clear();
  }

 private:
  std::deque<std::weak_ptr<ReceiverComponent>> prev_target_{};
};
class BeaconDummyReceiver final : public IReceivablePower {
 public:
  explicit BeaconDummyReceiver(class DummyEmptyBeaconActor* actor,
                               const base_engine::Vector2& position)
      : position_(position), actor_(actor) {
    actor->RegistryPart(this);
  };
  int Sequential() override { return actor_->Sequential(); }
  bool PowerJoinCondition() override { return true; }
  void OnPowerEnter(class TransmitterComponent* transmitter) override {
    actor_->SetElectric(true);
  }
  void OnPowerChanged(TransmitterComponent* transmitter) override {}
  void OnPowerExit(TransmitterComponent* transmitter) override {
    if (!transmitter) return;
    if (const auto target = transmitter->GetOwner(); !target.expired()) {
      if (const auto beacon =
              std::dynamic_pointer_cast<BeaconActor>(target.lock())) {
        beacon->SetOutline(false);
      } else if (const auto supply =
                     std::dynamic_pointer_cast<PowerSupplyUnitActor>(
                         target.lock())) {
        supply->SetOutline(false);
      };
      actor_->SetElectric(false);
    }
  }
  bool IsWireless() override { return false; }
  [[nodiscard]] base_engine::Vector2 GetPosition() const override {
    return {64, 64};
  }

 private:
  base_engine::Vector2 position_;
  class DummyEmptyBeaconActor* actor_;
};
class BeaconDummyTransmitter : public ISendablePower {
 public:
  explicit BeaconDummyTransmitter(class DummyEmptyBeaconActor* actor,
                                  base_engine::Vector2 position)
      : position_(position), actor_(actor) {
    actor->RegistryPart(this);
  }

  const ISendablePower* GetPrevious() override { return previous_; }
  void SetPrevious(ISendablePower* previous) override { previous_ = previous; }

  bool CanSending() override { return actor_->IsElectric(); }
  [[nodiscard]] base_engine::Vector2 GetPosition() const override { return {}; }

 private:
  base_engine::Vector2 position_;
  ISendablePower* previous_ = nullptr;

  DummyEmptyBeaconActor* actor_ = nullptr;
};

class ConnectBindDummy : public IConnectBindable {
 public:
  bool BindConnect(const std::shared_ptr<ReceiverComponent>& receiver,
                   std::weak_ptr<TransmitterComponent> transmitter) override {
    if (const auto target = receiver->GetOwner(); !target.expired()) {
      if (const auto beacon =
              std::dynamic_pointer_cast<BeaconActor>(target.lock())) {
        beacon->SetOutline(true);
      } else if (const auto supply =
                     std::dynamic_pointer_cast<PowerSupplyUnitActor>(
                         target.lock())) {
        supply->SetOutline(true);
      };
    }
    return true;
  }
  bool Constraints(
      const std::weak_ptr<ReceiverComponent>& receiver,
      const std::weak_ptr<TransmitterComponent>& transmitter) override {
    return (receiver.lock()->IsConnect() == true &&
            !receiver.lock()->EqualSender(transmitter)) ||
           TransmitterComponent::CoercionCondition(receiver) ||
           receiver.lock()->Level() > transmitter.lock()->Level();
  }

 private:
};

DummyEmptyBeaconActor::DummyEmptyBeaconActor(base_engine::Game* game)
    : Actor(game) {
  {
    const auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
    const auto circle = std::make_shared<base_engine::Circle>(
        cell_half.x, cell_half.y, kPowerRadius-20);
    if (kIsCollisionRenderMode) {
      const auto shape = new base_engine::ShapeRenderComponent(this, 110);
      shape->SetShape(circle);
      shape->SetFillMode(kElectricAreaFillMode).SetColor(kElectricAreaColor);
      RegistryPart(shape);
    }
    collision_ = new base_engine::CollisionComponent(this);
    collision_->SetShape(circle);
    collision_->SetObjectFilter(kBeaconObjectFilter);
    collision_->SetTargetFilter(kBeaconTargetFilter);
    collision_->SetTrigger(true);
  }
  {
    transmitter_ = new TransmitterDummyComponent(this, 100);
    transmitter_->Create<BeaconDummyTransmitter>(this, kBeaconReceiverOffset);
    transmitter_->CreateConnectBind<ConnectBindDummy>();

    receiver_ = new DummyReceiverComponent(this, 100);
    receiver_->Create<BeaconDummyReceiver>(this, kBeaconReceiverOffset);
  }
  SetName("BeaconPlan");
  SetTag("BeaconPlan");
}

DummyEmptyBeaconActor::~DummyEmptyBeaconActor() {}

void DummyEmptyBeaconActor::SetSequential(const int sequential) {
  sequential_ = sequential;
}

int DummyEmptyBeaconActor::Sequential() const { return sequential_; }

void DummyEmptyBeaconActor::Start() {}

void DummyEmptyBeaconActor::Input() {}

void DummyEmptyBeaconActor::Update() {
  const auto pos_opt = player_->SearchPlacePosition();
  if (!pos_opt.has_value()) {
    SetElectric(false);
    collision_->SetObjectFilter(CollisionLayer::kNone);
    collision_->SetTargetFilter(CollisionLayer::kNone);
  }
  if (prev_pos_ != pos_opt) {
    if (pos_opt.has_value()) {
      collision_->SetObjectFilter(kBeaconObjectFilter);
      collision_->SetTargetFilter(kBeaconTargetFilter);
      SetElectric(true);
      SetPosition(GridPosition::GridTo(pos_opt.value()));
      const auto num = (player_->MaxBeacon() - player_->GetBeacon() + 1) * 10;
      SetSequential(num);
    }
    prev_pos_ = pos_opt;
  }
}
