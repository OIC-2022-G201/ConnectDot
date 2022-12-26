// @StageContainer.h
// @brief
// @author ICE
// @date 2022/12/27
//
// @details

#pragma once
#include <filesystem>
#include <string>
#include <unordered_map>
#include <utility>
class StageContainer {
  using MapTilePath = std::filesystem::path;
  using ObjectsDirectory = std::filesystem::path;
  using StageDef = std::pair<MapTilePath, ObjectsDirectory>;

  std::unordered_map<std::string, StageDef> stage_map_;

  bool Load();

public:
  bool Initialize();

  std::optional<StageDef> GetStage(const std::string& key);
};
