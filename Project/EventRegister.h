// @EventRegister.h
// @brief
// @author ICE
// @date 2022/12/05
//
// @details

#pragma once
#include <memory>

class EventRegister {
 public:
  class Impl;
  EventRegister();
  void Register() const;

 private:
  std::shared_ptr<Impl> impl_;
};
