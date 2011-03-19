#include "Window.h"

using namespace std;

Window::Window(string _caption, int _w=640, int _h=480, 
        bool _fullscreen=false)
    : m_surface(NULL),
      m_caption(_caption),
      m_resolution(_w, _h),
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
    {
        cout << "Couldn't initialize SDL" << endl;
        return false;
    }

    // I honestly have no idea what all 
    // this attribute are for....
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,      8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,       8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,      8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,      16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,     16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,    16);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,  8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,8);

    /**
     * Usefull tags to remember :
     * SDL_HWSURFACE | SDL_SWSURFACE | SDL_RESIZABLE | SDL_NOFRAME
     * | SDL_FULLSCREEN | SDL_DOUBLEBUF | SDL_GL_DOUBLEBUFFER | SDL_OPENGL
     */
    int flags = SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE
        | SDL_OPENGL | ( m_fullscreen ? SDL_FULLSCREEN : 0 );

    if((m_surface = SDL_SetVideoMode(m_resolution.x, m_resolution.y, 32, flags)) == NULL)
    {
        cout << "Couldn't set up video mode" << endl;
        return false;
    }

    SDL_WM_SetCaption(m_caption.c_str(), NULL);
    SDL_ShowCursor(1);

    return true;
}

void
Window::swapBuffers()
{
    SDL_GL_SwapBuffers();
}

