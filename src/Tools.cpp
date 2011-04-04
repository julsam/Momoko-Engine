#include "Tools.h"

template <>
std::string to_str<Vector2>(const Vector2 t)
{
    std::stringstream ss;
    ss << "(" << t.x << ", " << t.y << ")";
    return ss.str();
}

