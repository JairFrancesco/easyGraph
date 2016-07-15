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

    vtkSmartPointer<vtkStructuredGrid> structuredGrid =  vtkSmartPointer<vtkStructuredGrid>::New();
    vtkStructuredGrid *  set_points(vtkPoints *,int,int,int);
    void print_grid();

    //filtros retornan pointers StructuredGrid
    vtkSmartPointer<vtkActor> filtro_puntos();
    vtkSmartPointer<vtkActor> filtro_lineas();

    //retorna actors
    vtkSmartPointer < vtkDataSetMapper> mapper =   vtkSmartPointer<vtkDataSetMapper>::New();
    vtkSmartPointer< vtkActor >mapear();

    //retorna actor axes
    vtkSmartPointer<vtkAxesActor>  axes();

    //render
    void render(std::vector<vtkSmartPointer<vtkActor> >,bool);


   //Actors
   // vtkSmartPointer<vtkActor> actor =   vtkSmartPointer<vtkActor>::New();
    //
    vtkSmartPointer<vtkAxesActor> axess = vtkSmartPointer<vtkAxesActor>::New();

    // Visualize


    vtkSmartPointer<vtkRenderWindow> renderWindow =  vtkSmartPointer<vtkRenderWindow>::New();

    //Render Windows
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =    vtkSmartPointer<vtkRenderWindowInteractor>::New();



};

#endif // GPADRE_H
