// @file DIActorContainer.h
// @brief
// @author ICE
// @date 2022/11/20
//
// @details

#pragma once
#include <functional>
#include <map>
#include <mutex>

#include "Actor.h"
#include "LoadObjectParameter.h"

class DiActorContainer {
  using ActorCreateFunc =
      std::function<base_engine::Actor*(base_engine::Game*, const LoadObject&)>;

 public:
  static void Register(const std::string_view name,
                       const ActorCreateFunc& function) {
    const auto hash = std::hash<std::string_view>()(name);

    // 追加済み確認
    if (container_.contains(hash)) {
      return;
    }

    container_[hash] = function;
  }

  template <class T>
  static T* Create(const std::string_view name, base_engine::Game* game,
                   const LoadObject& object) {
    const auto hash = std::hash<std::string_view>()(name);

    // 排他制御
    static std::recursive_mutex mutex;
    std::unique_lock lock(mutex);

    // 生成情報無し
    if (!container_.contains(hash)) {
      return nullptr;
    }

    // インスタンスを作成
    auto instance = container_[hash](game, object);
    auto result = dynamic_cast<T*>(instance);

    // インスタンスを返す
    return result;
  }

  static void Clear() { container_.clear(); }

 private:
  /*
    DIコンテナ情報
  */
  static std::map<size_t, ActorCreateFunc> container_;
};
