﻿#include "GimmickInjection.h"

#include <array>

#include "DIActorContainer.h"
#include "LeverStubActor.h"
#include "MoveFloorStubActor.h"
#include "PowerSupplyUnitActor.h"
#include "RenderableStubActor.h"
#include "SignboardActor.h"

using namespace base_engine;
using namespace std::string_view_literals;

#pragma region GimmickName
constexpr std::string_view kDoorName = "Door"sv;
constexpr std::string_view kPowerSupplyName = "Powersupply"sv;
constexpr std::string_view kLeverName = "Lever"sv;
constexpr std::string_view kMoveFloorName = "Movefloor"sv;
constexpr std::string_view kVentName = "Vent"sv;
constexpr std::string_view kSignboardName = "Signboard"sv;
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
  static Actor* PowerSupplyCreate(GimmickCreator* instance, Game* game,
                                  const LoadObject& object);

  static Actor* SignboardCreate(GimmickCreator* instance, Game* game,
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
        kDoorName,                                 // Name
        &SetupImpl::EmptyCreate,                   // CreateMethod
        &Gc::FactoryRegister<RenderableStubActor>  // FactoryRegister
    },
    std::tuple{
        kPowerSupplyName,                           // Name
        &SetupImpl::PowerSupplyCreate,              // CreateMethod
        &Gc::FactoryRegister<PowerSupplyUnitActor>  // FactoryRegister
    },
    std::tuple{
        kLeverName,                                // Name
        &SetupImpl::LeverCreate,                   // CreateMethod
        &Gc::FactoryRegister<LeverStubActor>  // FactoryRegister
    },
    std::tuple{
        kMoveFloorName,                            // Name
        &SetupImpl::MoveFloorCreate,               // CreateMethod
        &Gc::FactoryRegister<MoveFloorStubActor>  // FactoryRegister
    },
    std::tuple{
        kVentName,                                 // Name
        &SetupImpl::EmptyCreate,                   // CreateMethod
        &Gc::FactoryRegister<RenderableStubActor>  // FactoryRegister
    },
    std::tuple{
        kSignboardName,                       // Name
        &SetupImpl::SignboardCreate,          // CreateMethod
        &Gc::FactoryRegister<SignboardActor>  // FactoryRegister
    },
};

GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::
    GimmickDiActorContainerSetupImpl(GimmickCreator* creator)
    : creator_(creator) {
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
    GimmickCreator* instance, Game* game,
    const LoadObject& object)
{
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
    power_unit->SetTarget(actor);
  });
  return power_unit;
}

Actor*
GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::SignboardCreate(
    GimmickCreator* instance, Game* game, const LoadObject& object) {
  const auto signboard = new SignboardActor(game);
  signboard->Create(object);

  return signboard;
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
    return DiActorContainer::Create<SignboardActor>(key, creator->game_,
                                                    std::forward<T0>(PH1));
  };
}

GimmickDiActorContainerSetup::GimmickDiActorContainerSetup(
    GimmickCreator* creator) {
  impl_ = std::make_shared<GimmickDiActorContainerSetupImpl>(creator);
}