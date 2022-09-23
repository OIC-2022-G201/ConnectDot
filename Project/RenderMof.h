#pragma once

#include "IBaseEngineRender.h"
namespace base_engine {
class RenderMof final : public IBaseEngineRender {
  Vector camera_position_{0,0};
  Vector camera_center_position_{0,0};

 public:
  RenderMof();
  void AddTexture(ITexturePtr texture, const Vector& position,
                  const Vector& scale, float angle, const Rect& uv,
                  const Color& color, Mof::TextureAlignment alignment) override;
  void AddLine(const Vector& position1, const Vector& position2,
               const Color& color) override;
  void AddRect(const Rect& rect, const Color& color) override;

  void AddRectFrame(const Rect& rect, const Color& color) override;
  void AddCircle(const Circle& circle, const Color& color) override;

  void AddCircleFrame(const Circle& circle, const Color& color) override;
  void SetCameraPosition(const Vector& position) override;
  Vector GetCameraPosition() override { return camera_position_;
  }
private:
};
}  // namespace base_engine