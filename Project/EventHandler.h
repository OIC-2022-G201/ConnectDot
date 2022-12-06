// @EventHandler.h
// @brief
// @author ICE
// @date 2022/12/05
//
// @details

#pragma once
#include <type_traits>

#include "Event.h"

template <class T>
class EventHandler {
 public:
  EventHandler() {
    static_assert(std::is_base_of_v<Event, T>,
                  "EventHandler<T>: T must be a class derived from Event");
  }

  virtual ~EventHandler() {}

  virtual void OnEvent(T &) = 0;

  void dispatch(Event &e) { OnEvent(dynamic_cast<T &>(e)); }
};
