#include "ResultModel.h"

void ResultModel::Update(const float add_time)
{
	if (!pause_) time_ += add_time;
}

void ResultModel::Pause(){ pause_ = true; }

void ResultModel::Start(){ pause_ = false; }

void ResultModel::IncrementFoundCount()
{
	found_count_++;
	found_count_ %= 999;
}

void ResultModel::IncrementBeaconUsedTimes()
{
	beacon_used_times_++;
	beacon_used_times_ %= 999;
}

uint16_t ResultModel::GetFoundCount() const
{ return found_count_; }

uint16_t ResultModel::GetBeaconUsedTimes() const
{
	return beacon_used_times_;
}

float ResultModel::GetTime() const
{ return time_; }
