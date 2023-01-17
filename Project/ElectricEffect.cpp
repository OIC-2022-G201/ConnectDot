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
    "Effect/Electric/ElectroCellMap.png"};

void ElectricEffect::Update() {
  if (!is_play_) return;

  ++current_frame_;
  OnChangeLevel();
}

void ElectricEffect::Play(const Vector2& pos1, const Vector2& pos2) {
  {
    if (!sprite_) {
      sprite_ = new SpriteComponent(this, draw_order::kElectricEffectDrawOrder);
      sprite_->SetColor(MOF_ARGB(static_cast<int>(255 *0.8), 255, 255, 255));
      motion_ = new MofSpriteAnimationComponent(this, 500);
    }
    current_frame_ = 0;
    start_pos_ = pos1;
    end_pos_ = pos2;
    OnChangeLevel();

    const Vector2 o_pos = pos2 - pos1;

    const float width = std::abs(VectorUtilities::Length(o_pos));
    std::array animations = {SpriteAnimationClip{
        "Animation",
        0,
        0,
        width,
        128,
        true,
        {{5, 0, 0}, {5, 0, 1}, {5, 0, 2}, {5, 0, 3}, {5, 0, 4}}}};
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
