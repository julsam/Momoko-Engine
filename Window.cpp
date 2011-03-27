#include "Window.h"
#include "LogManager.h"
#include "Config.h"

using namespace std;

Window* Window::instance = NULL;

Window::Window(string _caption, int _w=640, int _h=480, 
        bool _fullscreen=false)
    : m_surface(NULL),
      m_caption(_caption),
      m_windowSize(_w, _h),
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
    LogManager::getSingleton()->logMessage( "[Window] Init." );
    /**
    //TODO
    if not first launch (there is a config file)
        putenv("SDL_VIDEO_WINDOW_POS=10,10");
    else
     */

    /* /!\ undesired behavior: when resized,
     * the window goes to the center of the screen
     */
    if (Config::getInfos()->windowCentered)
    {
        putenv((char*)"SDL_VIDEO_CENTERED=1");
        LogManager::getSingleton()->logMessage( "[Window] Set window centered" );
    }

    putenv((char*)"SDL_DEBUG=1");

    if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0)
    {
        LogManager::logMessage("Couldn't initialize SDL");
        return false;
    }

    // get screen resolution
    const SDL_VideoInfo* _i = SDL_GetVideoInfo();
    if ( _i->current_w && _i->current_h )
        m_sysResolution = Vector2(_i->current_w, _i->current_h);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,      8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,       8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,      8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,      16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,     32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,    1);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,  8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,8);

    LogManager::getSingleton()->logMessage( "[Window] Setup video mode." );
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
     * SDL_HWSURFACE | SDL_SWSURFACE | SDL_RESIZABLE | SDL_NOFRAME | ASYNCBLIT
     * | SDL_FULLSCREEN | SDL_DOUBLEBUF | SDL_GL_DOUBLEBUFFER | SDL_OPENGL
     */
    int flags = SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER
        | ( Config::getInfos()->windowResizable ? SDL_RESIZABLE : 0 )
        | SDL_OPENGL | ( instance->m_fullscreen ? SDL_FULLSCREEN : 0 );

    int bpp = Config::getInfos()->colorDepth;

    if ((instance->m_surface = SDL_SetVideoMode(instance->m_windowSize.x, 
                    instance->m_windowSize.y, bpp, flags)) == NULL)
    {
        LogManager::logMessage("Couldn't set up video mode");
        return false;
    }

    SDL_WM_SetCaption(instance->m_caption.c_str(), NULL);

    return true;
}

/*
 * /!\ In Windows, setting the video mode
 *     resets the current OpenGL context
 */
bool
Window::reshape(const int _w, const int _h)
{
    // little tricks to disable centered mode
    // when resized.
    if (Config::getInfos()->windowCentered)
        putenv((char*)"SDL_VIDEO_CENTERED");

    LogManager::getSingleton()->logMessage("[Window] Window size changed "+ to_str(_w) +"x"+ to_str(_h));
    instance->m_windowSize = Vector2(_w, _h);
    return instance->setupVideoMode();
}


Vector2
Window::getWindowSize()
{
    return instance->m_windowSize;
}

void
Window::swapBuffers()
{
    SDL_GL_SwapBuffers();
}

void
Window::changeFullscreen()
{
    instance->m_fullscreen = !instance->m_fullscreen;
    reshape(instance->m_sysResolution.x, instance->m_sysResolution.y);
}

void
Window::setCaption(const string& title)
{
    instance->m_caption = title;
    SDL_WM_SetCaption(instance->m_caption.c_str(), NULL);
}

