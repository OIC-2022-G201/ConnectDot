#include "ObjectLoader.h"

#include <fstream>
#include <variant>

#include "BinaryArchive.h"
#include "Frozen.h"
#include "LoadObjectParameter.h"
#include "PowerSupplyUnitActor.h"
#include "SignboardActor.h"

ObjectLoader::ObjectLoader(base_engine::Game* game) : game_(game) {}

void ObjectLoader::Load(const std::filesystem::path folder) {
  for (const std::filesystem::directory_entry& x :
       std::filesystem::recursive_directory_iterator(folder)) {
    if (auto path = x.path().relative_path(); path.extension() == ".bin") {
      CreateObject(path);
    }
  }
}

bool ObjectLoader::CreateObject(const std::filesystem::path path) {
  std::ifstream loading_file;
  LoadObject object;
  loading_file.open(path, std::ios::binary);
  {
    frozen::BinaryInputArchive i_archive(loading_file);
    i_archive(object);
  }
  loading_file.close();

  if (object.name == "Powersupply") {
    auto power_unit = new PowerSupplyUnitActor(game_);
    power_unit->Create(object);

    actor_map_[path.string()] = power_unit;
    bind_event_.emplace_back([power_unit, object, this]() {
        const auto key = std::get<LoadObject::Prefab>(object.parameters[4]).value.uuid;
      power_unit->SetTarget(actor_map_[key]);
    });
  } else if (object.name == "Signboard")
  {
      const auto signboard = new SignboardActor(game_);
    signboard->Create(object);
    actor_map_[path.string()] = signboard;
  }

  return true;
}
