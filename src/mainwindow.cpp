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

    this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(g->renderer);
    this->ui->qvtkWidget->GetRenderWindow()->Render();
    //this->refresh();

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
    //cout << "clickedreset" << endl;
    g->camera->SetPosition(0, 0, 20);
    g->camera->SetFocalPoint(0, 0, 0);
    g->camera->SetViewUp(0,1,0);

     this->ui->qvtkWidget->GetRenderWindow()->Render();
}


void MainWindow::llenarTabla(){

    int counterRow = 0;
    int counterCol = 0;
    for (auto it : coordenadas){
        for (auto ite : it){
            //string temp = stringify(ite);
            //QString qstr = QString::fromStdString(temp);
            this->model->setItem(counterRow, counterCol, new QStandardItem(QString::number(ite)));
            counterCol++;
        }

        counterCol=0;
        counterRow++;

    }
    this->ui->tableView->setModel(this->model);
}

void MainWindow::graficar(){
    //Graficar
    g->crear(coordenadas,21,21);
    //g->crear(coordenadas,21,1); // Esto es para 2d ... ideas papus ?
    g->add_filtros();
    g->add_axes();


    g->renderizar();
    this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(g->renderer);
    this->ui->qvtkWidget->GetRenderWindow()->Render();

}

void MainWindow::on_btnCalcular_clicked()
{

    //string ecuacion = "((x+2*y)/sin(y)-12)";
    this->ui->lblEquation->setText(this->ui->lineEdit->text());
    string ecuacion = this->ui->lineEdit->text().toUtf8().constData();
    std::cout << ecuacion << std::endl;


    this->interp -> set_ecuacion(ecuacion);
    this->interp -> crear_arbol();
    this->interp->set_diferencial(1); // por defecto el diferencial es 1
    //por defecto los limites van de -10 a 10, por lo que podrias omitir las proximas 4 lineas

    interp->set_limite_izq_var1(-10);
    interp->set_limite_der_var1(10);
    interp->set_limite_izq_var2(-10);
    interp->set_limite_der_var2(10);




    //Obtener Cordeenadas
    coordenadas = interp->get_coordenadas();

    //Llenar Tabla
    this->llenarTabla();

    //graficar
    this->graficar();

    //std::thread t1(MainWindow::llenarTabla,this);
    //std::thread t2(MainWindow::graficar,this);
    //Join the thread with the main thread
    //t1.join();
    //t2.join();

    cout << *interp->cont_x << "/" << *interp->cont_y <<  endl;
}


