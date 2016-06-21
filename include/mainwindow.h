#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QString>
#include "graficador.h"
#include "interprete.h"

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

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    interprete * interp = new interprete();
    QStandardItemModel *model = new QStandardItemModel();
    std::vector<std::vector<double>>coordenadas;

};

#endif // MAINWINDOW_H
