#include "ResultScoreComponent.h"
#include <Utilities/Utilities.h>
#include "EventBus.h"

ResultScoreComponent::ResultScoreComponent(base_engine::Actor* owner,
                                           int update_order)
    : Component(owner, update_order) {}

void ResultScoreComponent::Update() {
  result_->Update(Mof::CUtilities::GetFrameSecond());
}

void ResultScoreComponent::Start() {
  handler_ = EventBus::AddHandler(*this);
  result_ = ComponentServiceLocator::Instance().Resolve<ResultModel>();
  result_->Start();
}

void ResultScoreComponent::OnEvent(GoalEvent& event) { result_->Pause(); }

ResultScoreComponent* ResultScoreComponent::Create(base_engine::Game* game) {
  const auto component = new ResultScoreComponent(new base_engine::Actor(game));

  component->result_ = std::make_shared<ResultModel>();
  ComponentServiceLocator::Instance().RegisterInstance(component->result_);

  return component;
}
