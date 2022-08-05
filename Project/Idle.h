#pragma once
namespace player {
class Idle {
  Idle()
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
