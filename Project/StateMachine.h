#pragma once
#pragma once

#include <tuple>
#include <variant>

namespace til {
template <typename T, typename M>
concept Transitionable = requires(const T& t, M& m) {
  t.Transition(m);
};

template <typename T>
concept Startable = requires(T& t) {
  t.Start();
};
template <typename T>
concept Callable = requires(T& t) {
  t.Update();
};
template <typename T>
concept Endable = requires(T& t) {
  t.End();
};
template <typename T>
concept Inputable = requires(T& t) {
  t.ProcessInput();
};

template <typename T, typename... Args>
concept Eventable = requires(T& t, Args&&... args) {
  t.OnEvent(args...);
};

template <Callable... States>
class Machine {
 public:
  Machine() = default;

  explicit Machine(States&&... states)
      : states_{std::make_tuple(states...)},
        current_{&std::get<0>(this->states_)} {}

  Machine(const Machine&) = default;
  Machine& operator=(const Machine&) = default;

  Machine(Machine&&) = default;
  Machine& operator=(Machine&&) = default;

  ~Machine() = default;

  void ProcessInput() {
    auto visitor = [](auto* state) {
      if constexpr (Inputable<decltype(*state)>) state->ProcessInput();
    };
    std::visit(visitor, current_);
  }

  template <typename... Events>
  void OnEvent(Events&&... inputs) {
    auto visitor = [&inputs...](auto* state) {
      if constexpr (Eventable<decltype(*state),Events...>)
        state->OnEvent(std::forward<Events>(inputs)...);
    };
    std::visit(visitor, current_);
  }
  void Update() {
    auto visitor = [](auto* state) {
      if constexpr (Callable<decltype(*state)>) state->Update();
    };
    std::visit(visitor, current_);

    Transition();
  }

  template <Callable S>
  void TransitionTo() noexcept {
    std::visit(
        [](auto* state) {
          if constexpr (Endable<decltype(*state)>) {
            state->End();
          }
        },
        current_);

    current_ = &std::get<S>(states_);

    auto visitor = [](auto* state) {
      if constexpr (Startable<decltype(*state)>) {
        state->Start();
      }
    };
    std::visit(visitor, current_);
  }

  template <Callable State>
  const State& get_state() const noexcept {
    return std::get<State>(states_);
  }

  [[nodiscard]] size_t current_state() const noexcept {
    return current_.index();
  }

  void Reset() {
    states_ = std::make_tuple<States...>();
    current_ = &std::get<0>(states_);
  }

 private:
  void Transition() {
    auto visitor = [this](const auto* state) {
      // we can only Transition from non-terminal states
      if constexpr (Transitionable<decltype(*state), decltype(*this)>)
        state->Transition(*this);
    };
    std::visit(visitor, current_);
  }

  std::tuple<States...> states_;
  std::variant<States*...> current_ = &std::get<0>(states_);
};
class Empty {
  void Start() {}
  void Update() {}
  void ProcessInput() {}
  void End() {}
  template <typename Machine>
  void Transition(Machine& machine) const {
    // machine.template TransitionTo<X>();
  }
};
}  // namespace til
