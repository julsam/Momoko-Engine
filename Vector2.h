#ifndef _VECTOR2_H
#define _VECTOR2_H

class Vector2
{
public:
    Vector2();
    Vector2(int _x, int _y);

    float operator[](int i);

public:
    float x, y;

};

#endif // _VECTOR2_H

