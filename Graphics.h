#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "Vector2.h"

class Graphics
{
public:
    Graphics();
    void init();
    void beginFrame();
    void endFrame();
    void glEnable2D();
    void glDisable2D();

private:
    static Graphics* instance;

};

#endif // _GRAPHICS_H
