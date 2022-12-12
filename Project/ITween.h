// @ITween.h
// @brief
// @author ICE
// @date 2022/12/12
//
// @details

#pragma once
namespace ma_tween::core {
/// <summary>
/// Typeless interface for all core Tween functionality.
/// </summary>
__interface ITween {

  float GetTotalDuration(bool include_delay = false);

  /// <summary>
  /// Cancel the tween and remove the component.
  /// </summary>
  void Cancel();
};
}  // namespace ma_tween::core