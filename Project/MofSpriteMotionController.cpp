#include "MofSpriteMotionController.h"

MofBool base_engine::MofSpriteMotionController::Create(
    const SpriteAnimationClip& ac) {
  m_pAnimation = new Mof::CDynamicArray<Mof::CSpriteAnimation*>();
  m_pAnimation->Add(new SpriteAnimation{ac});
  this->Refresh();
  return true;
}

MofBool base_engine::MofSpriteMotionController::Create(
    const std::span<SpriteAnimationClip> ac) {
  m_pAnimation = new Mof::CDynamicArray<Mof::CSpriteAnimation*>();
  for (const auto& clip : ac) {
    m_pAnimation->Add(new SpriteAnimation{clip});
  }
  this->Refresh();
  return true;
}
