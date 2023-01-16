#pragma once

#include <Graphics/DirectX11/DX11Texture.h>

#include "IBaseEngineRender.h"
namespace base_engine {
class RenderMof final : public IBaseEngineRender {
  Vector camera_position_{0,0};
  Vector camera_center_position_{0,0};
  std::shared_ptr<Material> camera_material_;
  Mof::CTexture target_texture_;
  Mof::LPRenderTarget hold_render_target_buffer_ = nullptr;
 public:
  void Initialize() override;
  RenderMof();
  void AddTexture(ITexturePtr texture, const Vector& position,
                  const Vector& scale, float angle, const Rect& uv,
                  const Color& color, Mof::TextureAlignment alignment) override;
  void AddTexture(ITexturePtr texture, const Vector& position, const Vector& scale, float angle, const Rect& uv,
	  const Color& color, Mof::TextureAlignment alignment, const Material& material) override;
  void AddLine(const Vector& position1, const Vector& position2,
               const Color& color) override;
  void AddRect(const Rect& rect, const Color& color) override;

  void AddRectFrame(const Rect& rect, const Color& color) override;
  void AddCircle(const Circle& circle, const Color& color) override;

  void AddCircleFrame(const Circle& circle, const Color& color) override;
  void SetCameraPosition(const Vector& position) override;
  void SetMaterial(const std::shared_ptr<Material>& material) override;
  void Begin() override;

  void End() override;

  Vector GetCameraPosition() override;
private:
};
}  // namespace base_engine