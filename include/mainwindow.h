#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QString>
#include "graficador.h"
#include "interprete.h"
 #include <thread>
#include <vtkRendererCollection.h>


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
    void on_btnCalcular_clicked();

    void on_actionExample_triggered();

private:
    interprete * interp =  new interprete();
    QStandardItemModel *model = new QStandardItemModel();
    std::vector<std::vector<double>>coordenadas;

    void llenarTabla();
    void graficar(int,int);


};

#endif // MAINWINDOW_H
