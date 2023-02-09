// @AudioVolume.h
// @brief
// @author ICE
// @date 2023/02/09
//
// @details

#pragma once

class AudioVolume {
  float se_volume_ = 0.3;
  float bgm_volume_ = 0.3;

 public:
  float SEVolume() const { return se_volume_; }
  float BGMVolume() const { return bgm_volume_; }
  void SetSEVolume(float volume) { se_volume_ = volume; }
  void SetBGMVolume(float volume) { bgm_volume_ = volume; }
};
