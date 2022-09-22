#include "SignboardActor.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "IBaseEngineTexture.h"
#include "MachineConst.h"
using namespace base_engine;
using namespace electronics::signboard;
using namespace draw_order;
SignboardActor::SignboardActor(base_engine::Game* game): Actor(game)
{
}

void SignboardActor::Start()
{
  {
    display_ = new SpriteComponent(this, kSignboardDisplayDrawOrder);
    display_->SetOffset(kDisplayOffset);
    display_->SetImage(display_texture_);
  }
  {
      const auto sign = new SpriteComponent(this, kSignboardDrawOrder);
    sign->SetImage(
        BASE_ENGINE(Texture)->Get("Effect/Electric/ElectroCellMap.png"));
  }
}

void SignboardActor::Update()
{
        
}

void SignboardActor::SetDisplayImage(base_engine::TexturePtr texture)
{
  display_texture_ = texture;
  if (display_)
  {
    display_->SetImage(display_texture_);
  }
}
