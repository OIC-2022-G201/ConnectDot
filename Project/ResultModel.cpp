#include "ResultModel.h"

void ResultModel::Update(const float add_time) {
  if (!pause_) time_ += add_time;
}

void ResultModel::Pause() { pause_ = true; }

void ResultModel::Start() { pause_ = false; }

bool ResultModel::IsClearGoalTimes() const { return goal_time_ >= time_; }

void ResultModel::SetBeaconLimit(const uint16_t beacon_limit) {
  beacon_limit_ = beacon_limit;
}

void ResultModel::SetGoalTime(const float goal_time) { goal_time_ = goal_time; }

void ResultModel::SetPicUpDataChip(bool is_pick) {
  is_pick_data_chip_ = is_pick;
}

bool ResultModel::IsClearDataChip() const { return is_pick_data_chip_; }

void ResultModel::IncrementBeaconUsedTimes() { beacon_used_times_++; }

bool ResultModel::IsClearBeaconUsedTimes() const {
  return goal_beacon_ <= beacon_limit_ - beacon_used_times_;
}

float ResultModel::GetTime() const { return time_; }
