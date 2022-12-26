// @file ComponentServiceLocator.h
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

template <class T, class Tag>
struct Warp {
  T value;
};

class ComponentServiceLocator {
 public:
  ComponentServiceLocator() : instances_(), creators_() {}
  ~ComponentServiceLocator() { clear(); }
  static ComponentServiceLocator& Instance();

  void clear() {
    instances_.clear();
    creators_.clear();
  }

  template <typename T>
  void RegisterInstance(std::shared_ptr<T> instance) {
    const size_t hash = typeid(T).hash_code();
    if (instances_.contains(hash)) {
      instances_[hash] = instance;
      return;
    }
    instances_.emplace(hash, std::weak_ptr<void>(instance));
  }
  template <typename T>
  void RegisterInstance(std::weak_ptr<T> instance) {
    const size_t hash = typeid(T).hash_code();
    if (instances_.contains(hash)) {
      instances_[hash] = instance;
      return;
    }
    instances_.emplace(hash, instance);
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
      return std::static_pointer_cast<T>(itr1->second.lock());

    if (const auto itr2 = creators_.find(hash); itr2 != creators_.end())
      return std::static_pointer_cast<T>(itr2->second());

    return nullptr;
  }

 private:
  std::unordered_map<size_t, std::weak_ptr<void>> instances_;
  std::unordered_map<size_t, std::function<std::shared_ptr<void>()>> creators_;
};

class ServiceLocator {
 public:
  ServiceLocator() : instances_(), creators_() {}
  ~ServiceLocator() { clear(); }
  static ServiceLocator& Instance();

  void clear() {
    instances_.clear();
    creators_.clear();
  }

  template <typename T>
  void RegisterInstance(const std::shared_ptr<T>& instance) {
    const size_t hash = typeid(T).hash_code();
    if (instances_.contains(hash)) {
      instances_[hash] = instance;
      return;
    }
    instances_.emplace(hash, instance);
  }
  template <typename T>
  void RegisterInstance(const std::weak_ptr<T>& instance) {
    const size_t hash = typeid(T).hash_code();
    if (instances_.contains(hash)) {
      instances_[hash] = instance.lock();
      return;
    }
    instances_.emplace(hash, instance.lock());
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
inline ComponentServiceLocator& ComponentServiceLocator::Instance() {
  static ComponentServiceLocator instance_;
  return instance_;
}
inline ServiceLocator& ServiceLocator::Instance() {
  static ServiceLocator instance_;
  return instance_;
}
