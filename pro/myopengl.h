#ifndef MYOPENGL_H
#define MYOPENGL_H


#include <QOpenGLWidget>
#include <QDebug>
class Myopengl : public QOpenGLWidget
{
    Q_OBJECT
public:
   Myopengl(QWidget *parent) : QOpenGLWidget(parent) { }
    //explicit Myopengl(QWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

signals:

public slots:
};

#endif // MYOPENGL_H
