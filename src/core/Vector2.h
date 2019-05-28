#pragma once
#include "MathDetails.h"

template <typename T>
struct Vector2
{
    T x, y;

    inline T magnitude() const noexcept
    {
        return math::sqrt(x * x + y * y);
    }

    inline T sqrMagnitude() const noexcept
    {
        return (x * x + y * y);
    }

    inline Vector2 normalized() const
    {
        return (*this) / this->magnitude();
    }

    inline T dot(const Vector2 &v) const noexcept
    {
        return x * v.x + y * v.y;
    }

    inline T angle(const Vector2 &b) const
    {
        math::acos(this->dot(b) / (this->magnitude() * b.magnitude()));
    }

    inline T distance(const Vector2 &b) const
    {
        return (b - (*this)).magnitude();
    }

    inline Vector2 reflect(const Vector2 &normal) const noexcept
    {
        return this->project(normal) * T(-2) + (*this);
    }

    inline Vector2 project(const Vector2 &normal) const
    {
        auto n = normal.normalized();
        return n * n.dot(*this);
    }
};

template <typename T>
inline Vector2<T> operator-(Vector2<T> &v) noexcept
{
    return {-v.x, -v.y, -v.z};
}

template <typename T, typename U>
inline Vector2<T> operator*(U s, Vector2<T> &v) noexcept
{
    return {T(v.x * s), T(v.y * s), T(v.z * s)};
}

template <typename T, typename U>
inline Vector2<T> operator*(const Vector2<T> &v, U s) noexcept
{
    return {T(v.x * s), T(v.y * s), T(v.z * s)};
}

template <typename T, typename U>
inline Vector2<T> operator/(const Vector2<T> &v, U s) noexcept
{
    return v * T(1 / s);
}

template <typename T>
inline Vector2<T> operator+(const Vector2<T> &a, const Vector2<T> &b) noexcept
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

template <typename T>
inline Vector2<T> operator-(const Vector2<T> &a, const Vector2<T> &b) noexcept
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

template <typename T>
inline bool operator==(const Vector2<T> &a, const Vector2<T> &b) noexcept
{
    return a.x == b.x && a.y == b.y;
}

template <typename T>
inline bool operator!=(const Vector2<T> &a, const Vector2<T> &b) noexcept
{
    return a.x != b.x || a.y != b.y;
}

using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;