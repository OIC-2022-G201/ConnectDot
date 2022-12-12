#include "CameraComponent.h"
std::weak_ptr<base_engine::CameraComponent>
    base_engine::CameraComponent::main_camera_weak_;
base_engine::CameraComponent::CameraComponent(Actor* owner, int update_order)
    : Component(owner, update_order) {}

void base_engine::CameraComponent::Update() {
  BASE_ENGINE(Render)->SetCameraPosition(owner_->GetPosition());
}

void base_engine::CameraComponent::SetMainCamera() const {
  main_camera_weak_ = owner_->GetComponent<CameraComponent>();
}

std::weak_ptr<base_engine::CameraComponent>
base_engine::CameraComponent::GetMainCamera() {
  return main_camera_weak_;
}
