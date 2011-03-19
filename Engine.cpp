#include "Engine.h"

using namespace std;

Engine::Engine(int argc, char **argv)
    : m_config(argc, argv), m_quit(false)
{
}

Engine::~Engine()
{
}

bool
Engine::init()
{
    m_window = new Window(m_config.getCaption(),
                          m_config.getScreenWidth(),
                          m_config.getScreenHeight(),
                          m_config.isFullscreen());
    m_window->init();
    m_event.init();

    return true;
}

int
Engine::execute()
{
    while(!m_event.isExitPressed() && !m_quit)
    {
        SDL_Delay(33);

        m_event.update();

        if(m_event.isKeyPressed(SDLK_ESCAPE))
            m_quit = true;

    }
    return 0;
}

