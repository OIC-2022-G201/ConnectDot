#pragma once
#include <Graphics/Texture.h>

namespace base_engine {
class IBaseEngineRender {
 public:
  // TODO TextureÉNÉâÉXçÏê¨
  using ITexturePtr = Mof::ITexture*;
  using Rect = Mof::Rectangle;
  using Circle = Mof::Circle;
  using Color = uint_fast32_t;
  using Vector = Mof::Vector2Impl;
  static IBaseEngineRender* Create();
  virtual ~IBaseEngineRender();
  virtual void AddTexture(ITexturePtr texture,
                                         const Vector& position,
                                         const Vector& scale, float angle,
                                         const Rect& uv, const Color& color,
                                         Mof::TextureAlignment alignment) = 0;
  virtual void AddLine(const Vector& position1, const Vector& position2,
                       const Color& color) = 0;
  virtual void AddRect(const Rect& rect, const Color& color) = 0;
  virtual void AddRectFrame(const Rect& rect, const Color& color) = 0;
  virtual void AddCircle(const Circle& circle, const Color& color) = 0;
  virtual void AddCircleFrame(const Circle& circle, const Color& color) = 0;
  virtual void SetCameraPosition(const Vector& position) = 0;
  virtual Vector GetCameraPosition() = 0;
};
}  // namespace base_engine