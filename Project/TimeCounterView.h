#pragma once
#include "Actor.h"
#include "CounterComponent.h"
#include "EventHandler.h"
#include "GameOverEvent.h"
#include "GoalEvent.h"
#include "PauseEvent.h"
#include "QuitEvent.h"
#include "ReStartEvent.h"
#include "StageEpilogueEvent.h"
#include "Subject.h"
#include "Unit.h"

class TimeCounterView : public base_engine::Actor,
                        public EventHandler<PauseEvent>,
                        public EventHandler<GoalEvent>,
                        public EventHandler<StageEpilogueEvent>,
                        public EventHandler<ReStartEvent>,
                        public EventHandler<GameOverEvent>,
                        public EventHandler<QuitEvent> {
 public:
  void OnEvent(StageEpilogueEvent&) override;
  void OnEvent(GoalEvent&) override;
  void OnEvent(PauseEvent&) override;
  void OnEvent(ReStartEvent&) override;
  void OnEvent(GameOverEvent&) override;
  void OnEvent(QuitEvent&) override;

  explicit TimeCounterView(base_engine::Game* game);
  ~TimeCounterView() override;
  void SetElapsedMinutes(int elapsed_minutes);
  void SetElapsedSeconds(int elapsed_seconds);
  void SetElapsedMilliseconds(int elapsed_milliseconds);
  void Update() override;
  [[nodiscard]] auto&& GetStageEpilogueEvent() { return stage_epilogue_event_; }
  [[nodiscard]] auto&& GetGoalEvent() { return goal_event_; }
  [[nodiscard]] auto&& GetStartEvent() { return start_event_; }
  [[nodiscard]] auto&& GetStopEvent() { return stop_event_; }
  [[nodiscard]] auto&& GetReStartEvent() { return re_start_event_; }
  [[nodiscard]] auto&& GetGameOverEvent() { return game_over_event_; }
  [[nodiscard]] auto&& GetQuitEvent() { return quit_event_; }
  [[nodiscard]] auto&& GetUpdateEvent() { return update_event_; }

 private:
  base_engine::CounterComponent* minutes_counter_component_;
  base_engine::CounterComponent* seconds_counter_component_;
  base_engine::CounterComponent* milliseconds_counter_component_;
  observable::Subject<observable::Unit> stage_epilogue_event_;
  observable::Subject<observable::Unit> goal_event_;
  observable::Subject<observable::Unit> stop_event_;
  observable::Subject<observable::Unit> start_event_;
  observable::Subject<observable::Unit> re_start_event_;
  observable::Subject<observable::Unit> game_over_event_;
  observable::Subject<observable::Unit> quit_event_;
  observable::Subject<observable::Unit> update_event_;
};