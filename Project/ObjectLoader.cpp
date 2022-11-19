#include "ObjectLoader.h"

#include <fstream>

#include "BinaryArchive.h"
#include "Frozen.h"
#include "GimmickInjection.h"
#include "LoadObjectParameter.h"



ObjectLoader::ObjectLoader(base_engine::Game* game) : game_(game), creator_(game_)
{
}

void ObjectLoader::Load(const std::filesystem::path folder) {
  GimmickDiActorContainerSetup a{&creator_};
  for (const std::filesystem::directory_entry& x :
       std::filesystem::recursive_directory_iterator(folder)) {
    if (auto path = x.path().relative_path(); path.extension() == ".bin") {
      CreateObject(path);
    }
  }
  creator_.Bind();
}

bool ObjectLoader::CreateObject(const std::filesystem::path& path) {
  std::ifstream loading_file;
  LoadObject object;
  loading_file.open(path, std::ios::binary);
  {
    frozen::BinaryInputArchive i_archive(loading_file);
    i_archive(object);
  }
  loading_file.close();

  creator_.ActorCreate(object);



  return true;
}
