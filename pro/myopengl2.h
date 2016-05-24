#ifndef MYOPENGL2_H
#define MYOPENGL2_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Myopengl2 : public QOpenGLWidget
{
    Q_OBJECT
public:
    //explicit Myopengl2(QWidget *parent = 0);
    Myopengl2(QWidget *parent) : QOpenGLWidget(parent) { }

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

signals:

public slots:
};

#endif // MYOPENGL2_H
