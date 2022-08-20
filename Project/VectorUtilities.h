// @file VectorUtilities.h
// @brief
// @author ICE
// @date 2022/08/17
//
// @details

#pragma once

#include <cmath>

#include "Vector.h"
namespace base_engine {

class VectorUtilities {
 public:
  static Floating Dot(InVector2 a, InVector2 b);
  static Floating Cross(InVector2 a, InVector2 b);
  static Floating Length(InVector2 a);
  static Vector2 Normalize(InVector2 a);
  static Vector2 TripleProduct(InVector2 a, InVector2 b, InVector2 c);

  static float MagnitudeSquared(const Vector2& v);

  /**
   * \brief ベクトルを左へ回転
   * \param v 入力ベクトル
   * \return { y , -x }
   */
  static Vector2 Left(InVector2 v);

  /**
   * \brief ベクトルを右へ回転
   * \param v 入力ベクトル
   * \return { -y , x }
   */
  static Vector2 Right(InVector2 v);

  static bool IsZero(InVector2 v);
  VectorUtilities() = delete;
};
}  // namespace base_engine