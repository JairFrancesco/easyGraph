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
   ~Graficador();

    std::vector<vtkSmartPointer<vtkActor>> actores;


    void crear(std::vector<std::vector<double>>, int, int, bool lineas_activo = true);
    void add_filtros();
    void add_axes();
    void renderizar(bool mostrar=true);

    vtkSmartPointer<vtkPoints> pointss = vtkSmartPointer<vtkPoints>::New();

    void clean();
vtkSmartPointer<vtkCamera> camera =    vtkSmartPointer<vtkCamera>::New();
vtkSmartPointer<vtkUnsignedCharArray> colors = vtkSmartPointer<vtkUnsignedCharArray>::New();

};

#endif // GRAFICADOR_H
