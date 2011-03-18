#include "Window.h"

using namespace std;

Window::Window(string _caption, int _w=640, int _h=480, bool _fullscreen=false)
    : m_caption(_caption),
      m_width(_w),
      m_height(_h),
      m_fullscreen(_fullscreen)
{

}

Window::~Window()
{
    SDL_FreeSurface(m_surface);
    SDL_Quit();
}

bool
Window::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;

    int flags = SDL_OPENGL | SDL_DOUBLEBUF | ( m_fullscreen ? SDL_FULLSCREEN : 0 );

    if((m_surface = SDL_SetVideoMode(m_width, m_height, 32, flags)) == NULL)
        return false;

    SDL_WM_SetCaption(m_caption.c_str(), NULL);
    SDL_ShowCursor(0);

    return true;
}

