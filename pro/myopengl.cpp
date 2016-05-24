#include "myopengl.h"
#include <QtWidgets>
#include <QtOpenGL>

QSize Myopengl::sizeHint() const
{
return QSize(640, 480);
}

void Myopengl::initializeGL()
{
    initializeOpenGLFunctions();
    /*
    glClearColor(0,0,0,1);
       glEnable(GL_DEPTH_TEST);

       */
}

void Myopengl::paintGL()
{
      QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
           glColor3f(1.0, 0.0, 0.0);
            glVertex3f(-0.5, -0.5, 0);
            glColor3f(0.0, 1.0, 0.0);
            glVertex3f( 0.5, -0.5, 0);
            glColor3f(0.0, 0.0, 1.0);
            glVertex3f( 0.0,  0.5, 0);
        glEnd();



}

void Myopengl::resizeGL(int width, int height)
{

}
