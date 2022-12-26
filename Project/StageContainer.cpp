#include "StageContainer.h"

namespace fs = std::filesystem;
bool StageContainer::Load()
{
  for (const fs::directory_entry& x : fs::directory_iterator("MapData")) {
    if (const auto path = x.path().relative_path(); path.extension() == ".bin") {
      const auto directory = path.parent_path() / path.stem();
      stage_map_.emplace(path.stem().string(), std::pair{path, directory});
    }
  }
  return true;
}

bool StageContainer::Initialize() {
  Load();
	return true;
}

std::optional<StageContainer::StageDef> StageContainer::GetStage(const std::string& key)
{
	if (stage_map_.contains(key))
	{
		return stage_map_[key];
	}
	return std::nullopt;
}
