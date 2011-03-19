#ifndef _WINDOW_H
#define _WINDOW_H

#include <iostream>
#include <string.h>
#include "SDL.h"
#include <GL/gl.h>

#include "Vector2.h"

class Window
{
public:
    Window(std::string _caption, int _w, int _h, bool _fullscreen);
    ~Window();
    bool init();
    static void swapBuffers();

private:
    SDL_Surface* m_surface;
    std::string m_caption;
    Vector2 m_resolution;
    bool m_fullscreen;
};

#endif // _WINDOW_H
