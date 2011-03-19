#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <GL/gl.h>

#include "Vector2.h"
#include "Window.h"

class Graphics
{
public:
    Graphics();
    void init();
    void beginFrame();
    void endFrame();

private:
    static Graphics* instance;

};

#endif // _GRAPHICS_H
