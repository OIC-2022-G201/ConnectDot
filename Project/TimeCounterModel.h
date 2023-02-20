#pragma once

#include "ReactiveProperty.h"
#include "TimeCounter.h"

class TimeCounterModel{
	observable::ReactiveProperty<double> elapsed_time_ = 0.0;
	std::unique_ptr<Stopwatch::TimeCounter> time_counter_ = Stopwatch::TimeCounter::CreateNew();
public:
	[[nodiscard]] auto&& GetElapsedTime() {
		return elapsed_time_.ToReadOnly();
	}
	void SetElapsedTime() {
		/*time_counter_->Start();
		time_counter_->Stop();*/
		elapsed_time_  = time_counter_->GetElapsedSeconds();
	}
	[[nodiscard]] auto&& GetElapsedMinutes() {
		return static_cast<int>(static_cast<double>(elapsed_time_.ToReadOnly()) / 60);
	}
	[[nodiscard]] int GetElapsedSeconds() {
		return static_cast<int>(static_cast<double>(elapsed_time_)) % 60;
	}
	[[nodiscard]] auto&& GetElapsedMilliseconds() {
		return static_cast<int>(fmod(static_cast<double>(elapsed_time_.ToReadOnly()) * 100, 100));
	}
	void TimeCounterStart()  { time_counter_->Start(); }
	void TimeCounterStop() { time_counter_->Stop();}
	void TimeCounterReset() { time_counter_->Reset(); }
	void TimeCounterReStart() { time_counter_->ReStart(); }
};