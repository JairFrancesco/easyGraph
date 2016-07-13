#ifndef GPADRE_H
#define GPADRE_H


#include <vtkSmartPointer.h>
#include <vtkStructuredGrid.h>

#include <vtkDataSetMapper.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkStructuredGridOutlineFilter.h>
#include <vtkStructuredGridGeometryFilter.h>

#include <vtkProperty.h>
#include <vtkAxesActor.h>
#include <vtkTransform.h>

#include <iostream>
#include <vector>
class Gpadre
{
public:
    Gpadre();
    vtkSmartPointer<vtkRenderer> renderer =   vtkSmartPointer<vtkRenderer>::New();
protected:
    void next_point(std::vector<double>,vtkSmartPointer<vtkPoints>);

    vtkStructuredGrid *  set_points(vtkPoints *,int,int,int);

    void print_grid(vtkStructuredGrid *);

    //filtros retornan pointers StructuredGrid
    vtkSmartPointer<vtkActor> filtro_puntos(vtkStructuredGrid *);
    vtkSmartPointer<vtkActor> filtro_lineas(vtkStructuredGrid *);

    //retorna actors
    vtkSmartPointer< vtkActor >mapear(vtkSmartPointer< vtkStructuredGrid  >);

    //retorna actor axes
    vtkSmartPointer<vtkAxesActor>  axes();

    //render
    void render(std::vector<vtkSmartPointer<vtkActor> >,bool);


   //Actors
   // vtkSmartPointer<vtkActor> actor =   vtkSmartPointer<vtkActor>::New();
    //

    // Visualize


    vtkSmartPointer<vtkRenderWindow> renderWindow =  vtkSmartPointer<vtkRenderWindow>::New();

    //Render Windows
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =    vtkSmartPointer<vtkRenderWindowInteractor>::New();



};

#endif // GPADRE_H
