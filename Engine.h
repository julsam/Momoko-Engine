#ifndef _ENGINE_H
#define _ENGINE_H

#include "Config.h"
#include "Window.h"
#include "Event.h"
#include "Graphics.h"

class Engine
{
public:
    Engine(int argc, char **argv);
    ~Engine();
    bool init();
    int execute();

private:
    Config mConfig;
    Window* mWindow;
    Event mEvent;
    Graphics mGraphics;
    bool m_quit;
};

#endif // _ENGINE_H
