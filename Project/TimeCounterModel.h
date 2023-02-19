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
	void SetElapsedTime(double elapsed_time){ elapsed_time_  = elapsed_time;}
	[[nodiscard]] auto&& GetElapsedMinutes() { return static_cast<int>(static_cast<double>(elapsed_time_.ToReadOnly()) / 60); }
	[[nodiscard]] auto&& GetElapsedSeconds() { return static_cast<int>(static_cast<double>(elapsed_time_.ToReadOnly())) % 60; }
	[[nodiscard]] auto&& GetElapsedMilliseconds() { return static_cast<int>(fmod(static_cast<double>(elapsed_time_.ToReadOnly()) * 100, 100)); }
	void TimeCounterStart() const { time_counter_->Start(); }
	void TimeCounterStop() const { time_counter_->Stop(); }
	void TimeCounterReset() const { time_counter_->Reset(); }
	void TimeCounterReStart() const { time_counter_->ReStart(); }
};