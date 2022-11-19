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


class GimmickDiActorContainerSetup::GimmickDiActorContainerSetupImpl {
  using Impl = GimmickDiActorContainerSetupImpl;

 public:
  explicit GimmickDiActorContainerSetupImpl(GimmickCreator* creator)
      : creator_(creator) {
    Register(kPowerSupplyName, &PowerSupplyCreate);
    Register(kSignboardName, &SignboardCreate);
  }

 private:
  static Actor* PowerSupplyCreate(GimmickCreator* instance, Game* game,
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
  static Actor* SignboardCreate(GimmickCreator* instance, Game* game,
                                const LoadObject& object) {
    const auto signboard = new SignboardActor(game);
    signboard->Create(object);

    return signboard;
  }

  void Register(const std::string_view name,
                Actor* (*create_method)(GimmickCreator*, Game*,
                                        const LoadObject&)) {
    DiActorContainer::Register(name, [this, create_method](auto p, auto a) {
      creator_->actor_map_[a.id] = (*create_method)(creator_, p, a);
      return creator_->actor_map_[a.id];
    });
  }

 private:
  GimmickCreator* creator_;
};

GimmickCreator::GimmickCreator(base_engine::Game* game) : game_(game) {
  FactoryRegister<PowerSupplyUnitActor>(kPowerSupplyName);
  FactoryRegister<SignboardActor>(kSignboardName);
}

Actor* GimmickCreator::ActorCreate(const LoadObject& object) {
  if (!create_map_.contains(object.name)) return nullptr;

  return create_map_[object.name](object);
}

void GimmickCreator::Bind() {
  for (auto&& bind_event : bind_event_) {
    bind_event();
  }
}

template <class T>
void GimmickCreator::FactoryRegister(const std::string_view& key) {
  create_map_[key] = [key, this]<typename T0>(T0&& PH1) {
    return DiActorContainer::Create<SignboardActor>(key, game_,
                                                    std::forward<T0>(PH1));
  };
}

GimmickDiActorContainerSetup::GimmickDiActorContainerSetup(
    GimmickCreator* creator) {
  impl_ = std::make_shared<GimmickDiActorContainerSetupImpl>(creator);
}
