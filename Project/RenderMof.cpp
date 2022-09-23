#include "RenderMof.h"

#include <Utilities/GraphicsUtilities.h>
using Mof::CGraphicsUtilities;
namespace base_engine {
RenderMof::RenderMof()
{
}

void RenderMof::AddTexture(const ITexturePtr texture, const Vector& position,
                           const Vector& scale, float angle, const Rect& uv,
                           const Color& color,
                           Mof::TextureAlignment alignment) {
  CGraphicsUtilities::RenderScaleRotateTexture(
      position.x + camera_center_position_.x,
      position.y + camera_center_position_.y, scale.x, scale.y, angle, uv,
      color, alignment, texture);
}

void RenderMof::AddLine(const Vector& position1, const Vector& position2,
                        const Color& color) {
  CGraphicsUtilities::RenderLine(position1.x + camera_center_position_.x,
                                 position1.y + camera_center_position_.y,
                                 position2.x + camera_center_position_.x,
                                 position2.y + camera_center_position_.y,
                                 color);
}

void RenderMof::AddRect(const Rect& rect, const Color& color) {
  CGraphicsUtilities::RenderFillRect(rect.Left + camera_center_position_.x,
                                     rect.Top + camera_center_position_.y,
                                     rect.Right + camera_center_position_.x,
                                     rect.Bottom + camera_center_position_.y,
                                     color);
}

void RenderMof::AddRectFrame(const Rect& rect, const Color& color) {
  CGraphicsUtilities::RenderRect(rect.Left + camera_center_position_.x,
                                 rect.Top + camera_center_position_.y,
                                 rect.Right + camera_center_position_.x,
                                 rect.Bottom + camera_center_position_.y,
                                 color);
}

void RenderMof::AddCircle(const Circle& circle, const Color& color) {
  CGraphicsUtilities::RenderFillCircle(
      circle.Position.x + camera_center_position_.x,
      circle.Position.y + camera_center_position_.y, circle.r, color);
}

void RenderMof::AddCircleFrame(const Circle& circle, const Color& color) {
  CGraphicsUtilities::RenderCircle(
      circle.Position.x + camera_center_position_.x,
      circle.Position.y + camera_center_position_.y, circle.r, color);
}

void RenderMof::SetCameraPosition(const Vector& position) {
  camera_position_ = position;
  const auto& graphics = CGraphicsUtilities::GetGraphics();
  camera_center_position_ = {
      graphics->GetTargetWidth() / static_cast<float>(2) - camera_position_.x,
      graphics->GetTargetHeight() / static_cast<float>(2) - camera_position_.y };
}
}  // namespace base_engine
