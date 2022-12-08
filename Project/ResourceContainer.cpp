#include "ResourceContainer.h"

#include <Common/ReadFile.h>

#include <filesystem>
#include <fstream>
#include <functional>

#include "BaseEngineCore.h"
#include "ISpriteAnimationComponent.h"
#include "ResourceManager.h"
#include "SpriteAnimationClipLoader.h"

using namespace asset_system;
using namespace base_engine;
ResourceContainer::ResourceManagerMap ResourceContainer::resource_manager_{};
class ResourceContainer::Impl {
 public:
  explicit Impl(ResourceContainer* resource_register);
  ~Impl();

  bool Load(const fs::path& root);

 private:
  template <class T, class Pack>
  bool Register(Pack pack, size_t key);
  template <class T, class R>
  bool RegisterResource(ResourceValue<R> pack, size_t key);

  template <class R, class T, class Pack>
  bool Register(Pack pack, size_t key, std::function<R(T)> converter);
  template <class R, class T>
  bool RegisterResource(ResourceValue<R> pack, size_t key,
                        std::function<R(T)> converter);

  void LoadAnimationPack(const size_t hash,
                         ResourceManagerMap& resource_manager);
  void LoadSpritePack(const size_t hash, ResourceManagerMap& resource_manager);
  void LoadButtonPack(const size_t hash, ResourceManagerMap& resource_manager);
  ResourceContainer* resource_register_;
  std::ifstream reader_;
  std::unordered_map<size_t, std::function<void(size_t)>> factory_;
  std::hash<std::string> ToHash = std::hash<std::string>{};
};

ResourceContainer::ResourceContainer() { impl_ = std::make_unique<Impl>(this); }

ResourceContainer::~ResourceContainer() {}

bool ResourceContainer::Register() const {
  impl_->Load("Meta/Asset.txt");

  return true;
}

ResourceContainer::Impl::Impl(ResourceContainer* resource_register)
    : resource_register_(resource_register) {
  std::shared_ptr<AnimationResourcePack> animation_pack;
  factory_[ToHash("Animation")] = [this](const size_t hash) {
    LoadAnimationPack(hash, resource_manager_);
  };
  factory_[ToHash("Sprite")] = [this](const size_t hash) {
    LoadSpritePack(hash, resource_manager_);
  };
  factory_[ToHash("Button")] = [this](const size_t hash) {
    LoadButtonPack(hash, resource_manager_);
  };
}

bool ResourceContainer::Impl::Load(const fs::path& root) {
  reader_.open(root);
  while (!reader_.eof()) {
    std::string tag;
    std::string type;
    reader_ >> tag >> type;
    factory_[ToHash(type)](ToHash(tag));
  }
  return true;
}

template <class T, class Pack>
bool ResourceContainer::Impl::Register(Pack pack, size_t key) {
  T resource_value;
  reader_ >> resource_value;
  const auto resource_ptr = std::make_shared<Resource<T>>();
  resource_ptr->Register(key, resource_value);
  pack->Register(resource_ptr);
  return true;
}

template <class T, class R>
bool ResourceContainer::Impl::RegisterResource(ResourceValue<R> pack,
                                               size_t key) {
  T resource_value;
  reader_ >> resource_value;
  pack->Register(key, resource_value);
  return true;
}

template <class R, class T, class Pack>
bool ResourceContainer::Impl::Register(Pack pack, size_t key,
                                       std::function<R(T)> converter) {
  T read_value;
  reader_ >> read_value;
  const auto resource_ptr = std::make_shared<Resource<R>>();
  resource_ptr->Register(key, converter(read_value));
  pack->Register(resource_ptr);
  return true;
}

template <class R, class T>
bool ResourceContainer::Impl::RegisterResource(ResourceValue<R> pack,
                                               size_t key,
                                               std::function<R(T)> converter) {
  T read_value;
  reader_ >> read_value;
  pack->Register(key, converter(read_value));
  return true;
}

void ResourceContainer::Impl::LoadAnimationPack(
    const size_t hash, ResourceManagerMap& resource_manager) {
  const auto pack = resource_manager.CreatePack<AnimationResourcePack>(hash);

  Register<TexturePtr, ImagePath>(pack, 0, [](const fs::path& path) {
    return BASE_ENGINE(Texture)->Get(path.generic_string());
  });
  Register<AnimationClips, fs::path>(pack, 0, [](const fs::path& path) {
    return SpriteAnimationClipLoader::Load(path.generic_string().c_str());
  });
}

void ResourceContainer::Impl::LoadSpritePack(
    const size_t hash, ResourceManagerMap& resource_manager) {
  const auto pack = resource_manager.CreatePack<SpriteResourcePack>(hash);

  Register<TexturePtr, ImagePath>(pack, 0, [](const fs::path& path) {
    return BASE_ENGINE(Texture)->Get(path.generic_string());
  });
}

void ResourceContainer::Impl::LoadButtonPack(
    const size_t hash, ResourceManagerMap& resource_manager) {
  const auto pack = resource_manager.CreatePack<ButtonResourcePack>(hash);

  Register<ButtonPackage, ImagePath>(pack, 0, [](const fs::path& path) {
    ButtonPackage result;
    result.sprites[0] = BASE_ENGINE(Texture)->Get(path.generic_string());
    return result;
  });
  fs::path read_value;
  reader_ >> read_value;
  const auto resource = pack->Get<ButtonPackage>();
  resource->Get(0)->sprites[1] = BASE_ENGINE(Texture)->Get(read_value.generic_string());

}

ResourceContainer::Impl::~Impl() {}
