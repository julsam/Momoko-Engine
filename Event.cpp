#include "Event.h"

Event::Event() : m_exit(false)
{

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
    std::cout << (char)sym << "\n";
}

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

