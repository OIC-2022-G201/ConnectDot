#include "ParallaxCameraFlowLayerComponent.h"

#include "GameWindow.h"
#include "GridPosition.h"
#include "SpriteComponent.h"
using namespace base_engine;
ParallaxCameraFlowLayerComponent::ParallaxCameraFlowLayerComponent(Actor* owner)
    : Component(owner, 1) {}

void ParallaxCameraFlowLayerComponent::Create(
	const std::weak_ptr<Actor>& camera, const float follow_per_x,
	const float follow_per_y, const base_engine::Vector2& initial_position) {
  camera_actor_ = camera;
  follow_factor_ = Vector2{follow_per_x, follow_per_y};
  owner_->SetPosition(initial_position - Vector2{window::kWidth * 0.5f, 0});
}

void ParallaxCameraFlowLayerComponent::Start() {
}

void ParallaxCameraFlowLayerComponent::Update() {
  const auto current_pos = camera_actor_.lock()->GetPosition() +
                           Vector2{0, -window::kHeight * 0.5f} -
                           GridPosition::GridTo({0, 1}) * 2.02f;
  const auto delta_pos = current_pos - previous_camera_pos_;
  previous_camera_pos_ = current_pos;
  auto calced_pos = delta_pos * follow_factor_;
  owner_->SetPosition(owner_->GetPosition() + calced_pos +
                      owner_->GetParent().lock()->GetPosition());
  for (const auto& child_weak : owner_->GetChildren()) {
    const auto child = child_weak.lock();
    child->SetPosition(child->GetPosition() + calced_pos);
  }
}

HorizontalDynamicImageRotationComponent::
    HorizontalDynamicImageRotationComponent(Actor* owner)
    : Component(owner, 2), image_width_(0) {}

void HorizontalDynamicImageRotationComponent::Create(
    const std::weak_ptr<Actor>& camera) {
  camera_actor_ = camera;
  parent_cash_ = owner_->GetParent();
  image_width_ =
      owner_->GetComponent<SpriteComponent>().lock()->GetClipRect().GetWidth();
}

void HorizontalDynamicImageRotationComponent::Start() {
  owner_->SetPosition(owner_->GetPosition() +
                      parent_cash_.lock()->GetPosition());
}

void HorizontalDynamicImageRotationComponent::Update() {
  if (const auto distance =
          camera_actor_.lock()->GetPosition() - owner_->GetPosition();
      abs(distance.x) > image_width_ * 1.5f) {
    const float amount = image_width_ * 3 * (distance.x < 0 ? -1.0f : 1.0f);
    owner_->SetPosition(owner_->GetPosition() + Vector2{amount, 0});
  }
}
