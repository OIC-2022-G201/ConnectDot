// @ResourceContainer.h
// @brief
// @author ICE
// @date 2022/12/07
//
// @details

#pragma once
#include <filesystem>
#include <Sound/XAudio/XAudioSoundBuffer.h>


#include "IBaseEngineTexture.h"
#include "ISpriteAnimationComponent.h"
#include "ResourceManager.h"
#include "UiPackage.h"

namespace fs = std::filesystem;

class ResourceContainer {
 public:
  using ImagePath = std::filesystem::path;
  using Sprite = base_engine::TexturePtr;
  using AnimationClips = std::vector<base_engine::SpriteAnimationClip>;

  using SoundResourcePack =asset_system::ResourcePack<Mof::CSoundBuffer*>;
  using AnimationResourcePack =
      asset_system::ResourcePack<Sprite, AnimationClips>;
  using SpriteResourcePack =
      asset_system::ResourcePack<Sprite>;
  using ButtonResourcePack = asset_system::ResourcePack<ButtonResourcePackage>;
  using ResourceManagerMap =
      asset_system::ResourceManager<AnimationResourcePack, SpriteResourcePack,
                                    ButtonResourcePack,SoundResourcePack>;
    
 public:
  explicit ResourceContainer();
  ~ResourceContainer();
  bool Register() const;

  template <class Pack, class R>
  static std::shared_ptr<R> GetResource(const std::string& key);
  template <class Pack>
  static std::shared_ptr<Pack> GetPack(const std::string& key);;
  template <class Pack>
  static void Clear()
  {
    resource_manager_.Clear<Pack>();
  }

 private:
  static ResourceManagerMap resource_manager_;
  class Impl;
  std::unique_ptr<Impl> impl_;
};

template <class Pack, class R>
std::shared_ptr<R> ResourceContainer::GetResource(const std::string& key) {
  const auto pack = resource_manager_.FindPack<Pack>(
      std::hash<std::string>{}(key));
  return pack->template Get<R>()->Get(0);
}

template <class Pack>
std::shared_ptr<Pack> ResourceContainer::GetPack(const std::string& key)
{
  const auto pack = resource_manager_.FindPack<Pack>(
      std::hash<std::string>{}(key));
  return pack;
}
