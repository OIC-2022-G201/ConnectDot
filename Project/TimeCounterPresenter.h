#pragma once
#include <memory>

#include "EventBus.h"
#include "TimeCounterModel.h"
#include "TimeCounterView.h"

class TimeCounterPresenter{
	std::shared_ptr<TimeCounterModel> time_counter_model_;
	TimeCounterView* time_counter_view_ = nullptr;
	std::vector<std::shared_ptr<HandlerRegistration>> event_handlers_;
public:
	void Bind(){
		//model->view
		time_counter_model_->SetElapsedTime();
		time_counter_model_->GetElapsedTime().Subscribe([this](int elapsed_time) {
			time_counter_view_->SetElapsedMinutes(time_counter_model_->GetElapsedMinutes());
		});
		time_counter_model_->GetElapsedTime().Subscribe([this](int elapsed_time) {
			time_counter_view_->SetElapsedSeconds(time_counter_model_->GetElapsedSeconds());
		});
		time_counter_model_->GetElapsedTime().Subscribe([this](int elapsed_time) {
			time_counter_view_->SetElapsedMilliseconds(time_counter_model_->GetElapsedMilliseconds());
		});
		//view->model
		
		time_counter_view_->GetStageEpilogueEvent().Subscribe([this](auto) {time_counter_model_->TimeCounterStart(); });
		event_handlers_.emplace_back(EventBus::AddHandler<StageEpilogueEvent>(*time_counter_view_));

		time_counter_view_->GetGoalEvent().Subscribe([this](auto) {time_counter_model_->TimeCounterStop();});
		event_handlers_.emplace_back(EventBus::AddHandler<GoalEvent>(*time_counter_view_));

		time_counter_view_->GetStartEvent().Subscribe([this](auto) {time_counter_model_->TimeCounterResume(); });
		event_handlers_.emplace_back(EventBus::AddHandler<PauseEvent>(*time_counter_view_));

		time_counter_view_->GetStopEvent().Subscribe([this](auto) {time_counter_model_->TimeCounterStop(); });
		event_handlers_.emplace_back(EventBus::AddHandler<PauseEvent>(*time_counter_view_));

		time_counter_view_->GetReStartEvent().Subscribe([this](auto) {time_counter_model_->TimeCounterReStart(); });
		event_handlers_.emplace_back(EventBus::AddHandler<ReStartEvent>(*time_counter_view_));
		//ゲームオーバーいらないかも quitと同じ
		time_counter_view_->GetGameOverEvent().Subscribe([this](auto) {time_counter_model_->TimeCounterReset();});
		event_handlers_.emplace_back(EventBus::AddHandler<GameOverEvent>(*time_counter_view_));

		time_counter_view_->GetQuitEvent().Subscribe([this](auto) {time_counter_model_->TimeCounterReset();});
		event_handlers_.emplace_back(EventBus::AddHandler<QuitEvent>(*time_counter_view_));

		time_counter_view_->GetUpdateEvent().Subscribe([this](auto) { time_counter_model_->SetElapsedTime(); });

	}
	void SetTimeCounterView(TimeCounterView* time_counter_view) { time_counter_view_ = time_counter_view; }
	void SetTimeCounterModel(const std::shared_ptr<TimeCounterModel>& time_counter_model) { time_counter_model_ = time_counter_model; }
	[[nodiscard]] std::shared_ptr<TimeCounterModel> GetTimeCounterModel() const {return time_counter_model_;}
};