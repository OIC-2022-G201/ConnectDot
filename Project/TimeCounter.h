#pragma once
#include <chrono>

namespace Stopwatch {
  class TimeCounter
  {
    bool pause_ = true;
    float time_ = 0;
    TimeCounter() = default;
  public:
    ~TimeCounter() = default;
    static std::unique_ptr<Stopwatch::TimeCounter> CreateNew();
    [[nodiscard]] float GetElapsedSeconds()const;
    void Update(const float add_time);
    void Start();
    void Stop();
    void Reset();
  };
}