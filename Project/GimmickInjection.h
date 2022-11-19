// @file GimmickInjection.h
// @brief
// @author ICE
// @date 2022/11/20
//
// @details

#pragma once

#include "Game.h"
#include "LoadObjectParameter.h"

class GimmickCreator {
 public:
  explicit GimmickCreator(base_engine::Game* game);

  base_engine::Actor* ActorCreate(const LoadObject& object);
  void Bind() const;
  std::unordered_map<std::string, base_engine::Actor*> actor_map_;
  std::vector<std::function<void()>> bind_event_;
  template <class T>
  static void FactoryRegister(GimmickCreator* creator,
                              const std::string_view& key);
 private:
  base_engine::Game* game_ = nullptr;
  using FactoryFunc = base_engine::Actor*(std::string_view, base_engine::Game*, const LoadObject&);


  std::unordered_map<std::string_view,
                     std::function<base_engine::Actor*(const LoadObject&)>>
      create_map_;

};
class GimmickDiActorContainerSetup {
 public:
  explicit GimmickDiActorContainerSetup(GimmickCreator* creator);

  class GimmickDiActorContainerSetupImpl;
 private:
  std::shared_ptr<GimmickDiActorContainerSetupImpl> impl_;
};