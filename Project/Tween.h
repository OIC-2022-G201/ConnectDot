// @Tween.h
// @brief
// @author ICE
// @date 2022/12/12
//
// @details

#pragma once
#include <optional>

#include "Component.h"
#include "EaseType.h"
#include "Easer.h"
#include "ITween.h"

namespace ma_tween {

/**
 * \brief Base class for all Tweens with a value type for the driver.
 * \tparam DriverValueType
 */
template <class DriverValueType>
class TweenDriver : public base_engine::Component, public core::ITween {
  using Driver = TweenDriver<DriverValueType>;

 public:
  explicit TweenDriver(base_engine::Actor* owner, const int update_order = 100)
      : Component(owner, update_order) {}

  float GetTotalDuration(bool include_delay) {}
  void Cancel() {}

  DriverValueType value_from_{};
  DriverValueType value_to_{};
  DriverValueType value_current_{};

  virtual bool OnInitialize() = 0;
  virtual DriverValueType OnGetFrom() = 0;
  virtual void OnUpdate(float easedTime) = 0;

 private:
  bool is_paused_ = false;
  float time_ = 0;
  EaseType ease_ = EaseType::kLinear;
  bool is_loop_ = false;

  /**
   * \brief from value overwrite flag.
   */
  bool did_overwrite_from_ = false;
  /**
   * \brief Definition of whether the tween has reached its end time.
   */
  bool did_time_reach_end_ = false;

  std::optional<float> duration_;
  std::optional<float> delay_;

  /**
   * \brief Definition of whether onStart was called when the tween starts.
   */
  bool did_trigger_on_start_ = false;
  /**
   * \brief The start callback invoke when the tween starts.
   */
  std::function<void()> on_start_;
  /**
   * \brief The complete callback invoke when the tween completes.
   */
  std::function<void()> on_complete_;
  /**
   * \brief The cancel callback invoke when the tween cancels.
   */
  std::function<void()> on_cancel_;

  bool is_completed_ = false;

 public:
  void Start() override {
    if (this->OnInitialize() == false) {
      Decommission();
    } else if (this->delay_.has_value() == false) {
      if (this->did_overwrite_from_ == false)
        this->value_from_ = this->OnGetFrom();
      this->OnUpdate(Easer::Apply(this->ease_, 0));
    }
  }
  void Update() {
    // When the tween is paused, we'll just wait.
    if (this->is_paused_ == true) return;
    // When the delay is active, the tween will wait for the delay to pass by.
    if (this->delay_) {
      this->delay_ -= 0.017f;
      if (this->delay_ <= 0) {
        this->delay_.reset();
        // When the delay is over, the valueFrom is requested from the
        // inheriter. Then the animation will be set to its first frame.
        if (this->did_overwrite_from_ == false)
          this->value_from_ = this->OnGetFrom();
        this->OnUpdate(Easer::Apply(this->ease_, 0));
      }
    }
    // When the tween has no duration, the timing will not be done and the
    // animation will be set to its last frame, the Tween will be
    // decomissioned right away.
    else if (this->duration_) {
      this->OnUpdate(Easer::Apply(this->ease_, 1));
      if (this->on_start_) this->on_start_();
      if (this->on_complete_) this->on_complete_();
      this->Decommission();
      return;
    }
    // Oterwise it is... Showtime!
    else {
      // Right before the tween will start, the onstart callback will be
      // invoked.
      if (did_trigger_on_start_ == false) {
        if (this->on_start_) this->on_start_();
        did_trigger_on_start_ = true;
      }
      // Increase or decrease the time of the tween based on the direction.
      auto time_delta = (0.017f) / this->duration_;
      this->time_ += time_delta;
      // The time will be capped to 1, when pingpong is enabled the tween will
      // play backwards, otherwise when the tween is not infinite, didReachEnd
      // will be set to true.
      if (this->time_ > 1) {
        this->time_ = 1;
        this->did_time_reach_end_ = true;
      }

      this->OnUpdate(Easer::Apply(this->ease_, this->time_));
      if (this->did_time_reach_end_ == true) {
        if (this->on_complete_) this->on_complete_();

        this->is_completed_ = true;
        this->Decommission();
      }
    }
  }
  Driver& SetFrom(DriverValueType value_from) {
    this->did_overwrite_from_ = true;
    this->value_from_ = value_from;
    return *this;
  }

  Driver& SetOnStart(std::function<void()> on_start) {
    this->on_start_ = on_start;
    return *this;
  }

  Driver& SetOnComplete(std::function<void()> on_complete) {
    this->on_complete_ = on_complete;
    return *this;
  }
  Driver& SetOnCancel(std::function<void()> on_cancel) {
    this->on_cancel_ = on_cancel;
    return *this;
  }

  template <class DriverType>
  static DriverType& Add(base_engine::Actor* actor) {
    return *(new DriverType(actor));
  }

  template <class DriverType>
  static DriverType& Add(base_engine::Component* component) {
    return *(new DriverType(component->GetOwner().lock().get()));
  }

 protected:
  float InterpolateValue(const float from, const float to, const float time) {
    return from * (1 - time) + to * time;
  }
  TweenDriver<DriverValueType>& Finalize(DriverValueType valueTo,
                                         float duration) {
    this->duration_ = duration;
    this->value_to_ = valueTo;

    return *this;
  }

 private:
  void Decommission() const { owner_->RemoveComponent(this); }
};
template <class DriverValueType, class ComponentType>
class Tween final : public TweenDriver<DriverValueType> {
 protected:
  std::weak_ptr<ComponentType> component_weak_;
 public:
  bool OnInitialize() override {
    this.component_weak_ = this->owner_->template GetComponent<ComponentType>();
    return !component_weak_.expired();
  }
};
}  // namespace ma_tween