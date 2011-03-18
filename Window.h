#ifndef _WINDOW_H
#define _WINDOW_H

#include <iostream>
#include <string.h>
#include "SDL.h"

class Window
{
public:
    Window(std::string _caption, int _w, int _h, bool _fullscreen);
    ~Window();
    bool init();


private:
    SDL_Surface* m_surface;
    std::string m_caption;
    int m_width;
    int m_height;
    bool m_fullscreen;
};

#endif // _WINDOW_H
