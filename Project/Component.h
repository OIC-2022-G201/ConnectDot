#pragma once

namespace base_engine {

class Component {
 public:
  // �R���X�g���N�^
  // (updateOder�����������A��ɍX�V�����)
  Component(class Actor* owner, int update_order = 100);
  // �f�X�g���N�^
  virtual ~Component();
  virtual void Start() {}
  // ���̃R���|�[�l���g�̓��͏���
  virtual void ProcessInput() {}
  // ���̃R���|�[�l���g�̍X�V����
  virtual void Update() {}

  int GetUpdateOrder() const { return update_order_; }

 protected:
  // ����Component�����L����Actor
  class Actor* owner_;
  // �X�V�̏���
  int update_order_;
};
}  // namespace base_engine