#include "Window.h"

using namespace std;

Window* Window::instance = NULL;

Window::Window(string _caption, int _w=640, int _h=480, 
        bool _fullscreen=false)
    : m_surface(NULL),
      m_caption(_caption),
      m_resolution(_w, _h),
      m_fullscreen(_fullscreen)
{
    instance = this;
}

Window::~Window()
{
    SDL_FreeSurface(m_surface);
    SDL_Quit();
}

bool
Window::init()
{
    /**
    //TODO
    if not first launch (there is a config file)
        putenv("SDL_VIDEO_WINDOW_POS=10,10");
    else
        putenv("SDL_VIDEO_CENTERED=1");
     */

    // \o/ note : (char*) cast make g++ stop complaining about
    // `deprecated conversion from string constant to ‘char*’`
    putenv((char*)"SDL_DEBUG=1"); // let's try this too

    if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0)
    {
        LogManager::logMessage("Couldn't initialize SDL");
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

    if(!setupVideoMode())
        return false;

    SDL_ShowCursor(1);
    
    return true;
}

bool
Window::setupVideoMode()
{
/**
     * Usefull tags to remember :
     * SDL_HWSURFACE | SDL_SWSURFACE | SDL_RESIZABLE | SDL_NOFRAME
     * | SDL_FULLSCREEN | SDL_DOUBLEBUF | SDL_GL_DOUBLEBUFFER | SDL_OPENGL
     */
    int flags = SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE
        | SDL_OPENGL | ( instance->m_fullscreen ? SDL_FULLSCREEN : 0 );

    if((instance->m_surface = SDL_SetVideoMode(instance->m_resolution.x, 
                    instance->m_resolution.y, 32, flags)) == NULL)
    {
        LogManager::logMessage("Couldn't set up video mode");
        return false;
    }

    SDL_WM_SetCaption(instance->m_caption.c_str(), NULL);

    return true;
}

bool
Window::reshape(const int _w, const int _h)
{
    instance->m_resolution = Vector2(_w, _h);
    return instance->setupVideoMode();
}

void
Window::swapBuffers()
{
    SDL_GL_SwapBuffers();
}

void
Window::setScreenSizeInfo(int _w, int _h)
{
    instance->m_resolution = Vector2(_w, _h);
}

Vector2
Window::getScreenSizeInfo()
{
    return instance->m_resolution;
}

