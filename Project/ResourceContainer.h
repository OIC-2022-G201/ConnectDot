// @ResourceContainer.h
// @brief
// @author ICE
// @date 2022/12/07
//
// @details

#pragma once
#include <Sound/SoundBufferBase.h>

#include <filesystem>

#include "IBaseEngineTexture.h"
#include "ISpriteAnimationComponent.h"
#include "ResourceManager.h"
#include "UiPackage.h"

namespace base_engine {
class Material;
}

namespace fs = std::filesystem;

class ResourceContainer {
 public:
  using ImagePath = std::filesystem::path;
  using SoundPath = std::filesystem::path;
  using Sprite = base_engine::TexturePtr;
  using Sound = Mof::ISoundBuffer;
  using AnimationClips = std::vector<base_engine::SpriteAnimationClip>;

  using AnimationResourcePack =
      asset_system::ResourcePack<Sprite, AnimationClips>;
  using SoundResourcePack = asset_system::ResourcePack<Sound>;
  using SpriteResourcePack = asset_system::ResourcePack<Sprite>;
  using ButtonResourcePack = asset_system::ResourcePack<ButtonResourcePackage>;
  using MaterialResourcePack =
      asset_system::ResourcePack<base_engine::Material>;
  using ResourceManagerMap =
      asset_system::ResourceManager<AnimationResourcePack, SpriteResourcePack,
                                    ButtonResourcePack, MaterialResourcePack,
                                    SoundResourcePack>;

 public:
  explicit ResourceContainer();
  ~ResourceContainer();
  bool Register() const;

  template <class Pack, class R>
  static std::shared_ptr<R> GetResource(const std::string& key);
  template <class Pack>
  static std::shared_ptr<Pack> GetPack(const std::string& key);
  template <class Pack>
  static typename Pack::Ptr CreatePack(const std::string& key);
	static bool ClearAll();
 private:
  static ResourceManagerMap resource_manager_;
  class Impl;
  std::unique_ptr<Impl> impl_;
};

template <class Pack, class R>
std::shared_ptr<R> ResourceContainer::GetResource(const std::string& key) {
  const auto pack =
      resource_manager_.FindPack<Pack>(std::hash<std::string>{}(key));
  if(pack == nullptr)
  {
    return nullptr;
  }
  return pack->template Get<R>()->Get(0);
}

template <class Pack>
std::shared_ptr<Pack> ResourceContainer::GetPack(const std::string& key) {
  const auto pack =
      resource_manager_.FindPack<Pack>(std::hash<std::string>{}(key));
  return pack;
}

template <class Pack>
typename Pack::Ptr ResourceContainer::CreatePack(const std::string& key) {
  return resource_manager_.CreatePack<Pack>(std::hash<std::string>{}(key));
}
