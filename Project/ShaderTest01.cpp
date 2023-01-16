#include "ShaderTest01.h"

#include "DrawOrder.h"
#include "Material.h"
#include "MofSpriteAnimationComponent.h"
#include "ShaderBase.h"
#include "SpriteComponent.h"
#include "TexturePaths.h"
#include "ResourceContainer.h"
using namespace base_engine;
void ShaderTest01::Main()
{
  const auto actor = new Actor(game_);
  const auto player_sprite =
      new SpriteComponent(actor, draw_order::kPlayerDrawOrder);

  player_sprite->SetImage(
      BASE_ENGINE(Texture)->Get(texture::kPlayerTextureKey));
  using RC = ResourceContainer;
  const auto material =
      RC::GetResource<RC::MaterialResourcePack, Material>("TestShader");
  struct {
    Vector2 Screen;
    int nCount;
  } sb;
  sb.Screen.x = 256;
  sb.Screen.y = 256;
  sb.nCount = 8;
  material->SetParameter({"cb", 0, base_engine::PropertyType::kBuffer, &sb});
  player_sprite->SetMaterial(material);
}
