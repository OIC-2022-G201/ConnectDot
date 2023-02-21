#include "ObjectLoader.h"

#include <fstream>

#include "BinaryArchive.h"
#include "Frozen.h"
#include "GimmickInjection.h"
#include "GimmickObjectLoadForUnity.h"
#include "LoadObjectParameter.h"
#include "TextArchive.h"


ObjectLoader::ObjectLoader(base_engine::Game* game) : game_(game), creator_(game_)
{
}

void ObjectLoader::Load(const std::filesystem::path& folder) {
  GimmickDiActorContainerSetup a{&creator_};
  for (const std::filesystem::directory_entry& x :
       std::filesystem::recursive_directory_iterator(folder)) {
    if (auto path = x.path().relative_path(); path.extension() == ".txt") {
      CreateObject(path);
    }
  }
  creator_.Bind();
}

bool ObjectLoader::CreateObject(const std::filesystem::path& path) {
  std::ifstream loading_file;
  LoadObject object;
  GimmickObjectLoadForUnity convert;
  const auto part_object = convert.GenerateObject(path);
  object.object = part_object;
  object.id = path.stem().string();
  object.name = part_object.name;
  if (object.name == "Beacon") return false;
  creator_.ActorCreate(object);



  return true;
}
