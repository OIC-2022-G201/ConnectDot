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
  [[nodiscard]] static std::shared_ptr<HandlerRegistration> AddHandler(
      EventHandler<T>& handler, std::any& sender) {
    EventBus* instance = GetInstance();

    Registrations* registrations = instance->handlers_[typeid(T)];

    if (registrations == nullptr) {
      registrations = new Registrations();
      instance->handlers_[typeid(T)] = registrations;
    }

    const auto registration = std::make_shared<EventRegistration>(
        static_cast<void*>(&handler), registrations, &sender);

    registrations->emplace_back(registration);
    // registration->SetItr(registrations->cbegin());

    return registration;
  }

  template <class T>
  [[nodiscard]] static std::shared_ptr<HandlerRegistration> AddHandler(
      EventHandler<T>& handler) {
    EventBus* instance = GetInstance();

    Registrations* registrations = instance->handlers_[typeid(T)];

    if (registrations == nullptr) {
      registrations = new Registrations();
      instance->handlers_[typeid(T)] = registrations;
    }

    const auto registration = std::make_shared<EventRegistration>(
        static_cast<void*>(&handler), registrations, nullptr);

    registrations->emplace_back(registration);

    return registration;
  }
  static void FireEvent(Event& e) {
    EventBus* instance = GetInstance();

    const Registrations* registrations = instance->handlers_[typeid(e)];

    if (registrations == nullptr) {
      return;
    }
    if (registrations->empty()) return;
    for (auto& reg_weak : *registrations) {
      if (reg_weak.expired()) continue;
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
    using Registrations = std::vector<std::weak_ptr<EventRegistration>>;

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
        if (const auto iter = std::ranges::find_if(
                (*registrations_),
                [this](const std::weak_ptr<EventRegistration>& n) {
                  return n.lock().get() == this;
                });
            iter != registrations_->end()) {
          std::iter_swap(iter, registrations_->end() - 1);
          registrations_->pop_back();
        }
        registered_ = false;
      }
    }

   private:
    void* const handler_;
    Registrations* const registrations_;
    std::any* const sender_;

    bool registered_;
  };

  using WeakEventRegistration = std::weak_ptr<EventRegistration>;
  using Registrations = std::vector<WeakEventRegistration>;
  using TypeMap =
      std::unordered_map<std::type_index, std::vector<WeakEventRegistration>*>;

  TypeMap handlers_;
};
