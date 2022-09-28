// @file ServiceLocator.h
// @brief 
// @author ICE
// @date 2022/09/25
// 
// @details

#pragma once
#include <functional>
#include <memory>
#include <type_traits>
#include <unordered_map>

class ServiceLocator {
  inline static ServiceLocator* Instance = nullptr;
 public:
  ServiceLocator() : instances_(), creators_(){}
  ~ServiceLocator() { clear(); }

  void clear() {
    instances_.clear();
    creators_.clear();
  }

  template <typename T>
  void RegisterInstance(T* instance) {
    const size_t hash = typeid(T).hash_code();
    if (!instances_.contains(hash))
      instances_.emplace(hash, std::shared_ptr<void>(instance));
  }

  template <typename T>
  void RegisterCreator(std::function<std::shared_ptr<T>()> creator) {
    const size_t hash = typeid(T).hash_code();
    if (!creators_.contains(hash)) creators_.emplace(hash, creator);
  }

  template <typename T>
  std::shared_ptr<T> Resolve() const {
    const size_t hash = typeid(T).hash_code();
    if (const auto itr1 = instances_.find(hash); itr1 != instances_.end())
      return std::static_pointer_cast<T>(itr1->second);

    if (const auto itr2 = creators_.find(hash); itr2 != creators_.end())
      return std::static_pointer_cast<T>(itr2->second());

    return nullptr;
  }

 private:
  std::unordered_map<size_t, std::shared_ptr<void>> instances_;
  std::unordered_map<size_t, std::function<std::shared_ptr<void>()>> creators_;
};