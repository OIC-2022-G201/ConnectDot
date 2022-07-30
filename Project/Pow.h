#pragma once
namespace ce::math {
template <class T, int N>
struct Impl {
  static constexpr T calc(T x) {
    if constexpr (N < 0) {
      return 1 / x * Impl<T, -N>::calc(x);
    } else if constexpr (N & 1) {
      return x * Impl<T, N - 1>::calc(x);
    } else if constexpr (N == 0) {
      (void)x;
      return 1.0;
    } else {
      return Impl<T, N / 2>::calc(x * x);
    }
  }
};

template <int N, class T>
constexpr T pow(T x) {
  return Impl<T, N>::calc(x);
}
}