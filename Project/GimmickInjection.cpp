#include "GimmickInjection.h"

#include <array>

#include "CollapsibleBlockActor.h"
#include "DIActorContainer.h"
#include "DoorComponent.h"
#include "ElevatorComponent.h"
#include "EnemyActor.h"
#include "GoalComponent.h"
#include "LeverStubActor.h"
#include "MoveFloorStubActor.h"
#include "PlayerActor.h"
#include "PowerSupplyUnitActor.h"
#include "PylonActor.h"
#include "RenderableStubActor.h"
#include "SignboardActor.h"
#include "VentComponent.h"
#include "NotPutFloorActor.h"

using namespace base_engine;
using namespace std::string_view_literals;

#pragma region GimmickName
constexpr std::string_view kDoorName = "Door"sv;
constexpr std::string_view kPowerSupplyName = "Powersupply"sv;
constexpr std::string_view kMultiPowerSupplyName = "MultiPowersupply"sv;
constexpr std::string_view kMultiRemotePowerSupplyName = "MultiRemotePowersupply"sv;
constexpr std::string_view kStartPowerSupplyName = "StartPowersupply"sv;
constexpr std::string_view kLeverName = "Lever"sv;
constexpr std::string_view kMoveFloorName = "Movefloor"sv;
constexpr std::string_view kVentName = "Vent"sv;
constexpr std::string_view kSignboardName = "Signboard"sv;
constexpr std::string_view kEnemyName = "Enemy"sv;
constexpr std::string_view kGoalName = "Goal"sv;
constexpr std::string_view kElevatorName = "Elevator"sv;
constexpr std::string_view kCollapsibleBlockName = "CollapsibleBlock"sv;
constexpr std::string_view kPlayerSpawn = "PlayerSpawnPosition"sv;
constexpr std::string_view kNotPutFloorName = "NotPutFloor"sv;
#pragma endregion
using CreatorMethod = Actor* (*)(GimmickCreator*, Game*, const LoadObject&);
using FactoryRegisterMethod = void (*)(GimmickCreator*,
                                       const std::string_view& key);

class GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl {
  using Impl = GimmickDiActorContainerSetupImpl;

 public:
  explicit GimmickDiActorContainerSetupImpl(GimmickCreator* creator);

  static Actor* EmptyCreate(GimmickCreator* instance, Game* game,
                            const LoadObject& object);
  static Actor* LeverCreate(GimmickCreator* instance, Game* game,
                            const LoadObject& object);

  static Actor* MoveFloorCreate(GimmickCreator* instance, Game* game,
                                const LoadObject& object);
  static Actor* NotPutFloorCreate(GimmickCreator* instance, Game* game,
                                  const LoadObject& object);

  static Actor* PowerSupplyCreate(GimmickCreator* instance, Game* game,
                                  const LoadObject& object);
  static Actor* MultiPowerSupplyCreate(GimmickCreator* instance, Game* game,
                                       const LoadObject& object);
  static Actor* MultiRemotePowerSupplyCreate(GimmickCreator* instance, Game* game,
                                       const LoadObject& object);
  static Actor* PylonCreate(GimmickCreator* instance, Game* game,
                            const LoadObject& object);
  static Actor* SignboardCreate(GimmickCreator* instance, Game* game,
                                const LoadObject& object);
  static Actor* GoalCreate(GimmickCreator* instance, Game* game,
                           const LoadObject& object);
  static Actor* VentCreate(GimmickCreator* instance, Game* game,
                           const LoadObject& object);
  static Actor* EnemyCreate(GimmickCreator* instance, Game* game,
                            const LoadObject& object);

  static Actor* DoorCreate(GimmickCreator* instance, Game* game,
                           const LoadObject& object);
  static Actor* CollapsibleBlockCreate(GimmickCreator* instance, Game* game,
                                       const LoadObject& object);
  static Actor* ElevatorCreate(GimmickCreator* instance, Game* game,
                                       const LoadObject& object);
  static Actor* PlayerCreate(GimmickCreator* instance, Game* game,
                               const LoadObject& object);
  void Register(const std::string_view name, CreatorMethod create_method);

 private:
  GimmickCreator* creator_;
};
using SetupImpl =
    GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl;
using Gc = GimmickCreator;
constexpr std::array kGimmickMethodTable = {
    std::tuple{
        kDoorName,                       // Name
        &SetupImpl::DoorCreate,          // CreateMethod
        &Gc::FactoryRegister<DoorActor>  // FactoryRegister
    },
    std::tuple{
        kCollapsibleBlockName,                       // Name
        &SetupImpl::CollapsibleBlockCreate,          // CreateMethod
        &Gc::FactoryRegister<CollapsibleBlockActor>  // FactoryRegister
    },
    std::tuple{
        kPowerSupplyName,                           // Name
        &SetupImpl::PowerSupplyCreate,              // CreateMethod
        &Gc::FactoryRegister<PowerSupplyUnitActor>  // FactoryRegister
    },
    std::tuple{
        kMultiPowerSupplyName,                      // Name
        &SetupImpl::MultiPowerSupplyCreate,         // CreateMethod
        &Gc::FactoryRegister<PowerSupplyUnitActor>  // FactoryRegister
    },

    std::tuple{
        kMultiRemotePowerSupplyName,                      // Name
        &SetupImpl::MultiRemotePowerSupplyCreate,         // CreateMethod
        &Gc::FactoryRegister<PowerSupplyUnitActor>  // FactoryRegister
    },
    std::tuple{
        kStartPowerSupplyName,            // Name
        &SetupImpl::PylonCreate,          // CreateMethod
        &Gc::FactoryRegister<PylonActor>  // FactoryRegister
    },
    std::tuple{
        kLeverName,                           // Name
        &SetupImpl::LeverCreate,              // CreateMethod
        &Gc::FactoryRegister<LeverStubActor>  // FactoryRegister
    },
    std::tuple{
        kMoveFloorName,                           // Name
        &SetupImpl::MoveFloorCreate,              // CreateMethod
        &Gc::FactoryRegister<MoveFloorStubActor>  // FactoryRegister
    },
    std::tuple{
        kVentName,                       // Name
        &SetupImpl::VentCreate,          // CreateMethod
        &Gc::FactoryRegister<VentActor>  // FactoryRegister
    },
    std::tuple{
        kSignboardName,                       // Name
        &SetupImpl::SignboardCreate,          // CreateMethod
        &Gc::FactoryRegister<SignboardActor>  // FactoryRegister
    },
    std::tuple{
        kEnemyName,                              // Name
        &SetupImpl::EnemyCreate,                 // CreateMethod
        &Gc::FactoryRegister<enemy::EnemyActor>  // FactoryRegister
    },
    std::tuple{
        kGoalName,                       // Name
        &SetupImpl::GoalCreate,          // CreateMethod
        &Gc::FactoryRegister<GoalActor>  // FactoryRegister
    },
    std::tuple{
        kElevatorName,                       // Name
        &SetupImpl::ElevatorCreate,      // CreateMethod
        &Gc::FactoryRegister<ElevatorActor>  // FactoryRegister
    },
    std::tuple{
        kPlayerSpawn,                       // Name
        &SetupImpl::PlayerCreate,          // CreateMethod
        &Gc::FactoryRegister<player::PlayerActor>  // FactoryRegister
    },
    std::tuple{
        kNotPutFloorName,                       // Name
        &SetupImpl::NotPutFloorCreate,          // CreateMethod
        &Gc::FactoryRegister<NotPutFloorActor>  // FactoryRegister
    },
};

GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::
    GimmickDiActorContainerSetupImpl(GimmickCreator* creator)
    : creator_(creator) {
  DiActorContainer::Clear();
  for (const auto& gimmick_method_table : kGimmickMethodTable) {
    Register(std::get<0>(gimmick_method_table),
             std::get<1>(gimmick_method_table));
  }
}

Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::EmptyCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto empty = new RenderableStubActor(game);
  empty->Create(object);

  return empty;
}
Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::LeverCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto lever = new LeverStubActor(game);
  lever->Create(object);
  instance->bind_event_.emplace_back([lever, object, instance]() {
    const auto& key =
        std::get<LoadObject::Prefab>(object.parameters[4]).value.uuid;

    if (!instance->actor_map_.contains(key)) return;
    lever->SetTarget(instance->actor_map_[key]);
  });
  return lever;
}

Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::MoveFloorCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto lever = new MoveFloorStubActor(game);
  lever->Create(object);

  return lever;
}

Actor* GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::
    PowerSupplyCreate(GimmickCreator* instance, Game* game,
                      const LoadObject& object) {
  const auto power_unit = new PowerSupplyUnitActor(game);
  power_unit->Create(object);

  instance->bind_event_.emplace_back([power_unit, object, instance, game]() {
    const auto& key =
        std::get<LoadObject::Prefab>(object.parameters[4]).value.uuid;

    if (!instance->actor_map_.contains(key)) return;
    const auto actor = game->GetActor(instance->actor_map_[key]->GetId());
    power_unit->AddTarget(actor);
  });
  return power_unit;
}

Actor* GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::
	NotPutFloorCreate(GimmickCreator* instance, Game* game, const LoadObject& object)
{
    const auto notput_floor = new NotPutFloorActor(game);
    notput_floor->Create(object);
    return notput_floor;
}


Actor* GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::
    MultiPowerSupplyCreate(GimmickCreator* instance, Game* game,
                           const LoadObject& object) {
  const auto power_unit = new PowerSupplyUnitActor(game);
  power_unit->Create(object);

  instance->bind_event_.emplace_back([power_unit, object, instance, game]() {


    for (int i = 4; i < 8; ++i)
    {
      const auto& key =
          std::get<LoadObject::Prefab>(object.parameters[i]).value.uuid;
      if (!instance->actor_map_.contains(key)) continue;;
      const auto actor = game->GetActor(instance->actor_map_[key]->GetId());
      power_unit->AddTarget(actor); 
    }
  });
  return power_unit;
}

Actor* GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::MultiRemotePowerSupplyCreate(
	GimmickCreator* instance, Game* game, const LoadObject& object)
{
  const auto power_unit = new PowerSupplyUnitActor(game);
  power_unit->SetCanRemote(true);
  power_unit->Create(object);

  instance->bind_event_.emplace_back([power_unit, object, instance, game]() {
    for (int i = 4; i < 12; ++i) {
      const auto& key =
          std::get<LoadObject::Prefab>(object.parameters[i]).value.uuid;
      if (!instance->actor_map_.contains(key)) continue;
      ;
      const auto actor = game->GetActor(instance->actor_map_[key]->GetId());
      power_unit->AddTarget(actor);
    }
  });
  return power_unit;
}

Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::PylonCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto pylon = new PylonActor(game);
  pylon->Create(object);

  return pylon;
}

Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::SignboardCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto signboard = new SignboardActor(game);
  signboard->Create(object);

  return signboard;
}

Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::GoalCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto goal = new GoalActor(game);
  goal->Create(object);

  return goal;
}

Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::VentCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto vent = new VentActor(game);
  vent->Create(object);

  return vent;
}

Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::DoorCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto door = new DoorActor(game);
  door->Create(object);

  return door;
}

Actor* GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::
    CollapsibleBlockCreate(GimmickCreator* instance, Game* game,
                           const LoadObject& object) {
  const auto block = new CollapsibleBlockActor(game);
  block->Create(object);

  return block;
}

Actor* GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::ElevatorCreate(GimmickCreator* instance,
	Game* game, const LoadObject& object)
{
  const auto elevator = new ElevatorActor(game);
  elevator->Create(object);
  return elevator;
}

Actor* GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::PlayerCreate(GimmickCreator* instance,
    Game* game, const LoadObject& object)
{
  const auto player = new player::PlayerActor(game);
  player->Create(object);
  return player;
}

Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::EnemyCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto enemy = new enemy::EnemyActor(game);
  enemy->Create(object);
  return enemy;
}

void GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::Register(
    const std::string_view name, CreatorMethod create_method) {
  DiActorContainer::Register(name, [this, create_method](auto p, auto a) {
    creator_->actor_map_[a.id] = (*create_method)(creator_, p, a);
    return creator_->actor_map_[a.id];
  });
}

GimmickCreator::GimmickCreator(Game* game) : game_(game) {
  for (const auto& gimmick_method_table : kGimmickMethodTable) {
    std::get<2>(gimmick_method_table)(this, std::get<0>(gimmick_method_table));
  }
}

Actor* GimmickCreator::ActorCreate(const LoadObject& object) {
  if (!create_map_.contains(object.name)) return nullptr;

  return create_map_[object.name](object);
}

void GimmickCreator::Bind() const {
  for (auto&& bind_event : bind_event_) {
    bind_event();
  }
}

template <class T>
void GimmickCreator::FactoryRegister(GimmickCreator* creator,
                                     const std::string_view& key) {
  creator->create_map_[key] = [key, creator]<typename T0>(T0&& PH1) {
    return DiActorContainer::Create<T>(key, creator->game_,
                                       std::forward<T0>(PH1));
  };
}

GimmickDiActorContainerSetup::GimmickDiActorContainerSetup(
    GimmickCreator* creator) {
  impl_ = std::make_shared<GimmickDiActorContainerSetupImpl>(creator);
}
