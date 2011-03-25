#ifndef _WINDOW_H
#define _WINDOW_H

#include <iostream>
#include <string>
#include "SDL.h"
#include <GL/gl.h>

#include "Vector2.h"

class Window
{
public:
    Window(std::string _caption, int _w, int _h, bool _fullscreen);
    ~Window();
    bool init();
    static bool reshape(const int _w, const int _h);
    static Vector2 getWindowSize();
    static void swapBuffers();
    static void changeFullscreen();
    static void setCaption(const std::string& title);

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
