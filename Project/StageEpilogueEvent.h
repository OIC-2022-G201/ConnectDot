// @StageEpilogueEvent.h
// @brief
// @author ICE
// @date 2022/12/12
//
// @details

#pragma once
#include "Event.h"

class StageEpilogueEvent final : public Event {
 public:
  explicit StageEpilogueEvent(std::any& sender) : Event(sender) {}
};
