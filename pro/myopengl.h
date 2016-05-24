#ifndef MYOPENGL_H
#define MYOPENGL_H


#include <QOpenGLWidget>
#include <QDebug>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
class Myopengl : public QOpenGLWidget , protected QOpenGLFunctions
{
    Q_OBJECT
public:
   Myopengl(QWidget *parent) : QOpenGLWidget(parent) { }
    //explicit Myopengl(QWidget *parent = 0);
    QSize sizeHint() const;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
    QMatrix4x4 pMatrix;
    QOpenGLShaderProgram shaderProgram;
    QVector<QVector3D> vertices;

signals:

public slots:
};

#endif // MYOPENGL_H
