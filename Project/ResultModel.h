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

  bool pause_ = true;

  float time_ = 0;

 public:
  
  // Control

  void Update(const float add_time);
  void Pause();
  void Start();

  void IncrementFoundCount();

  void IncrementBeaconUsedTimes();

  // Get

  [[nodiscard]] uint16_t GetFoundCount() const;

  [[nodiscard]] uint16_t GetBeaconUsedTimes() const;
  [[nodiscard]] float GetTime() const;
};
