#pragma once
#include "MathDetails.h"

template <typename T>
struct Vector3
{
    T x, y, z;

    inline T magnitude() const noexcept
    {
        return math::sqrt(x * x + y * y + z * z);
    }

    inline T sqrMagnitude() const noexcept
    {
        return (x * x + y * y + z * z);
    }

    inline Vector3 normalized() const
    {
        return (*this) / (this->magnitude());
    }

    inline T dot(const Vector3 &v) const noexcept
    {
        return x * v.x + y * v.y + z * v.z;
    }

    inline Vector3 cross(const Vector3 &v) const noexcept
    {
        return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
    }

    inline T angle(const Vector3 &b) const
    {
        math::acos(this->dot(b) / (this->magnitude() * b.magnitude()));
    }

    inline T distance(const Vector3 &b) const
    {
        return (b - (*this)).magnitude();
    }

    inline Vector3 reflect(const Vector3 &normal) const noexcept
    {
        return this->project(normal) * T(-2) + (*this);
    }

    inline Vector3 project(const Vector3 &normal) const
    {
        return normal * normal.dot(*this) / normal.dot(normal);
    }
};

template <typename T>
inline Vector3<T> operator-(Vector3<T> &v) noexcept
{
    return {-v.x, -v.y, -v.z};
}

template <typename T, typename U>
inline Vector3<T> operator*(U s, Vector3<T> &v) noexcept
{
    return {T(v.x * s), T(v.y * s), T(v.z * s)};
}

template <typename T, typename U>
inline Vector3<T> operator*(const Vector3<T> &v, U s) noexcept
{
    return {T(v.x * s), T(v.y * s), T(v.z * s)};
}

template <typename T, typename U>
inline Vector3<T> operator/(const Vector3<T> &v, U s) noexcept
{
    return v * T(1 / s);
}

template <typename T>
inline Vector3<T> operator+(const Vector3<T> &a, const Vector3<T> &b) noexcept
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

template <typename T>
inline Vector3<T> operator-(const Vector3<T> &a, const Vector3<T> &b) noexcept
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

template <typename T>
inline bool operator==(const Vector3<T> &a, const Vector3<T> &b) noexcept
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

template <typename T>
inline bool operator!=(const Vector3<T> &a, const Vector3<T> &b) noexcept
{
    return a.x != b.x || a.y != b.y || a.z != b.z;
}

using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;