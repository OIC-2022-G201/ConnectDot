// @file MofSpriteMotionController.h
// @brief
// @author ICE
// @date 2023/01/01
//
// @details

#pragma once
#include <Graphics/SpriteMotionController.h>

#include "ISpriteAnimationComponent.h"
namespace base_engine {

class SpriteAnimation : public Mof::CSpriteAnimation {
 public:
  SpriteAnimation(const SpriteAnimationClip& clip) {
    m_Name = clip.name.data();
    MofS32 nc;
    const size_t N = clip.pattern.size();
    for (nc = 0; nc < N && clip.pattern[nc].wait > 0; nc++)
      ;
    m_RectKeyFrame.ReSize(nc + 1);
    m_RectKeyFrame.SetFlag(((clip.is_loop)
                                ? Mof::KEYFRAMEARRAY_ARRAYMEMBERDELETE |
                                      Mof::KEYFRAMEARRAY_LOOPALLFRAME |
                                      Mof::KEYFRAMEARRAY_ARRAYMEMBERCOPY
                                : Mof::KEYFRAMEARRAY_ARRAYMEMBERDELETE |
                                      Mof::KEYFRAMEARRAY_ARRAYMEMBERCOPY));
    MofFloat wt = 0.0f;
    MofFloat ft = ((Mof::CUtilities::GetRestrictFPS() <= 0)
                       ? 1.0f
                       : 1.0f / Mof::CUtilities::GetRestrictFPS());
    for (int i = 0; i <= nc; i++) {
      if (i == nc) {
        const MofFloat ox = clip.offset_x + clip.width * clip.pattern[i - 1].no;
        const MofFloat oy =
            clip.offset_y + clip.height * clip.pattern[i - 1].step;
        Mof::Rectangle r(ox, oy, ox + clip.width, oy + clip.height);
        auto pKey = new Mof::CRectangleKeyFrame(
            r, wt, 0, Mof::KEYINTERPOLATION_NONE, NULL);
        m_RectKeyFrame.SetData(pKey, i);
      } else {
        MofFloat ox = clip.offset_x + clip.width * clip.pattern[i].no;
        MofFloat oy = clip.offset_y + clip.height * clip.pattern[i].step;
        Mof::Rectangle r(ox, oy, ox + clip.width, oy + clip.height);
        auto pKey = new Mof::CRectangleKeyFrame(
            r, wt, 0, Mof::KEYINTERPOLATION_NONE, NULL);
        m_RectKeyFrame.SetData(pKey, i);
        wt += clip.pattern[i].wait * ft;
      }
    }
  }
};
class MofSpriteMotionController : public Mof::CSpriteMotionController {
 public:

  MofBool Create(const SpriteAnimationClip& ac);

  MofBool Create(const std::span<SpriteAnimationClip> ac);
};
}  // namespace base_engine
