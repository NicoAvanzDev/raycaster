//
// Created by tiger on 5/5/2022.
//

#ifndef RAYCASTER_VECTOR2F_H
#define RAYCASTER_VECTOR2F_H

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

    Vector2f& operator+=(const Vector2f& vec);
    Vector2f& operator-=(const Vector2f& vec);
};

Vector2f operator*(const Vector2f& a, float b);
Vector2f operator*(float b, const Vector2f& a);

} // namespace physics

#endif // RAYCASTER_VECTOR2F_H
