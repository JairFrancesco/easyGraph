#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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


    g->camera->SetPosition(0, 0, 20);
    g->camera->SetFocalPoint(0, 0, 0);

    // Setup render window, renderer, and interactor
    g->renderer->AddActor(g->actor);
    g->renderer->SetActiveCamera(g->camera);

    this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(g->renderer);
    this->ui->qvtkWidget->GetRenderWindow()->Render();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::color2(){
    g->renderer->SetBackground(255,255,255);
    this->ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::colorearfondo(){
    auto red =this->ui->doubleSpinBox->value();
    auto green =this->ui->doubleSpinBox_2->value();
    auto blue =this->ui->doubleSpinBox_3->value();
    cout << red << " " << green << " " << blue <<" " << endl;
    g->renderer->SetBackground(red,green,blue);
    this->ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::resetCamera(){
    cout << "clickedreset" << endl;
    g->camera->SetPosition(0, 0, 20);
    g->camera->SetFocalPoint(0, 0, 0);
    this->ui->qvtkWidget->GetRenderWindow()->Render();
}
