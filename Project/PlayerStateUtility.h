#pragma once
#include <numbers>
#include <cmath>

using std::numbers::pi_v;
static float CalculationJumpAcceleration(const float H, const uint16_t T, const uint16_t X){
	const float t = T;
	const float x = X;
	return (H / t) / t * -std::sin(pi_v<float>*x / t) * std::pow(pi_v<float>, 2);
}