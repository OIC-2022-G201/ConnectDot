#pragma once
#include <chrono>

namespace Stopwatch {
  class TimeCounter
  {
    bool is_running_ = false;
    std::chrono::system_clock::time_point begin_;// �J�n����
    std::chrono::system_clock::time_point end_;// �J�n����
    std::chrono::nanoseconds elapsed_;// ���v����
    TimeCounter() = default;
  public:
    ~TimeCounter() = default;
    double GetElapsedSeconds()const;
    static std::unique_ptr<TimeCounter> CreateNew();
    void Start();
    void Stop();
    void ReStart();
    void Reset();
  private:
    template <typename T, class Unit>
    [[nodiscard]] T GetElapsed()const;
  };
}