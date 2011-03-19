#ifndef _ENGINE_H
#define _ENGINE_H

#include "Config.h"
#include "Window.h"
#include "Event.h"

class Engine
{
public:
    Engine(int argc, char **argv);
    ~Engine();
    bool init();
    int execute();

private:
    Config m_config;
    Window* m_window;
    Event m_event;
    bool m_quit;
};

#endif // _ENGINE_H
