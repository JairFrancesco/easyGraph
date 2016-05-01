#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "countcontroller.h"
#include "settingsdialog.h"
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

private:
    SettingsDialog *settingDialog;

private slots:
    void setValueLabel(int);

    void on_actionConfiguraciones_triggered();
};

#endif // MAINWINDOW_H
