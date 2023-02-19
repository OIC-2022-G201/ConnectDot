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
		time_counter_view_->SetElapsedMinutes(time_counter_model_->GetElapsedMinutes());
		time_counter_model_->GetElapsedTime().Subscribe([this](int elapsed_time) {
			time_counter_view_->SetElapsedMinutes(time_counter_model_->GetElapsedMinutes());
		});
		time_counter_view_->SetElapsedSeconds(time_counter_model_->GetElapsedSeconds());
		time_counter_model_->GetElapsedTime().Subscribe([this](int elapsed_time) {
			time_counter_view_->SetElapsedSeconds(time_counter_model_->GetElapsedSeconds());
		});
		time_counter_view_->SetElapsedMilliseconds(time_counter_model_->GetElapsedMilliseconds());
		time_counter_model_->GetElapsedTime().Subscribe([this](int elapsed_time) {
			time_counter_view_->SetElapsedMilliseconds(time_counter_model_->GetElapsedMilliseconds());
		});
		//view->model
		time_counter_view_->GetGoalEvent().Subscribe([this](auto) {time_counter_model_->TimeCounterStop();});
		event_handlers_.emplace_back(EventBus::AddHandler<GoalEvent>(*time_counter_view_));
	}
	void SetTimeCounterView(TimeCounterView* time_counter_view) { time_counter_view_ = time_counter_view; }
	void SetTimeCounterModel(const std::shared_ptr<TimeCounterModel>& time_counter_model) { time_counter_model_ = time_counter_model; }
	[[nodiscard]] std::shared_ptr<TimeCounterModel> GetTimeCounterModel() const {return time_counter_model_;}
};