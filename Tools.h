#ifndef _TOOLS_H
#define _TOOLS_H
#include <iostream>
#include <sstream>
#include <string.h>
#include "Vector2.h"

#define _VERSION "0.0.1"

struct Config_Info
{
    bool        fullscreen;
    Vector2     windowSize;
    Vector2     windowPosition;     // only if not fullscreen and not windowCentered
    bool        windowCentered;     // only if not fullscreen
    bool        windowResizable;
    int         colorDepth;
    bool        vSync;
    
    //KeySomething keybind;         // TODO
    int         verbose;
    std::string progname;
};

template <class T> std::string to_str(const T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <> std::string to_str<Vector2>(const Vector2 t);

#endif // _TOOLS_H

