#include "Engine.h"

using namespace std;

Engine* Engine::instance = NULL;

Engine::Engine(int argc, char **argv)
    : mConfig(argc, argv), m_quit(false)
{
    instance = this;
}

Engine::~Engine()
{
}

bool
Engine::init()
{
    mWindow = new Window(mConfig.getCaption(),
                         mConfig.getScreenWidth(),
                         mConfig.getScreenHeight(),
                         mConfig.isFullscreen());
    mWindow->init();
    mEvent.init();
    mGraphics.init();

    return true;
}

int
Engine::execute()
{
    while(!mEvent.isExitPressed() && !m_quit)
    {
        SDL_Delay(33);

        mEvent.update();

        if(Event::isKeyPressed(SDLK_ESCAPE))
            m_quit = true;

        mGraphics.beginFrame();
        mGraphics.endFrame();
    }
    return 0;
}

