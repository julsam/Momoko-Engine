#ifndef _ENGINE_H
#define _ENGINE_H

#include "Config.h"
#include "Window.h"
#include "Event.h"
#include "Graphics.h"
#include "LogManager.h"

class Engine
{
public:
    Engine(int argc, char **argv);
    ~Engine();
    bool init();
    int execute();

private:
    static Engine* instance;
    LogManager mLogManager;
    Config mConfig;
    Window* mWindow;
    Event mEvent;
    Graphics mGraphics;

    bool m_quit;
    double deltaTime;
    long thisTime;
    long lastTime;
};

#endif // _ENGINE_H
