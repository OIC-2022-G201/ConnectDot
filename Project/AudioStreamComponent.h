// @AudioStreamComponent.h
// @brief
// @author ICE
// @date 2023/02/05
//
// @details

#pragma once
#include "Component.h"
#include "ResourceContainer.h"
namespace base_engine {
class AudioStreamComponent final : public Component {
  using MofSoundBufferPtr = std::shared_ptr<ResourceContainer::Sound>;
  MofSoundBufferPtr audio_buffer_ = nullptr;

 public:
  explicit AudioStreamComponent(Actor* owner);
  ~AudioStreamComponent() override;
  void SetAudioBuffer(const MofSoundBufferPtr audio);
  bool AssetLoad(const std::string& name);
  void Update() override;
  void Play() const;
  void Stop() const;
  void Resume() const;
  void SetVolume(float volume) const;
  void SetLoop(bool loop) const;
  void SetPitch(float pitch) const;

  float GetPitch() const;
  bool IsPlay() const;
};
}  // namespace base_engine
