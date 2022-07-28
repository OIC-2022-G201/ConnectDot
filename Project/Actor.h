#pragma once

#include <string>
#include <vector>

#include "Vector.h"
#include "IBaseEngineCollider.h"
namespace base_engine {
class Actor {
 public:
  enum State { kStart,kActive, kPause, kDead };

  Actor(class Game* game);
  virtual ~Actor();

  void StartActor();
  virtual void Start() {}
  void ProcessInput();
  virtual void Input() {}

  void UpdateActor();
  virtual void Update() {}

  template<class T>
  void SendCallbackMessage(T* callback)
  {
    for (auto element : components_)
      {
      callback->SendComponentsMessage(element);
      }
  }

  template <class T,class D>
  void SendCallbackMessage(T* callback,D* data) {
    for (auto element : components_) {
      callback->SendComponentsMessage(element, data);
    }
  }
  [[nodiscard]] State GetState() const { return state_; }
  void SetState(const State state) { state_ = state; }

  [[nodiscard]] const Vector2& GetPosition() const { return position_; }
  void SetPosition(const Vector2& pos) { position_ = pos; }
  float GetRotation() const;
  void SetRotation(const float rotation) { rotation_ = rotation; }
  [[nodiscard]] float GetScale() const { return scale_; }
  void SetScale(const float scale) { scale_ = scale; }

  class Game* GetGame() const {
    return game;
  }

  void AddComponent(class Component*);
  void RemoveComponent(class Component*);
  std::string_view GetName() { return name_; }
  Actor& SetName(const std::string_view name);

protected:
  std::string name_ = "Actor";
  State state_;
  Vector2 position_;
  float rotation_;
  float scale_;
private:
  void AddComponent();
  class Game* game;
  std::vector<class Component*> components_;
  std::vector<class Component*> pending_components_;
};
}  // namespace base_engine