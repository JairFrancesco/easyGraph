#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    g->add_axes();


    g->renderizar();
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

    g->renderer->SetActiveCamera(g->camera);

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

void MainWindow::graficar(int x,int y ){
    //Graficar
    cout << "here " << x << "," << y<< endl;
    //g->crear(coordenadas,21,1); // Esto es para 2d ... ideas papus ?

    if(this->ui->boxFiltros->isChecked()){
        g->crear(coordenadas,x,y,true);
        g->add_filtros();

    }
    else{
        g->crear(coordenadas,x,y,false);
    }

    g->add_axes();


    g->renderizar();
    auto lista = this->ui->qvtkWidget->GetRenderWindow()->GetRenderers();
    auto i = lista->GetFirstRenderer();

    while (i != NULL) {
        this->ui->qvtkWidget->GetRenderWindow()->RemoveRenderer(i);
        i = lista->GetFirstRenderer();
    }

    this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(g->renderer);

    this->ui->qvtkWidget->GetRenderWindow()->Render();

}

void MainWindow::on_btnCalcular_clicked()
{
    delete this->g;
    this->g = new Graficador();
    this->g->renderer = vtkSmartPointer<vtkRenderer>::New();
    this->resetCamera();


    //string ecuacion = "((x+2*y)/sin(y)-12)";
    this->ui->lblEquation->setText(this->ui->lineEdit->text());
    string ecuacion = this->ui->lineEdit->text().toUtf8().constData();
    std::cout << ecuacion << std::endl;


    interp -> set_ecuacion(ecuacion);
    interp -> crear_arbol();
    interp->set_diferencial(this->ui->spinDiferencial->value()); // por defecto el diferencial es 1
    //por defecto los limites van de -10 a 10, por lo que podrias omitir las proximas 4 lineas

    cout<<"settings limits.."<<endl;
    interp->set_limite_izq_var1(this->ui->spinLimx1->value());
    interp->set_limite_der_var1(this->ui->spinLimx2->value());
    interp->set_limite_izq_var2(this->ui->spinLimy1->value());
    interp->set_limite_der_var2(this->ui->spinLimy2->value());

   //Obtener Cordeenadas
    cout<<"Getting coords"<<endl;
    coordenadas = interp->get_coordenadas();

    //Llenar Tabla
    cout<<"filling table"<<endl;
    this->llenarTabla();

    cout<<"Graficando.."<<endl;
    //graficar


    graficar(*interp->cont_x,*interp->cont_y);

    cout << *interp->cont_x << "/" << *interp->cont_y <<  endl;
    coordenadas.clear();

}



void MainWindow::on_actionExample_triggered()
{
    vector<string> examples;
    examples.push_back("sen(x) + cos(y)");
    examples.push_back("x^2+y^2");
    examples.push_back("sqrt(x^2+y^2)");
    examples.push_back("sen(x) + cos(y)");
    examples.push_back("x^2-y^2");
    examples.push_back("(sen(x)*cos(y))-log(x)");
    examples.push_back("x^2-y");
    srand(time(NULL));
    int randNum = rand()%(examples.size());
    QString tmp = QString::fromStdString(examples[randNum]);
    this->ui->lineEdit->setText(tmp);
}
