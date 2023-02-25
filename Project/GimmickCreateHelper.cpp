#include "GimmickCreateHelper.h"

#include <Mof.h>

#include <filesystem>

#include "IBaseEngineTexture.h"
#include "ISpriteAnimationComponent.h"
#include "MofSpriteAnimationComponent.h"
#include "ResourceContainer.h"
#include "SpriteComponent.h"
using namespace base_engine;
using RC = ResourceContainer;
namespace {
// white, red, yellow, green, cyan, blue,magenta

void SetColor(SpriteComponent* sprite, int color_type) {
  MofU32 color = MOF_COLOR_WHITE;
  switch (color_type) {
    case 0:
      color = MOF_COLOR_WHITE;
      break;
    case 1:
      color = MOF_COLOR_RED;
      break;
    case 2:
      color = MOF_COLOR_YELLOW;
      break;
    case 3:
      color = MOF_COLOR_GREEN;
      break;
    case 4:
      color = MOF_COLOR_HBLUE;
      break;
    case 5:
      color = MOF_COLOR_BLUE;
      break;
    case 6:
      color = MOF_XRGB(200, 0, 250);
      break;
    default:;
  }
  sprite->SetColor(color);
}
}  // namespace
SpriteComponent* GimmickCreateHelper::SpriteCreateKey(base_engine::Actor* owner,
                                                      const std::string& key,
                                                      int color_type,
                                                      int draw_order) {
  const auto sprite = new SpriteComponent(owner, draw_order);
  const auto image = *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(key);
  sprite->SetImage(image);
  SetColor(sprite, color_type);
  return sprite;
}

SpriteComponent* GimmickCreateHelper::SpriteCreatePath(
    base_engine::Actor* owner, const std::string& path, int color_type,
    int draw_order) {
  const auto sprite = new SpriteComponent(owner, draw_order);
  sprite->SetImage(BASE_ENGINE(Texture)->Get(path));
  SetColor(sprite, color_type);
  return sprite;
}

std::pair<SpriteComponent*, ISpriteAnimationComponent*>
GimmickCreateHelper::AnimationCreateKey(base_engine::Actor* owner,
                                        const std::string& key, int color_type,
                                        bool play, int draw_order) {
  const auto image =
      *RC::GetResource<RC::AnimationResourcePack, RC::Sprite>(key);
  const auto clip =
      RC::GetResource<RC::AnimationResourcePack, RC::AnimationClips>(key);
  const auto sprite = new SpriteComponent(owner, draw_order);
  sprite->SetImage(image);
  SetColor(sprite, color_type);
  const auto animation = new MofSpriteAnimationComponent(owner);
  if(!animation->Load(sprite, *clip))
  {
    throw std::exception("アニメーション読み込み失敗");
  }
  if (!play) animation->Stop();
  return {sprite, animation};
}

std::pair<SpriteComponent*, ISpriteAnimationComponent*>
GimmickCreateHelper::AnimationCreatePath(base_engine::Actor* owner,
                                         const std::string& path,
                                         int color_type, bool play,
                                         int draw_order) {
  const auto sprite = new SpriteComponent(owner, draw_order);

  sprite->SetImage(BASE_ENGINE(Texture)->Get(path));
  SetColor(sprite, color_type);

  std::filesystem::path file = path;
  const auto animation = new MofSpriteAnimationComponent(owner);
  animation->Load(sprite, file.replace_extension(".aei").string());
  if (!play) animation->Stop();
  return {sprite, animation};
}
