#pragma once
#include <Graphics/DirectX11/DX11Texture.h>
#include <Math/MathCommon.h>

#include "Actor.h"
#include "Component.h"

namespace base_engine {
class RenderComponent : public Component {
 public:
  RenderComponent(class Actor* owner, int draw_order = 100);
  ~RenderComponent() override;

  void Update() override;
  void SetEnabled(const bool enabled) { enabled_ = enabled; }
  bool GetEnabled() const { return enabled_; }
  virtual void Draw() = 0;

  [[nodiscard]] int GetDrawOrder() const { return draw_order_; }
  
 private:
  int draw_order_;
  bool enabled_ = true;
};
}  // namespace base_engine