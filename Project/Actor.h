#pragma once

#include <memory>
#include <string>
#include <vector>

#include "IBaseEngineCollider.h"
#include "Vector.h"
namespace base_engine {
    using ComponentPtr = std::shared_ptr<class Component>;
    using ComponentWeakPtr = std::weak_ptr<class Component>;
    template <class T>
    using ComponentDerivedPtr = std::shared_ptr<T>;
    template <class T>
    using ComponentDerivedWeakPtr = std::weak_ptr<T>;
    class Actor {
 public:
  enum State { kStart, kActive, kPause, kDead };

  Actor(class Game* game);
  virtual ~Actor();

  void StartActor();
  /**
   * \brief Actorを継承した各クラスが登録された後に呼び出される
   */
  virtual void Start() {}
  void ProcessInput();
  /**
   * \brief Update前に毎フレーム呼び出される
   */
  virtual void Input() {}

  void UpdateActor();
  /**
   * \brief 毎フレーム呼び出される
   */
  virtual void Update() {}

  template <class T>
  void SendCallbackMessage(T* callback) {
    for (auto element : components_) {
      callback->SendComponentsMessage(element);
    }
  }

  template <class T, class D>
  void SendCallbackMessage(T* callback, D&& data) {
    for (auto element : components_) {
      callback->SendComponentsMessage(element.get(), data);
    }
  }
  [[nodiscard]] State GetState() const { return state_; }
  void SetState(const State state) { state_ = state; }

  [[nodiscard]] const Vector2& GetPosition() const { return position_; }
  void SetPosition(const Vector2& pos) { position_ = pos; }
  void Translation(const Vector2& pos) { position_ += pos; }
  float GetRotation() const;
  void SetRotation(const float rotation) { rotation_ = rotation; }
  [[nodiscard]] float GetScale() const { return scale_; }
  void SetScale(const float scale) { scale_ = scale; }

  [[nodiscard]] Game* GetGame() const { return game; }
  /**
   * \brief Componentの追加はコンストラクタから呼び出す
   * \param component 
   */
  void AddComponent(class Component* component);
  /**
   * \brief コンポーネントを登録する
   */
  void AddComponent();
  /**
   * \brief コンポーネント型を探索して取得する
   * \tparam T Componentクラスを継承したクラス
   * \return 成功:最初に見つかったコンポーネントのポインタ, 失敗:nullptr
   * 同一型のコンポーネントが複数ある場合同じものが返ってくるとは限らない
   */
  template <class T>
  [[nodiscard]] ComponentDerivedWeakPtr<T> GetComponent() const;

  /**
   * \brief 指定のコンポーネントを全て探索して取得する
   * \tparam T Componentクラスを継承したクラス
   * \return 成功:探索したコンポーネントのポインタ,失敗:nullptr
   */
  template <class T>
  T* GetComponents() const;
  /**
   * \brief Componentのデストラクタから呼び出す
   * \param component
   */
  void RemoveComponent(class Component* component);
  std::string_view GetName() { return name_; }
  Actor& SetName(const std::string_view name);

  void SetTag(std::string_view tag);
  [[nodiscard]] std::string_view GetTag() const;
  
 protected:
  std::string name_ = "Actor";
  std::string tag_ = "Object";
  State state_;
  Vector2 position_;
  float rotation_;
  float scale_;
 private:
  class Game* game;
  std::vector<ComponentPtr> components_;
  std::vector<ComponentPtr> pending_components_;
    };

template <class T>
ComponentDerivedWeakPtr<T> Actor::GetComponent() const {
    for (auto& elem : components_) {
        if (ComponentDerivedPtr<T> buff = std::dynamic_pointer_cast<T>(elem)) return buff;
    }
    for (auto& elem : pending_components_) {
        if (ComponentDerivedPtr<T> buff = std::dynamic_pointer_cast<T>(elem)) return buff;
    }
    return ComponentDerivedWeakPtr<T>();
}

template <class T>
T* Actor::GetComponents() const
{
      
}
}  // namespace base_engine