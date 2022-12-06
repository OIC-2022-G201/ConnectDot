// @PlayerListener.h
// @brief
// @author ICE
// @date 2022/12/05
//
// @details

#pragma once
#include "EventHandler.h"
#include "GoalEvent.h"
#include "StubEvent.h"

class PlayerListener : public EventHandler<GoalEvent>,public EventHandler<StubEvent> {
 public:
  PlayerListener() = default;
  void OnEvent(GoalEvent& e) override {

    auto p = e.GetSender();
    auto value = std::any_cast<int>(p);
    int n = 3;
  }

  void OnEvent(StubEvent&) override
  {
      int n = 3;
  }
};
