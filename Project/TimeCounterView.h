#pragma once
#include "Actor.h"
#include "CounterComponent.h"
#include "EventHandler.h"
#include "GoalEvent.h"
#include "Subject.h"
#include "Unit.h"

class TimeCounterView :public base_engine::Actor,public  EventHandler<GoalEvent> {
public:
	void OnEvent(GoalEvent&) override;
	explicit  TimeCounterView(base_engine::Game* game);
	~TimeCounterView()override;
	void SetElapsedMinutes(int elapsed_minutes);
	void SetElapsedSeconds(int elapsed_seconds);
	void SetElapsedMilliseconds(int elapsed_milliseconds);

	[[nodiscard]] observable::IObservable<observable::Unit>& GetStartEvent() { return start_event_; }
	[[nodiscard]] observable::IObservable<observable::Unit>& GetGoalEvent() { return goal_event_; }
	[[nodiscard]] observable::IObservable<observable::Unit>& GetPauseEvent() { return pause_event_; }
	[[nodiscard]] observable::IObservable<observable::Unit>& GetReStartEvent() { return re_start_event_; }
private:
	base_engine::CounterComponent* counter_component_;
	observable::Subject<observable::Unit>start_event_;
	observable::Subject<observable::Unit>goal_event_;
	observable::Subject<observable::Unit>pause_event_;
	observable::Subject<observable::Unit>re_start_event_;
};