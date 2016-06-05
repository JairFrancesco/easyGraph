#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <iostream>
#include <vector>
#include "graficador.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Graficador * g = new Graficador;
    g->puntos2d();
    g->crearpolilinea();


    g->cells->InsertNextCell(g->polyLine);

    // Add the points to the dataset
    g->polyData->SetPoints(g->points);

    // Add the lines to the dataset
    g->polyData->SetLines(g->cells);
    g->polyData->GetCellData()->SetScalars(g->colors);

    // Setup actor and mapper
    g->mapper->SetInputData(g->polyData);
    g->actor->SetMapper(g->mapper);

    // Setup render window, renderer, and interactor
    g->renderer->AddActor(g->actor);
    this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(g->renderer);
    this->ui->qvtkWidget->GetRenderWindow()->Render();

}

MainWindow::~MainWindow()
{
    delete ui;
}
