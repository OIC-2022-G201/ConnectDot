#pragma once
#include <chrono>

namespace Stopwatch {
  class TimeCounter
  {
    bool is_running_ = false;
    std::chrono::system_clock::time_point begin_;// 開始時間
    std::chrono::system_clock::time_point end_;// 開始時間
    std::chrono::nanoseconds elapsed_;// 合計時間
  public:
    ~TimeCounter() = default;
    TimeCounter(TimeCounter&&) = default;

    bool IsRunning() const { return is_running_; }
    template <typename T, class Unit>
    [[nodiscard]] T GetElapsed()const;
    double GetElapsedSeconds()const;
    static std::unique_ptr<TimeCounter> CreateNew();
    void Start();
    void Stop();
    void ReStart();
    void Reset();
  private:
    TimeCounter() = default;
  };
}


