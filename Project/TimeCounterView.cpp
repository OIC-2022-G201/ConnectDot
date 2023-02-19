#include "TimeCounterView.h"

TimeCounterView::TimeCounterView(base_engine::Game* game) : Actor(game) {
	counter_component_ = new base_engine::CounterComponent(this, "Timer_Number");
	SetPosition({ 1730 ,51 });
	SetEnable(true);
	counter_component_->SetEnable(true);
	counter_component_->SetSpace(5);
}

TimeCounterView::~TimeCounterView() {
}

void TimeCounterView::OnEvent(GoalEvent&) {
	auto event = observable::Unit();
	goal_event_.OnNext(event);
}

void TimeCounterView::SetElapsedMinutes(int elapsed_minutes) {
	counter_component_->SetNumber(elapsed_minutes);
}

void TimeCounterView::SetElapsedSeconds(int elapsed_seconds) {
	counter_component_->SetNumber(elapsed_seconds);
}

void TimeCounterView::SetElapsedMilliseconds(int elapsed_milliseconds) {
	counter_component_->SetNumber(elapsed_milliseconds);
}
