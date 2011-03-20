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
    mLogManager.init();

    mWindow = new Window(mConfig.getCaption(),
                         mConfig.getScreenSize().x,
                         mConfig.getScreenSize().y,
                         mConfig.isFullscreen());
    mWindow->init();
    mEvent.init();
    mGraphics.init();
    
    int a = 2;
    long b = 4;
    float c = 1.577f;
    double d = 45;
    Vector2 e(12, 54);
    LogManager::logMessage(a);
    LogManager::logMessage(b);
    LogManager::logMessage(c);
    LogManager::logMessage(d);
    LogManager::logMessage(e);
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


