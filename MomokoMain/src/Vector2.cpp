#include "../include/Vector2.h"

Vector2::Vector2()
    : x(0), y(0)
{

}

Vector2::Vector2(float _x, float _y)
    : x(_x), y(_y)
{

}

Vector2::Vector2(int _x, int _y)
    : x(_x), y(_y)
{

}

float
Vector2::operator[](int i)
{
    if(i <= 0)
        return x;
    else
        return y;
}

Vector2
Vector2::operator=(const Vector2 &_vector2)
{
    x = _vector2.x;
    y = _vector2.y;
    return *this;
}
