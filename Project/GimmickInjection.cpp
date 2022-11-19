#include "GimmickInjection.h"

#include <array>

#include "DIActorContainer.h"
#include "PowerSupplyUnitActor.h"
#include "SignboardActor.h"

using namespace base_engine;
using namespace std::string_view_literals;

#pragma region GimmickName
constexpr std::string_view kPowerSupplyName = "Powersupply"sv;
constexpr std::string_view kSignboardName = "Signboard"sv;
#pragma endregion
using CreatorMethod = Actor* (*)(GimmickCreator*, Game*, const LoadObject&);
using FactoryRegisterMethod = void (*)(GimmickCreator*,
                                       const std::string_view& key);

class GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl {
  using Impl = GimmickDiActorContainerSetupImpl;

 public:
  explicit GimmickDiActorContainerSetupImpl(GimmickCreator* creator);

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

constexpr std::array kGimmickMethodTable = {
    std::tuple{
        kPowerSupplyName, &SetupImpl::PowerSupplyCreate,
        &GimmickCreator::FactoryRegister<PowerSupplyUnitActor>},  // PowerSupply
    std::tuple{kSignboardName, &SetupImpl::SignboardCreate,
               &GimmickCreator::FactoryRegister<SignboardActor>},  // Signboard
    std::tuple{kSignboardName, &SetupImpl::SignboardCreate,
               &GimmickCreator::FactoryRegister<SignboardActor>}};

GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::
    GimmickDiActorContainerSetupImpl(GimmickCreator* creator)
    : creator_(creator) {
  for (const auto& gimmick_method_table : kGimmickMethodTable) {
    Register(std::get<0>(gimmick_method_table),
             std::get<1>(gimmick_method_table));
  }
}

Actor* GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl::
    PowerSupplyCreate(GimmickCreator* instance, Game* game,
                      const LoadObject& object) {
  const auto power_unit = new PowerSupplyUnitActor(game);
  power_unit->Create(object);

  instance->bind_event_.emplace_back([power_unit, object, instance]() {
    const auto& key =
        std::get<LoadObject::Prefab>(object.parameters[4]).value.uuid;

    if (!instance->actor_map_.contains(key)) return;
    power_unit->SetTarget(instance->actor_map_[key]);
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
