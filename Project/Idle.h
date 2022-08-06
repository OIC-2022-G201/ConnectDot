#pragma once
namespace player {
class Idle {
  class PlayerComponent* player_;

 public:
  explicit Idle(class PlayerComponent* player) : player_(player)
  {
      
  }
  void Start() {}
  void Update() {}
  void ProcessInput() {}
  void End() {}
  template <typename Machine>
  void Transition(Machine& machine) const {
    //machine.template TransitionTo<X>();
  }
};

}  // namespace player
