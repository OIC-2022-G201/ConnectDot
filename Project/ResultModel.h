// @ResultModel.h
// @brief
// @author ICE
// @date 2022/12/26
//
// @details

#pragma once
#include <cstdint>

class ResultModel {
  uint16_t found_count_ = 0;
  uint16_t beacon_used_times_ = 0;
  uint16_t beacon_limit_ = 20;
  uint16_t goal_beacon_ = 7;

  bool pause_ = true;
  float time_ = 0;
  float goal_time_ = 60;
  bool is_pick_data_chip = false;
 public:
  
  // Control

  void Update(const float add_time);
  void Pause();
  void Start();

  void IncrementBeaconUsedTimes();

  // Set

  void SetBeaconLimit(uint16_t beacon_limit);
  void SetGoalTime(const float goal_time);
  void SetPicUpDataChip(bool is_pick);

  // Get

  [[nodiscard]] bool IsClearBeaconUsedTimes() const;
  [[nodiscard]] bool IsClearGoalTimes() const;
  [[nodiscard]] bool IsClearDataChip() const;
  [[nodiscard]] float GetTime() const;
};
