// @EventBus.h
// @brief
// @author ICE
// @date 2022/12/05
//
// @details

#pragma once
#include <any>
#include <list>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "EventHandler.h"
#include "HandlerRegistration.h"

class EventBus {
 public:
  EventBus() = default;
  virtual ~EventBus() = default;

  static EventBus* GetInstance() {
    if (instance_ == nullptr) {
      instance_ = new EventBus();
    }

    return instance_;
  }

  template <class T>
  static std::shared_ptr<HandlerRegistration> AddHandler(
      EventHandler<T>& handler, std::any& sender) {
    EventBus* instance = GetInstance();

    Registrations* registrations = instance->handlers_[typeid(T)];

    if (registrations == nullptr) {
      registrations = new Registrations();
      instance->handlers_[typeid(T)] = registrations;
    }

    const auto registration = std::make_shared<EventRegistration>(
        static_cast<void*>(&handler), registrations, &sender);

    registrations->push_front(registration);
    registration->SetItr(registrations->cbegin());

    return registration;
  }

  template <class T>
  static std::shared_ptr<HandlerRegistration> AddHandler(
      EventHandler<T>& handler) {
    EventBus* instance = GetInstance();

    Registrations* registrations = instance->handlers_[typeid(T)];

    if (registrations == nullptr) {
      registrations = new Registrations();
      instance->handlers_[typeid(T)] = registrations;
    }

    const auto registration = std::make_shared<EventRegistration>(
        static_cast<void*>(&handler), registrations, nullptr);

    registrations->push_front(registration);
    registration->SetItr(registrations->cbegin());

    return registration;
  }
  static void FireEvent(Event& e) {
    EventBus* instance = GetInstance();

    const Registrations* registrations = instance->handlers_[typeid(e)];

    if (registrations == nullptr) {
      return;
    }

    for (auto& reg_weak : *registrations) {
      if (const auto reg = reg_weak.lock();
          (reg->GetSender() == nullptr) ||
          (reg->GetSender() == &e.GetSender())) {
        static_cast<EventHandler<Event>*>(reg->GetHandler())->OnEvent(e);
      }
    }
  }

 private:
  static EventBus* instance_;

  class EventRegistration final : public HandlerRegistration {
   public:
    using Registrations = std::list<std::weak_ptr<EventRegistration>>;

    EventRegistration(void* const handler, Registrations* const registrations,
                      std::any* const sender)
        : handler_(handler),
          registrations_(registrations),
          sender_(sender),
          registered_(true) {}

    ~EventRegistration() override { removeHandler(); }

    [[nodiscard]] void* GetHandler() const { return handler_; }

    [[nodiscard]] std::any* GetSender() const { return sender_; }

    void removeHandler() override {
      if (registered_) {
        registrations_->erase(itr_);
        registered_ = false;
      }
    }
    void SetItr(const Registrations::const_iterator& itr) { itr_ = itr; }

   private:
    void* const handler_;
    Registrations* const registrations_;
    std::any* const sender_;

    bool registered_;
    Registrations::const_iterator itr_;
  };

  using WeakEventRegistration = std::weak_ptr<EventRegistration>;
  using Registrations = std::list<WeakEventRegistration>;
  using TypeMap =
      std::unordered_map<std::type_index, std::list<WeakEventRegistration>*>;

  TypeMap handlers_;
};
