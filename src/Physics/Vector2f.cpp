//
// Created by tiger on 5/5/2022.
//

#include "Vector2f.h"

namespace physics
{

Vector2f::Vector2f() : v{0, 0}
{
}
Vector2f::Vector2f(float x, float y) : v{x, y}
{
}

float Vector2f::x() const
{
    return v[0];
}
float Vector2f::y() const
{
    return v[1];
}
void Vector2f::set_x(float x)
{
    v[0] = x;
}
void Vector2f::set_y(float y)
{
    v[1] = y;
}

Vector2f Vector2f::normalize(const Vector2f& v)
{
    float mag = sqrt(v.x() * v.x() + v.y() * v.y());
    return v / mag;
}

Vector2f operator+(const Vector2f& a, const Vector2f& b)
{
    return {a.x() + b.x(), a.y() + b.y()};
}
Vector2f operator+(const Vector2f& a, const int b)
{
    return {a.x() + static_cast<float>(b), a.y() + static_cast<float>(b)};
}
Vector2f operator+(const Vector2f& a, const float b)
{
    return {a.x() + b, a.y() + b};
}
Vector2f operator-(const Vector2f& a, const Vector2f& b)
{
    return {a.x() - b.x(), a.y() - b.y()};
}
Vector2f operator*(const Vector2f& a, const Vector2f& b)
{
    return {a.x() * b.x(), a.y() * b.y()};
}
Vector2f operator*(const Vector2f& a, float b)
{
    return {a.x() * b, a.y() * b};
}
Vector2f operator/(const Vector2f& a, float b)
{
    return {a.x() / b, a.y() / b};
}
Vector2f operator*(float b, const Vector2f& a)
{
    return a * b;
}
Vector2f& Vector2f::operator+=(const Vector2f& vec)
{
    this->v[0] += vec.v[0];
    this->v[1] += vec.v[1];
    return *this;
}
Vector2f& Vector2f::operator-=(const Vector2f& vec)
{
    this->v[0] -= vec.v[0];
    this->v[1] -= vec.v[1];
    return *this;
}

} // namespace physics