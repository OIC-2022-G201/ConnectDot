// @NinePatchImageComponent.h
// @brief
// @author ICE
// @date 2022/12/25
//
// @details

#pragma once
#include <array>

#include "ISpriteAnimatable.h"
#include "RenderComponent.h"

namespace base_engine {
//TODO Imageなどに統合
class NinePatchImageComponent : public RenderComponent,public ISpriteAnimatable {
 public:
  using COLOR = uint32_t;

  NinePatchImageComponent(Actor* owner, int draw_order = 100);

  void Draw() override;
  

  NinePatchImageComponent& SetImage(const Mof::LPTexture img,
                                    const Vector2& left_top,
                                    const Vector2& right_bottom);
  void SetClipRect(const Mof::CRectangle &rect) override;

  [[nodiscard]] Mof::CRectangle GetClipRect() const override
  {
	  return clip_rect_;
  }

  NinePatchImageComponent& SetColor(const COLOR& color);
  COLOR GetColor() const;

  NinePatchImageComponent& SetOffset(InVector2 offset);

  NinePatchImageComponent& SetAngle(const MofFloat angle);

  NinePatchImageComponent& SetAlignment(Mof::TextureAlignment alignment);

  [[nodiscard]] MofFloat GetAngle() const;

private:
  int draw_order_;
  Mof::LPTexture texture_;
  COLOR color_;
  Vector2 offset_;
  MofFloat angle_ = 0;
  Mof::CRectangle clip_rect_{};
  Mof::TextureAlignment alignment_ = Mof::TextureAlignment::TEXALIGN_TOPLEFT;

void CalcPoint();
  std::array<Vector2, 16> point_;
  Mof::Rectangle center_face_{};

  void Draw(const Vector2& offset,const Vector2& left_top, const Vector2& right_bottom,const Vector2& diff);
};

};  // namespace base_engine
