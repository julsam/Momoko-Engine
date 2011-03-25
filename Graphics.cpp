#include "Graphics.h"
#include "Window.h"
#include "LogManager.h"

Graphics* Graphics::instance = NULL;

Graphics::Graphics()
{
    instance = this;
}

void
Graphics::init()
{
    LogManager::getSingleton()->logMessage("[Graphics] Init");

    Vector2 screenSize = Window::getWindowSize();

    glClearColor(0.23f, 0.23f, 0.23f, 0.0f);
    glClearDepth(1.0f);

    glViewport(0.0f, 0.0f, screenSize.x, screenSize.y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0f, screenSize.x, screenSize.y, 0.0f, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_TEXTURE_2D);

    glLoadIdentity();

    glEnable2D();
}

void
Graphics::beginFrame()
{
    Vector2 screenSize = Window::getWindowSize();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0.0f, 0.0f, screenSize.x, screenSize.y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0f, screenSize.x, screenSize.y, 0.0f, 1.0, -1.0);

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


void
Graphics::glEnable2D()
{
    LogManager::getSingleton()->logMessage("[Graphics] glEnable2D");

    GLint viewPort[4];
    glGetIntegerv(GL_VIEWPORT, viewPort);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix(); // maybe useless
    glLoadIdentity();

    glOrtho(0.0f, viewPort[2], viewPort[3], 0.0f, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
}

void
Graphics::glDisable2D()
{
    LogManager::getSingleton()->logMessage("[Graphics] glDisable2D");
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

