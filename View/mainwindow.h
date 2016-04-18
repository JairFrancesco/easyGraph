#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "countcontroller.h"
#include <QMainWindow>

using namespace Controller;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//private:
    Ui::MainWindow *ui;

private slots:
    void setValueLabel(int);

};

#endif // MAINWINDOW_H
