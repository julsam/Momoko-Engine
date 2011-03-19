#include "Event.h"

using namespace std;

Event::Event() : m_exit(false)
{
    for(int i = 0; i < SDLK_LAST; i++)
        m_keyStates[i] = STATE_UP;
}

Event::~Event()
{
}

bool
Event::init()
{
    return true;
}

void
Event::update()
{
    while(SDL_PollEvent(&m_event)) {
        Input::OnEvent(&m_event);
    }
}

void Event::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    m_keyStates[sym] = STATE_DOWN;

    std::cout << (char)sym << std::endl;
}

void
Event::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    m_keyStates[sym] = STATE_UP;
}

void
Event::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
{
    m_mousePosition = Vector2(mX, mY);
    cout << m_mousePosition.x << " " << m_mousePosition.y << endl;

    if(Left && m_buttonStates[0] == STATE_UP)
        m_buttonStates[0] = STATE_DOWN;
    if(Right && m_buttonStates[1] == STATE_UP)
        m_buttonStates[0] = STATE_DOWN;
    if(Middle && m_buttonStates[2] == STATE_UP)
        m_buttonStates[0] = STATE_DOWN;
}

void
Event::OnLButtonDown(int mX, int mY)
{
    m_mousePosition = Vector2(mX, mY);
    m_buttonStates[0] = STATE_DOWN;
}

void
Event::OnLButtonUp(int mX, int mY)
{
    m_mousePosition = Vector2(mX, mY);
    m_buttonStates[0] = STATE_UP;
}

void
Event::OnRButtonDown(int mX, int mY)
{
    m_mousePosition = Vector2(mX, mY);
    m_buttonStates[1] = STATE_DOWN;
}

void
Event::OnRButtonUp(int mX, int mY)
{
    m_mousePosition = Vector2(mX, mY);
    m_buttonStates[1] = STATE_UP;
}

void
Event::OnMButtonDown(int mX, int mY)
{
    m_mousePosition = Vector2(mX, mY);
    m_buttonStates[2] = STATE_DOWN;
}

void
Event::OnMButtonUp(int mX, int mY)
{
    m_mousePosition = Vector2(mX, mY);
    m_buttonStates[2] = STATE_UP;
}

void
Event::OnResize(int _w, int _h)
{
}

// window close call
void
Event::OnExit()
{
    m_exit = true;
}

bool
Event::isExitPressed()
{
    return m_exit;
}

bool
Event::isKeyPressed(int _keysym)
{
    if(m_keyStates[_keysym] == STATE_DOWN)
        return true;
    else
        return false;
}

Vector2 
Event::getMousePosition() const
{
    return m_mousePosition;
}

bool
Event::isMouseButtonPressed(MouseButton _button) const
{
    if(m_buttonStates[_button] == STATE_DOWN)
        return true;
    else
        return false;
}


