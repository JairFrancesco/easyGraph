#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include "gpadre.h"
#include <vtkCamera.h>
#include <vtkCubeAxesActor.h>
#include <vtkTextProperty.h>
class Graficador : public Gpadre
{


public:
    Graficador();

    std::vector<vtkSmartPointer<vtkActor>> actores;
    vtkSmartPointer<vtkStructuredGrid> structuredGrid =  vtkSmartPointer<vtkStructuredGrid>::New();

    void crear(std::vector<std::vector<double>>,int,int);
    void add_filtros();
    void add_axes();
    void renderizar(bool mostrar=true);

void clean();
vtkSmartPointer<vtkCamera> camera =    vtkSmartPointer<vtkCamera>::New();
vtkSmartPointer<vtkUnsignedCharArray> colors = vtkSmartPointer<vtkUnsignedCharArray>::New();

};

#endif // GRAFICADOR_H
