// @TitlePresenter.h
// @brief
// @author ICE
// @date 2022/12/09
//
// @details

#pragma once
#include <vector>

#include "Button.h"

class TitlePresenter {
  std::vector<std::weak_ptr<Button>> buttons_;
  std::vector<std::weak_ptr<base_engine::ImageComponent>> images_;

 public:
  void Load(std::string_view path);
  void Register() {}
};
