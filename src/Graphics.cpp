#include "Graphics.h"
#include "Window.h"
#include "LogManager.h"

#include <IL/ilut.h>

Graphics* Graphics::instance = NULL;

Graphics::Graphics()
{
    instance = this;
}

void
Graphics::init()
{
    LogManager::getSingleton()->logMessage("[Graphics] Init");

    /*
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
    */

    initDevIL();
    initGL();
    Vector2 screenSize = Window::getWindowSize();
    resize(screenSize.x, screenSize.y);
}

void
Graphics::initDevIL()
{
    LogManager::getSingleton()->logMessage("Init DevIL");
    ilInit();
    iluInit();
    ilutInit();
    //ilutRenderer( ILUT_OPENGL );

    // set the first loaded point to the upper-left corner
    ilOriginFunc(IL_ORIGIN_UPPER_LEFT);
    ilEnable(IL_ORIGIN_SET);
}

void
Graphics::initGL()
{
    LogManager::getSingleton()->logMessage("Init GL");

    // enable the 2D texturing. will apply textures to shapes on the screen
    glEnable(GL_TEXTURE_2D);

    // Choose a smooth shading model. tells OpenGL if the points of a 
    // primitive (a basic shape, like a triangle or a rectangle) have 
    // different colors, they will be interpolated.
    // Values are : GL_SMOOTH, GL_FLAT
    glShadeModel(GL_SMOOTH);

    glClearColor(0.0, 0.0, 0.0, 0.0);

    // enable the alpha testing. This is needed 
    // if we want to render some parts of a texture transparent.
    glEnable(GL_ALPHA_TEST);

    // we need also to select which function will be used to discard pixels
    // depending on their alpha channel. This is done through the glAlphaFunc:
    // we specify that all pixels with an alpha channel greater (GL_GREATER)
    // than the specified threshold (0) will be discarded (not drawn).
    glAlphaFunc(GL_GREATER, 0.0f);
}

void
Graphics::resize(float _w, float _h)
{
    glViewport(0.0f, 0.0f, _w, _h);

    /*
     * # GL_MODELVIEW: This matrix stack affects the objects in your scene.
     *    In case of our tutorial, these objects will simply be textured rectangles.
     *    By manipulating this matrix stack, you will be able to translate,
     *    rotate and scale the objects in your scene.
     * # GL_PROJECTION: This matrix stack affects how the objects in your scene
     *    will be projected on the viewport. By manipulating this stack, you can
     *    specify which kind of projection should be applied to your objects.
     * # GL_TEXTURE: This matrix stack defines how the textures will be manipulated
     *    before being applied to objects.
     */
    glMatrixMode(GL_PROJECTION);
    // simply resets the current matrix to the identity matrix
    glLoadIdentity();

    glOrtho(0.0f, _w, _h, 0.0f, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void
Graphics::beginFrame()
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    /*

    glBegin(GL_QUADS);
        glColor3f(1, 0, 0); glVertex3i(0, 0, 0);
        glColor3f(1, 1, 0); glVertex3i(100, 0, 0);
        glColor3f(1, 0, 1); glVertex3i(100, 100, 0);
        glColor3f(1, 1, 1); glVertex3i(0, 100, 0);
    glEnd();
    */
}

void
Graphics::endFrame()
{
    Window::swapBuffers();
}


void
Graphics::glEnable2D()
{
    LogManager::getSingleton()->logMessage("glEnable2D");

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
    LogManager::getSingleton()->logMessage("glDisable2D");
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

