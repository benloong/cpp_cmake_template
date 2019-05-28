#pragma once

struct Matrix
{
    float data[4][4];

    inline float *operator[](int r)
    {
        return data[r];
    }
};
