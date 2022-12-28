#include "ElectricEffect.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "IBaseEngineTexture.h"
#include "MofSpriteAnimationComponent.h"
#include "ReceiverComponent.h"
#include "TransmitterComponent.h"
using namespace base_engine;
constexpr std::array<std::string_view, 2> kTexturePaths = {
    "Effect/Electric/ElectroCellMap.png",
    "Effect/Electro_purple/ElectroCellMap.png"};

void ElectricEffect::Update() { OnChangeLevel(); }

void ElectricEffect::Play(Vector2 pos1, Vector2 pos2) {
  {
    if (!sprite_) {
      sprite_ = new SpriteComponent(this, draw_order::kElectricEffectDrawOrder);
      sprite_->SetColor(MOF_ARGB(255 / 3, 255, 255, 255));
      motion_ = new MofSpriteAnimationComponent(this, 500);
    }
    OnChangeLevel();

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

void ElectricEffect::OnChangeLevel() {
  if (!transmitter_.expired()) {
    if (const int level = transmitter_.lock()->Level() - 1;
        current_level_ != level) {
      current_level_ = level;
      sprite_->SetImage(BASE_ENGINE(Texture)->Get(kTexturePaths[level]));
    }
  }
}
