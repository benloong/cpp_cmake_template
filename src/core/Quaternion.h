#pragma once
#include "Vector3.h"

struct Quaternion
{
    float x, y, z, w;

    inline Quaternion inverse() const noexcept
    {
        return {-x, -y, -z, w};
    }

    inline Quaternion slerp(const Quaternion &b, float t)
    {
        return {x, y, z, w};
    }

    inline Vector3f toEuler()
    {

        auto xx = x * x;
        auto yy = y * y;
        auto zz = z * z;
        auto ww = w * w;

        return {
            math::atan2(2 * (y * z + x * w), -xx - yy + zz + ww),
            math::asin(math::clamp(2 * (y * w - x * z), -1.0f, 1.0f)),
            math::atan2(2 * (x * y + z * w), xx - yy - zz + ww)};
    }
    
    static inline Quaternion fromEuler(float x, float y, float z)
    {
        auto cr = math::cos(x * 0.5f);
        auto cp = math::cos(y * 0.5f);
        auto cy = math::cos(z * 0.5f);

        auto sr = math::sin(x * 0.5f);
        auto sp = math::sin(y * 0.5f);
        auto sy = math::sin(z * 0.5f);

        auto cpcy = cp * cy;
        auto spsy = sp * sy;
        auto cpsy = cp * sy;
        auto spcy = sp * cy;

        return {sr * cpcy - cr * spsy,
                cr * spcy + sr * cpsy,
                cr * cpsy - sr * spcy,
                cr * cpcy + sr * spsy};
    }
};
