// @StubEvent.h
// @brief
// @author ICE
// @date 2022/12/06
// 
// @details

#pragma once
#include "Event.h"

class StubEvent final : public Event {
 public:
  explicit StubEvent(std::any& sender) : Event(sender) {}
};
