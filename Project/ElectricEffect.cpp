#include "ElectricEffect.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "IBaseEngineTexture.h"
#include "ReceiverComponent.h"
using namespace base_engine;
void ElectricEffect::Play(Vector2 pos1, Vector2 pos2) {
  {
    if (!sprite_)
    {
        sprite_ = new SpriteComponent(this, draw_order::kElectricEffectDrawOrder);
      sprite_->SetColor(MOF_ARGB(32,255,255,255));
        sprite_->SetImage(
            BASE_ENGINE(Texture)->Get("Effect/Electric/ElectroCellMap_half.png"));
        motion_ = new MofSpriteAnimationComponent(this, 500);
    }

    const Vector2 o_pos = pos2 - pos1;

    const float width = std::abs(VectorUtilities::Length(o_pos));
    std::array animations = {SpriteAnimationClip{
        "", 0, 0, width, 128, true, {{5, 0, 0}, {5, 0, 1}, {5, 0, 2}}}};
    sprite_->SetOffset(pos1);
    sprite_->SetAngle(std::atan2(o_pos.y, o_pos.x));
    sprite_->SetAlignment(Mof::TEXALIGN_CENTERLEFT);
    motion_->Load(sprite_, animations);
  
  

  }
}


