#ifndef _WINDOW_H
#define _WINDOW_H

#include <iostream>
#include <string.h>
#include "SDL.h"
#include <GL/gl.h>

#include "LogManager.h"
#include "Vector2.h"

class Window
{
public:
    Window(std::string _caption, int _w, int _h, bool _fullscreen);
    ~Window();
    bool init();
    static bool reshape(const int _w, const int _h);
    static void swapBuffers();
    static void setScreenSizeInfo(int _w, int _h);
    static Vector2 getScreenSizeInfo();

private:
    bool setupVideoMode();

private:
    static Window *instance;

    SDL_Surface* m_surface;
    std::string m_caption;
    Vector2 m_resolution;
    bool m_fullscreen;
};

#endif // _WINDOW_H
