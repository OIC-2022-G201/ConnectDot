#include "TimeCounterView.h"
#include "ResourceContainer.h"
using RC = ResourceContainer;
TimeCounterView::TimeCounterView(base_engine::Game* game) : Actor(game) {
	minutes_counter_component_ = new base_engine::CounterComponent(this, "Timer_Number");
	seconds_counter_component_ = new base_engine::CounterComponent(this, "Timer_Number");
	milliseconds_counter_component_ = new base_engine::CounterComponent(this, "Timer_Number");

	SetEnable(true);
	SetPosition({ 1720, 51 });
	minutes_counter_component_->SetEnable(true);
	seconds_counter_component_->SetEnable(true);
	milliseconds_counter_component_->SetEnable(true);
	minutes_counter_component_->SetSpace(5);
	seconds_counter_component_->SetSpace(5);
	milliseconds_counter_component_->SetSpace(5);

	{
		auto actor = new Actor(game);
		auto sprite = new base_engine::ImageComponent(actor, 1000);
		actor->SetPosition({ 1730 ,51 });
		sprite->SetImage(*RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("Timer_Frame"));
	}
}

TimeCounterView::~TimeCounterView() {
}

void TimeCounterView::OnEvent(StageEpilogueEvent& e) {
	auto event = observable::Unit();
	stage_epilogue_event_.OnNext(event);
}

void TimeCounterView::OnEvent(GoalEvent& e) {
	auto event = observable::Unit{};
	stop_event_.OnNext(event);
}

void TimeCounterView::OnEvent(PauseEvent& e) {
	auto event = observable::Unit{};
	if (e.IsOpen()) {
		stop_event_.OnNext(event);
	}
	else if(e.IsClose()){
		start_event_.OnNext(event);
	}
}

void TimeCounterView::OnEvent(ReStartEvent& e) {
	auto event = observable::Unit{};
	re_start_event_.OnNext(event);
}

void TimeCounterView::OnEvent(GameOverEvent& e) {
	auto event = observable::Unit{};
	game_over_event_.OnNext(event);
}

void TimeCounterView::OnEvent(QuitEvent& e) {
	auto event = observable::Unit{};
	quit_event_.OnNext(event);
}

void TimeCounterView::SetElapsedMinutes(int elapsed_minutes) {
	minutes_counter_component_->SetOffset({ 0, 0 });
	minutes_counter_component_->SetNumber(elapsed_minutes);
}

void TimeCounterView::SetElapsedSeconds(int elapsed_seconds) {
	seconds_counter_component_->SetOffset({ 53, 0 });
	seconds_counter_component_->SetNumber(elapsed_seconds);
}

void TimeCounterView::SetElapsedMilliseconds(int elapsed_milliseconds) {
	milliseconds_counter_component_->SetOffset({ 105, 0 });
	milliseconds_counter_component_->SetNumber(elapsed_milliseconds);
}

void TimeCounterView::Update()
{
	observable::Unit event;
	update_event_.OnNext(event);
}
