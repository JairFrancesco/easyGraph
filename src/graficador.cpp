#include "graficador.h"

Graficador::Graficador()
{
    vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
    transform->Translate(0.0, 0.0, 0.0);

    axes->SetUserTransform(transform);
    axes->SetTotalLength(5,5,5);
    renderer->AddActor(axes);


    unsigned char red[3] = { 255, 0, 0 };
    // Create a vtkUnsignedCharArray container and store the colors in it
    colors->SetNumberOfComponents(3);
    colors->InsertNextTupleValue(red);

}

void Graficador::puntos2d(){

    for(double i=0.0; i<5; i+=0.1){
        double origin[3] = {i, cuadrado(i), 0};
        points->InsertNextPoint(origin);
    }
}

void Graficador::insertar_punto(double x ,double y ,double z){
    double origin[3] = {x, y, z};
    this->points->InsertNextPoint(origin);
}

void Graficador::set_polilinea(int n){
       this->polyLine->GetPointIds()->SetNumberOfIds(n);
}

void Graficador::insertar_polilinea(int i){
    //polyLine->GetPointIds()->SetNumberOfIds(numberids);
    this->polyLine->GetPointIds()->SetId(i,i);
}

void Graficador::crearpolilinea(){
    int numberids = 50;
       polyLine->GetPointIds()->SetNumberOfIds(numberids);
      for(unsigned int i = 0; i < numberids; i++)
      {
        polyLine->GetPointIds()->SetId(i,i);
      }
}

double Graficador::cuadrado(double x){
    return x*x;
}

void Graficador::clean(){
    cells = vtkSmartPointer<vtkCellArray>::New();

    // Create a polydata to store everything in
     polyData = vtkSmartPointer<vtkPolyData>::New();
    // polyLine = vtkSmartPointer<vtkPolyLine>::New();
     //mapper =  vtkSmartPointer<vtkPolyDataMapper>::New();


    // Create a vtkPoints object and store the points in it
    points = vtkSmartPointer<vtkPoints>::New();

}
