#ifndef _TOOLS_H
#define _TOOLS_H
#include <iostream>
#include <sstream>
#include <string.h>
#include "Vector2.h"

template <class T> std::string to_str(const T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <> std::string to_str<Vector2>(const Vector2 t);

#endif // _TOOLS_H

