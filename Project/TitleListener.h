// @TitleListener.h
// @brief
// @author ICE
// @date 2022/12/09
//
// @details

#pragma once
#include "Component.h"
#include "HandlerRegistration.h"

class TitleComponent final : base_engine::Component {
  class TitleListener;

 public:
  explicit TitleComponent(base_engine::Actor* owner);

  void Start() override;

private:
  std::unique_ptr<TitleListener> listener_;
  std::shared_ptr<HandlerRegistration> handle_;
};
