#include "TimeCounter.h"

std::unique_ptr<Stopwatch::TimeCounter> Stopwatch::TimeCounter::CreateNew() {
  std::unique_ptr<TimeCounter> time_counter(new TimeCounter());
  return time_counter;
}

void Stopwatch::TimeCounter::Update(const float add_time) {
  if(time_ >(99*60+59))return;
  if (!pause_) time_ += add_time;
}

float Stopwatch::TimeCounter::GetElapsedSeconds() const {
  return time_;
}

void Stopwatch::TimeCounter::Start() {
  pause_ = false;
}

void Stopwatch::TimeCounter::Stop() {
  pause_ = true;
}

void Stopwatch::TimeCounter::Reset() {
  time_ = 0;
}
