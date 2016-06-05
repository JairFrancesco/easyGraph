#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graficador.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
     Graficador * g = new Graficador;

public slots:
    void color2();
    void resetCamera();
    void colorearfondo();

private:


};

#endif // MAINWINDOW_H
