// @IBaseEngineCanvasRender.h
// @brief
// @author ICE
// @date 2022/11/01
// 
// @details

#pragma once

#include <Graphics/Texture.h>

namespace base_engine {
class IBaseEngineCanvasRender
{
 public:
  // TODO Textureクラス作成
  using ITexturePtr = Mof::ITexture*;
  using Rect = Mof::Rectangle;
  using Circle = Mof::Circle;
  using Color = uint_fast32_t;
  using Vector = Mof::Vector2Impl;
  static IBaseEngineCanvasRender* Create();
  virtual ~IBaseEngineCanvasRender();
  virtual void AddTexture(ITexturePtr texture, const Vector& position,
                          const Vector& scale, float angle, const Rect& uv,
                          const Color& color,
                          Mof::TextureAlignment alignment) = 0;
  virtual void AddTexture(ITexturePtr texture, const Vector& position,
                          const Vector& scale, float angle, const Rect& uv,
                          const Color& color, Mof::TextureAlignment alignment,
                          const std::shared_ptr<class Material>& material) = 0;
  virtual void AddTexture(const Mof::Matrix44& wMat, const Rect& srec,
                          const Mof::Vector4& col, const Mof::Vector3& Pivot,
                          const Mof::Vector3& Size, const Mof::Vector2& uvp,
                          const Mof::Vector2& uvs, const MofFloat uva,ITexturePtr pTex) = 0;
  virtual void AddLine(const Vector& position1, const Vector& position2,
                       const Color& color) = 0;
  virtual void AddRect(const Rect& rect, const Color& color) = 0;
  virtual void AddRectFrame(const Rect& rect, const Color& color) = 0;
  virtual void AddCircle(const Circle& circle, const Color& color) = 0;
  virtual void AddCircleFrame(const Circle& circle, const Color& color) = 0;
};

}  // namespace base_engine