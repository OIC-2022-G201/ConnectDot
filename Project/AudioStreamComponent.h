// @AudioStreamComponent.h
// @brief
// @author ICE
// @date 2023/02/05
//
// @details

#pragma once
#include <Sound/XAudio/XAudioSoundBuffer.h>

#include "Component.h"
#include "ResourceContainer.h"

namespace base_engine {
struct Del {
  constexpr Del() noexcept = default;

  void operator()(Mof::ISoundBuffer* _Ptr) const noexcept {
    static_assert(0 < sizeof(Mof::ISoundBuffer),
                  "can't delete an incomplete type");
    _Ptr->Release();
    delete _Ptr;
  }
};
class AudioStreamComponent : public Component {
  using MofSoundBufferPtr = std::shared_ptr<ResourceContainer::Sound>;
  MofSoundBufferPtr audio_buffer_ = nullptr;

 public:
  explicit AudioStreamComponent(Actor* owner) : Component(owner) {}
  void SetAudioBuffer(const MofSoundBufferPtr audio) { audio_buffer_ = audio; }

  bool AssetLoad(const std::string& name) {
    audio_buffer_ =
        ResourceContainer::GetResource<ResourceContainer::SoundResourcePack,
                                       ResourceContainer::Sound>(name);
    return audio_buffer_ != nullptr;
  }

  void Play() const { audio_buffer_->Play(); }
  void Stop() const { audio_buffer_->Stop(); }
  void Resume() const { audio_buffer_->Resume(); }
  void SetVolume(const float volume) { audio_buffer_->SetVolume(volume); }
};
}  // namespace base_engine
