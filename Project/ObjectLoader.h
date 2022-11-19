// @ObjectLoader.h
// @brief
// @author ICE
// @date 2022/11/18
//
// @details

#pragma once
#include <filesystem>
#include <functional>
#include <unordered_map>

#include "Actor.h"
#include "GimmickInjection.h"

namespace base_engine {
class Game;
}

class ObjectLoader {
 public:
  explicit ObjectLoader(base_engine::Game* game);

  /**
   * \brief
   * 指定されたフォルダーのパスを元にその中にあるオブジェクトファイルを探索して読み込みを行う
   * \param folder オブジェクトファイルの再帰全探索を行いたいルートフォルダ
   */
  void Load(const std::filesystem::path folder);

 private:
  bool CreateObject(const std::filesystem::path& path);

  base_engine::Game* game_ = nullptr;

  GimmickCreator creator_;
};
