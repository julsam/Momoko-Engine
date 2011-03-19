#include "Graphics.h"
#include "Window.h"

Graphics::Graphics()
{
}

void
Graphics::init()
{
    //TODO: resize
    Vector2 screenSize = Vector2(640, 480);

    glClearColor(0.23f, 0.23f, 0.23f, 0.0f);
    glClearDepth(1.0f);

    glViewport(0, 0, screenSize.x, screenSize.y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, screenSize.x, screenSize.y, 0, 1, -1);

    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_TEXTURE_2D);

    glLoadIdentity();
}

void
Graphics::beginFrame()
{
    //TODO: resize
    Vector2 screenSize = Vector2(640, 480);
    //std::cout << screenSize.x << std::endl;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, screenSize.x, screenSize.y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, screenSize.x, screenSize.y, 0, 1, -1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
        glColor3f(1, 0, 0); glVertex3f(0, 0, 0);
        glColor3f(1, 1, 0); glVertex3f(100, 0, 0);
        glColor3f(1, 0, 1); glVertex3f(100, 100, 0);
        glColor3f(1, 1, 1); glVertex3f(0, 100, 0);
    glEnd();
}

void
Graphics::endFrame()
{
    Window::swapBuffers();
}

