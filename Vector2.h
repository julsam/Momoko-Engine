#ifndef _VECTOR2_H
#define _VECTOR2_H

class Vector2
{
public:
    Vector2();
    Vector2(float _x, float _y);
    Vector2(int _x, int _y);

    float operator[](int i);
    Vector2 operator=(const Vector2 &_vector2);

public:
    float x, y;

};

#endif // _VECTOR2_H

