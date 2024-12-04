#include "math.hpp"

Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
Vec3::Vec3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}

Vec3 Vec3::operator+(const Vec3& o) const {
    return Vec3(x + o.x, y + o.y, z + o.z);
}

Vec3 Vec3::operator-(const Vec3& o) const {
    return Vec3(x - o.x, y - o.y, z - o.z);
}

Vec3 Vec3::operator*(float scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3& Vec3::operator+=(const Vec3& o) {
    x += o.x;
    y += o.y;
    z += o.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& o) {
    x -= o.x;
    y -= o.y;
    z -= o.z;
    return *this;
}
