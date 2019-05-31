#pragma once
#include "MathDetails.h"

template <typename T>
struct Vector4
{
    T x, y, z, w;

    inline T magnitude() const noexcept
    {
        return math::sqrt(x * x + y * y + z * z + w * w);
    }

    inline T sqrMagnitude() const noexcept
    {
        return (x * x + y * y + z * z + w * w);
    }

    inline Vector4 normalized() const
    {
        return *this / this->magnitude();
    }

    inline T dot(const Vector4 &v) const noexcept
    {
        return x * v.x + y * v.y + z * v.z + w * v.w;
    }
};

template <typename T>
inline Vector4<T> operator-(const Vector4<T> &v) noexcept
{
    return {-v.x, -v.y, -v.z, -v.w};
}

template <typename T, typename U>
inline Vector4<T> operator*(U s, const Vector4<T> &v) noexcept
{
    return {T(v.x * s), T(v.y * s), T(v.z * s), T(v.w * s)};
}

template <typename T, typename U>
inline Vector4<T> operator*(const Vector4<T> &v, U s) noexcept
{
    return {T(v.x * s), T(v.y * s), T(v.z * s), T(v.w * s)};
}

template <typename T, typename U>
inline Vector4<T> operator/(const Vector4<T> &v, U s)
{
    return v * T(1 / s);
}

template <typename T>
inline Vector4<T> operator+(const Vector4<T> &a, const Vector4<T> &b) noexcept
{
    return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

template <typename T>
inline Vector4<T> operator-(const Vector4<T> &a, const Vector4<T> &b) noexcept
{
    return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

template <typename T>
inline bool operator==(const Vector4<T> &a, const Vector4<T> &b) noexcept
{
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

template <typename T>
inline bool operator!=(const Vector4<T> &a, const Vector4<T> &b) noexcept
{
    return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
}
using Vector4f = Vector4<float>;
using Vector4i = Vector4<int>;