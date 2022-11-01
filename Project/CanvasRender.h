// @CanvasRender.h
// @brief
// @author ICE
// @date 2022/11/01
//
// @details

#pragma once
#include "IBaseEngineCanvasRender.h"

namespace base_engine {
class CanvasRender : public IBaseEngineCanvasRender {
 public:
  CanvasRender();
  void AddTexture(ITexturePtr texture, const Vector& position,
                  const Vector& scale, float angle, const Rect& uv,
                  const Color& color, Mof::TextureAlignment alignment) override;
  void AddLine(const Vector& position1, const Vector& position2,
               const Color& color) override;
  void AddRect(const Rect& rect, const Color& color) override;

  void AddRectFrame(const Rect& rect, const Color& color) override;
  void AddCircle(const Circle& circle, const Color& color) override;

  void AddCircleFrame(const Circle& circle, const Color& color) override;
};
}  // namespace base_engine
