// @ParallaxCameraFlowLayer.h
// @brief
// @author
// @date 2023/01/07
//
// @details

#pragma once
#include "Actor.h"

class ParallaxCameraFlowLayer {
 public:
  using CreateInfo = struct {
    /**
     * \brief 構造名
     */
    std::string_view literal_name;
    /**
     * \brief 0から1のカメラ追従割合(0で完全停止 1でカメラと同じ座標)
     */
    float follow_per;

    int draw_order;
  };

  static base_engine::Actor* Create(base_engine::Game* game,
                                    std::string_view name,
                                    const std::span<CreateInfo>& literals);
};
