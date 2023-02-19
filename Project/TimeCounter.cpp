#include "TimeCounter.h"

std::unique_ptr<Stopwatch::TimeCounter> Stopwatch::TimeCounter::CreateNew() {
  std::unique_ptr<TimeCounter> time_counter(new TimeCounter());
  return time_counter;
}

void Stopwatch::TimeCounter::Start() {
  if (is_running_) return;
	is_running_ = true;
	begin_ = end_ = std::chrono::system_clock::now();
}

void Stopwatch::TimeCounter::Stop() {
  if (!is_running_) return;
  is_running_ = false;
  end_ = std::chrono::system_clock::now();
  elapsed_ = elapsed_ + std::chrono::duration_cast<std::chrono::nanoseconds>(end_ - begin_);
}

void Stopwatch::TimeCounter::ReStart() {
	elapsed_ = std::chrono::nanoseconds(0);
	begin_ = end_ = std::chrono::system_clock::now();
}

void Stopwatch::TimeCounter::Reset() {
  Reset();
  Start();
}

template <typename T, class Unit>
T Stopwatch::TimeCounter::GetElapsed() const {
  if (is_running_){
    return std::chrono::duration_cast<std::chrono::duration<T, Unit>>
  	(std::chrono::system_clock::now() - this->begin_).count();
  }
  return std::chrono::duration_cast<std::chrono::duration<T, Unit>>(this->elapsed_).count();
}

double Stopwatch::TimeCounter::GetElapsedSeconds() const {
  return GetElapsed<double, std::ratio<1>>();
}