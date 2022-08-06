#pragma once
namespace player {
class Jump
{
 public:
  Jump() {}
  void Start() {}
  void Update() {
    int n = 4;
    
  }
  void ProcessInput() {}
  void End() {}
  template <typename Machine>
  void Transition(Machine& machine) const {
    // machine.template TransitionTo<X>();
  }
};
}  // namespace player