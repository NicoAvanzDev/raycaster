//
// Created by tiger on 5/5/2022.
//

#ifndef RAYCASTER_VECTOR2F_H
#define RAYCASTER_VECTOR2F_H

#include <cmath>

namespace physics
{

class Vector2f
{
  private:
    float v[2];

  public:
    Vector2f();
    Vector2f(float x, float y);

    [[nodiscard]] float x() const;
    [[nodiscard]] float y() const;

    void set_x(float x);
    void set_y(float y);

    static Vector2f normalize(const Vector2f& v);

    Vector2f& operator+=(const Vector2f& vec);
    Vector2f& operator-=(const Vector2f& vec);
};

Vector2f operator+(const Vector2f& a, const Vector2f& b);
Vector2f operator+(const Vector2f& a, int b);
Vector2f operator+(const Vector2f& a, const float b);
Vector2f operator-(const Vector2f& a, const Vector2f& b);
Vector2f operator*(const Vector2f& a, float b);
Vector2f operator*(float b, const Vector2f& a);
Vector2f operator/(const Vector2f& a, float b);

} // namespace physics

#endif // RAYCASTER_VECTOR2F_H
