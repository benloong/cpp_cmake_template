#pragma once
#include <cmath>
#include <algorithm>

namespace math
{
using namespace std;

template <typename T, typename S>
T lerp(const T &a, const T &b, S t)
{
    return a + (b - a) * t;
}

template <typename T>
T smoothStep(const T &x)
{
    return x * x * (T(3) - x * T(2));
}

template <typename T>
T clamp(const T &v, T min, T max)
{
    return std::max(std::min(v, max), min);
}

template <typename T, typename S>
T mix(const T &v0, const T &v1, const S &scale0, const S &scale1)
{
    return v0 * scale0 + v1 * scale1;
}
} // namespace math
