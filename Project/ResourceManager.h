// @file ResourceManager.h
// @brief
// @author ICE
// @date 2022/09/24
//
// @details

#pragma once
#include "Resource.h"
#include "ResourcePack.h"
;
#include <algorithm>

namespace asset_system {
template <typename T>
concept IsResourcePack = requires(T t) {
  {
    asset_system::ResourcePack { std::move(t) }
    } -> std::same_as<T>;
};
template <typename T, class Elements>
concept IsTupleResourcePack = requires(T t) {
  tuple_holds_v<Elements, std::unordered_map<ResourceKey, typename T::Ptr>>;
};

/**
 * \brief Resource管理クラス
 * \tparam _ResourcePackTypes リソースパック型毎のマップ タプルを作る
 */
template <IsResourcePack... _ResourcePackTypes>
class ResourceManager {
  using Elements = std::tuple<
      std::unordered_map<ResourceKey, typename _ResourcePackTypes::Ptr>...>;

 public:
  /**
   * \brief ResourcePackを作成する
   * \tparam PackType リソースパック型
   * \param key 登録キー
   * \return 作成したResourcePack
   */
  template <IsResourcePack PackType>
  typename PackType::Ptr CreatePack(const ResourceKey& key) {
    auto re = std::make_shared<PackType>();
    std::get<std::unordered_map<ResourceKey, typename PackType::Ptr>>(
        elements_)[key] = re;
    return re;
  }

  /**
   * \brief ResourcePackを登録する
   * \tparam PackType リソースパック型
   * \param key 登録キー
   * \param pack 登録したいパック
   */
  template <IsTupleResourcePack<Elements> PackType>
  void RegisterPack(const ResourceKey& key, typename PackType::Ptr pack) {
    std::get<std::unordered_map<ResourceKey, typename PackType::Ptr>>(
        elements_)[key] = pack;
  }

  /**
   * \brief リソースパックを検索する
   * \tparam PackType リソースパック型
   * \param key 登録キー
   * \return Found: ResourcePack
   *         Not Found: ポインタ初期値
   */
  template <IsTupleResourcePack<Elements> PackType>
  typename PackType::Ptr FindPack(const ResourceKey& key) {
    const auto& resources =
        std::get<std::unordered_map<ResourceKey, typename PackType::Ptr>>(
            elements_);
    auto it = resources.find(key);
    if (it != resources.end()) {
      return it->second;
    }
    return PackType::Ptr();
  }

  /**
   * \brief Resourceを検索する
   * \tparam PackType リソースパック型
   * \tparam ResourceType リソース型
   * \param key 登録キー
   * \return Found: Resource
   *         Not Found: ポインタ初期値
   */
  template <IsTupleResourcePack<Elements> PackType, class ResourceType>
  typename PackType::Ptr FindResource(const ResourceKey& key) {
    const auto& resources =
        std::get<std::unordered_map<ResourceKey, typename PackType::Ptr>>(
            elements_);
    for (auto it : resources) {
      if (auto t = it.second->template Get<ResourceType>()->Get(key)) {
        return t;
      }
    }
    return ResourceValue<ResourceType>();
  }

 private:
  Elements elements_;
};
class Test {
 public:
  Test(int n) {}
  void test() {
    std::shared_ptr<Resource<int>> resource_value_int;
    std::shared_ptr<Resource<char>> resource_value_char;
    std::shared_ptr<Resource<float>> resource_value_float;
    std::shared_ptr<ResourcePack<int, char, double>> rs_int;
    rs_int->Register(resource_value_char);
    ResourceManager<ResourcePack<int, char, double>> manager;
    manager.RegisterPack<ResourcePack<int, char, double>>(0, rs_int);

    auto n = tuple_holds_v<std::tuple<int, char>, double>;
  }
};
}  // namespace asset_system
