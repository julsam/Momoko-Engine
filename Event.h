#ifndef _EVENT_H
#define _EVENT_H

#include "Input.h"
#include <iostream>

class Event : public Input
{
public:
    enum
    {
        STATE_UP = 0,
        STATE_DOWN = 1
    };

public:
    Event();
    ~Event();
    bool init();
    void update();
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
    void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
    void OnLButtonDown(int mX, int mY);
    void OnLButtonUp(int mX, int mY);
    void OnRButtonDown(int mX, int mY);
    void OnRButtonUp(int mX, int mY);
    void OnMButtonDown(int mX, int mY);
    void OnMButtonUp(int mX, int mY);
    void OnExit();
    bool isExitPressed();
    bool isKeyPressed(int _keysym);

private:
    bool m_exit;
    SDL_Event m_event;
    int m_keyStates[SDLK_LAST];
    int m_buttonStates[3]; // 0 : left, 1 : right, 2 : middle
};

#endif // _EVENT_H
