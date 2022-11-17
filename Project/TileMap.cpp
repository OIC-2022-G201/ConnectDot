#include "TileMap.h"

#include <filesystem>
#include <fstream>

#include "BinaryArchive.h"
#include "Frozen.h"
#include "StringFrozen.h"
#include "VectorFrozen.h"
namespace tile_map {

struct FrozenMapData {
  std::string back_ground_path{};
  std::string map_chip_path{};
  int chip_size = 0;
  int map_max_x{};
  int map_max_y{};
  std::vector<std::vector<char>> tile_data{};
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(back_ground_path, map_chip_path, chip_size, map_max_x, map_max_y,
            tile_data);
  }
};

bool Layer::Load(const std::filesystem::path& path) {
  {
    FrozenMapData map_data;

    std::ifstream os(path, std::ios::binary);
    {
      frozen::BinaryInputArchive archive(os);
      archive(map_data);
    }
    os.close();

    x_ = map_data.map_max_x;
    y_ = map_data.map_max_y;
    layer_ = map_data.tile_data;
  }

  return true;
}
}  // namespace tile_map
