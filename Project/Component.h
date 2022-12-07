#pragma once
#include "Actor.h"

namespace base_engine {

class Component {
 public:
  // コンストラクタ
  // (updateOderが小さい程、先に更新される)
  Component(class Actor* owner, int update_order = 100);
  // デストラクタ
  virtual ~Component();
  virtual void Start() {}
  // このコンポーネントの入力処理
  virtual void ProcessInput() {}
  // このコンポーネントの更新処理
  virtual void Update() {}
  virtual void OnCollision(const class SendManifold& manifold) {}

  [[nodiscard]] int GetUpdateOrder() const { return update_order_; }
  [[nodiscard]] ActorWeakPtr GetOwner() const {
    return owner_->GetGame()->GetActor(owner_->GetId());
  }

 protected:
  // このComponentを所有するActor
  class Actor* owner_;
  // 更新の順番
  int update_order_;
};
}  // namespace base_engine