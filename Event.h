#ifndef _EVENT_H
#define _EVENT_H

#include "Input.h"
#include <iostream>

class Event : public Input
{
public:
    Event();
    ~Event();
    bool init();
    void update();
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    void OnExit();
    bool isExitPressed();

private:
    bool m_exit;
    SDL_Event m_event;
    int m_keyStates[SDLK_LAST]; // useless rightnow
};

#endif // _EVENT_H
