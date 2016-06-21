#include "include/mainwindow.h"
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
    //cout << red << " " << green << " " << blue <<" " << endl;
    g->renderer->SetBackground(red,green,blue);
    this->ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::resetCamera(){
    //cout << "clickedreset" << endl;
    g->camera->SetPosition(0, 0, 20);
    g->camera->SetFocalPoint(0, 0, 0);
    g->camera->SetViewUp(0,1,0);
    this->ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_pushButton_2_clicked()
{
    //string ecuacion = "((x+2*y)/sin(y)-12)";
    this->ui->label_4->setText(this->ui->lineEdit->text());
    string ecuacion = this->ui->lineEdit->text().toUtf8().constData();
    std::cout << ecuacion << std::endl;


      this->interp -> set_ecuacion(ecuacion);
       this->interp -> crear_arbol();
      this->interp->set_diferencial(1); // por defecto el diferencial es 1
       //por defecto los limites van de -10 a 10, por lo que podrias omitir las proximas 4 lineas

       //interp->set_limite_izq_var1(-100);
       //interp->set_limite_der_var1(100);
       //interp->set_limite_izq_var2(-100);
       //interp->set_limite_der_var2(100);

}

void MainWindow::on_pushButton_3_clicked()
{
    this->coordenadas =   interp->get_coordenadas();  // el metodo get_coordenadas es obvio

    this->model->setHorizontalHeaderItem(0, new QStandardItem(QString("X")));
    this->model->setHorizontalHeaderItem(1, new QStandardItem(QString("Y")));
    this->model->setHorizontalHeaderItem(2, new QStandardItem(QString("Z")));



   for(int i=0;i<20;++i){
        for(int j=0;j<2;++j){
            cout << this->coordenadas[i][j] << " ";
            this->model->setItem(i,j,new QStandardItem(QString::number(this->coordenadas[i][j])));
        }
        cout << endl;
    }

    this->ui->tableView->setModel(this->model);

}
