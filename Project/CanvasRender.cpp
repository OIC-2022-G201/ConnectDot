#include "CanvasRender.h"

#include <Utilities/GraphicsUtilities.h>
using Mof::CGraphicsUtilities;

namespace base_engine {

CanvasRender::CanvasRender() {}


void CanvasRender::AddTexture(const ITexturePtr texture, const Vector& position,
                           const Vector& scale, float angle, const Rect& uv,
                           const Color& color,
                           Mof::TextureAlignment alignment) {
  CGraphicsUtilities::RenderScaleRotateTexture(
      position.x,
      position.y, scale.x, scale.y, angle, uv,
      color, alignment, texture);
}

void CanvasRender::AddLine(const Vector& position1, const Vector& position2,
                        const Color& color) {
  CGraphicsUtilities::RenderLine(position1.x,
                                 position1.y,
                                 position2.x,
                                 position2.y,
                                 color);
}

void CanvasRender::AddRect(const Rect& rect, const Color& color) {
  CGraphicsUtilities::RenderFillRect(rect.Left,
                                     rect.Top,
                                     rect.Right,
                                     rect.Bottom,
                                     color);
}

void CanvasRender::AddRectFrame(const Rect& rect, const Color& color) {
  CGraphicsUtilities::RenderRect(rect.Left,
                                 rect.Top,
                                 rect.Right,
                                 rect.Bottom,
                                 color);
}

void CanvasRender::AddCircle(const Circle& circle, const Color& color) {
    CGraphicsUtilities::RenderFillCircle(
      circle.Position.x,
      circle.Position.y, circle.r, color);
}

void CanvasRender::AddCircleFrame(const Circle& circle, const Color& color) {
  CGraphicsUtilities::RenderCircle(
      circle.Position.x,
      circle.Position.y, circle.r, color);
}

}  // namespace base_engine