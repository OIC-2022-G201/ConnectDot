// @ResultScoreComponent.h
// @brief
// @author ICE
// @date 2022/12/26
//
// @details

#pragma once
#include "Component.h"
#include "EventHandler.h"
#include "ResultModel.h"
#include "ServiceLocator.h"
#include "GoalEvent.h"
#include "HandlerRegistration.h"

class ResultScoreComponent final : public base_engine::Component,
                                   public EventHandler<GoalEvent> {
  explicit ResultScoreComponent(base_engine::Actor* owner,
                                int update_order = 100);
  std::shared_ptr<HandlerRegistration> handler_; 
  std::shared_ptr<ResultModel> result_; 
	public:
  void Update() override;
  void Start() override;
  void OnEvent(GoalEvent&) override;
  static ResultScoreComponent* Create(base_engine::Game* game);
};
