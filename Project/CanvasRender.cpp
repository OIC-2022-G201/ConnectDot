#include "CanvasRender.h"

#include <Utilities/GraphicsUtilities.h>

#include "Vector.h"
using Mof::CGraphicsUtilities;
using Mof::Vector3;
using Mof::Vector4;
namespace base_engine {

CanvasRender::CanvasRender() {}

void CanvasRender::AddTexture(const ITexturePtr texture, const Vector& position,
                              const Vector& scale, float angle, const Rect& uv,
                              const Color& color,
                              Mof::TextureAlignment alignment) {
  CGraphicsUtilities::RenderScaleRotateTexture(position.x, position.y, scale.x,
                                               scale.y, angle, uv, color,
                                               alignment, texture);
}

void CanvasRender::AddLine(const Vector& position1, const Vector& position2,
                           const Color& color) {
  CGraphicsUtilities::RenderLine(position1.x, position1.y, position2.x,
                                 position2.y, color);
}

void CanvasRender::AddRect(const Rect& rect, const Color& color) {
  CGraphicsUtilities::RenderFillRect(rect.Left, rect.Top, rect.Right,
                                     rect.Bottom, color);
}

void CanvasRender::AddRectFrame(const Rect& rect, const Color& color) {
  CGraphicsUtilities::RenderRect(rect.Left, rect.Top, rect.Right, rect.Bottom,
                                 color);
}

void CanvasRender::AddCircle(const Circle& circle, const Color& color) {
  CGraphicsUtilities::RenderFillCircle(circle.Position.x, circle.Position.y,
                                       circle.r, color);
}

void CanvasRender::AddCircleFrame(const Circle& circle, const Color& color) {
  CGraphicsUtilities::RenderCircle(circle.Position.x, circle.Position.y,
                                   circle.r, color);
}

Mof::CVector2 vpos[4] = {{0, 0}, {1, 0}, {1, 1}, {1, 1}};
Mof::CVector4 vcol[4] = {
    {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

void CanvasRender::AddTexture(const Mof::Matrix44& wMat, const Rect& srec,
                              const Mof::Vector4& col,
                              const Mof::Vector3& Pivot,
                              const Mof::Vector3& Size, const Mof::Vector2& uvp,
                              const Mof::Vector2& uvs, const MofFloat uva,
                              ITexturePtr pTex) {
  CGraphicsUtilities::RenderTexture(wMat, srec, col, Pivot, Size, uvp, uvs, 0,
                                    &vpos[0], &vcol[0], 0.0f, pTex);
}
}  // namespace base_engine