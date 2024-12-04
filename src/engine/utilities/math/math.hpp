#pragma once

class Vec3 {
public:
    Vec3();
    Vec3(float x, float y, float z);

    float x, y, z;

    Vec3 operator+(const Vec3& o) const;
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator*(float s) const;
    Vec3& operator+=(const Vec3& o);
    Vec3& operator-=(const Vec3& o);
};

template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T min(T a, T b) {
    return a < b ? a : b;
}
