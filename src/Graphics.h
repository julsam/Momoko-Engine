#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "Vector2.h"

class Graphics
{
public:
    struct Image
    {
        char *m_filename;
        const int m_width;
        const int m_height;
        GLuint m_texID;
    };

public:
    Graphics();
    void init();
    void initDevIL();
    void initGL();

    static void resize(float _w, float _h);
    void beginFrame();
    void endFrame();
    void glEnable2D();
    void glDisable2D();

private:
    static Graphics* instance;

};

#endif // _GRAPHICS_H
