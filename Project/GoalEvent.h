// @GoalEvent.h
// @brief
// @author ICE
// @date 2022/12/05
//
// @details

#pragma once
#include "Event.h"

class GoalEvent : public Event {
 public:
  explicit GoalEvent(std::any& sender) : Event(sender) {}

};
