#include "ImageComponent.h"

#include "BaseEngineCore.h"
#include "IBaseEngineCanvasRender.h"

namespace base_engine
{
    ImageComponent::ImageComponent(Actor* owner, int draw_order): RenderComponent(owner, draw_order),
                                                                  texture_(nullptr),
                                                                  color_(MOF_XRGB(255, 255, 255)),
                                                                  mFlashTime(0.0f)
    {}

    void ImageComponent::Draw()
    {
        Vector2 p = owner_->GetPosition() + offset_;

        float a = owner_->GetRotation();
        float s = owner_->GetScale();
        Mof::Vector3 pos = {p.x, p.y, 0};
        BASE_ENGINE(CanvasRender)->AddTexture(texture_, p, {s, s}, angle_, clip_rect_,
                                              color_, alignment_);
    }
}
