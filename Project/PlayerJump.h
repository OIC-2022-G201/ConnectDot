// @file PlayerJump.h
// @brief �v���C���[�W�����v�̃X�e�[�g
// @author ICE
// @date 2022/08/07
//
// @details
#pragma once

namespace player {
class PlayerJump
{
 public:
  PlayerJump() {}
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