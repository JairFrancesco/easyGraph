#include "gpadre.h"

Gpadre::Gpadre()
{

}


void Gpadre::next_point(std::vector<double> vec,vtkSmartPointer<vtkPoints> pointss){
    pointss->InsertNextPoint(vec[0],vec[1],vec[2]);
}

vtkStructuredGrid * Gpadre::set_points(vtkPoints * points, int numi , int numj , int numk){
    // Create a grid
   vtkSmartPointer<vtkStructuredGrid> structuredGrid =  vtkSmartPointer<vtkStructuredGrid>::New();
   structuredGrid->SetDimensions(numi, numj, numk);
   structuredGrid->SetPoints(points);
   return structuredGrid;
}

void Gpadre::print_grid(vtkStructuredGrid * structuredGrid){
    std::cout << "There are " << structuredGrid->GetNumberOfPoints() << " points." << std::endl; // there should be 2*3*2 = 12 points
    std::cout << "There are " << structuredGrid->GetNumberOfCells() << " cells." << std::endl; // The 12 points define the corners of 2 cubes/cells (4 points are shared by both cubes)

}

vtkSmartPointer<vtkActor> Gpadre::filtro_puntos(vtkStructuredGrid * structuredGrid){

    vtkSmartPointer<vtkStructuredGridGeometryFilter> geometryFilter =   vtkSmartPointer<vtkStructuredGridGeometryFilter>::New();

    geometryFilter->SetInputData(structuredGrid);
    geometryFilter->Update();


   vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
   mapper->SetInputConnection(geometryFilter->GetOutputPort());

   vtkSmartPointer<vtkActor> actor =   vtkSmartPointer<vtkActor>::New();
   actor->SetMapper(mapper);
   actor->GetProperty()->SetPointSize(3);
   return actor;


}

vtkSmartPointer<vtkActor> Gpadre::filtro_lineas(vtkStructuredGrid * structuredGrid){
    //Filtros
    vtkSmartPointer<vtkStructuredGridOutlineFilter> outlineFilter =   vtkSmartPointer<vtkStructuredGridOutlineFilter>::New();

    outlineFilter->SetInputData(structuredGrid);
    outlineFilter->Update();

    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(outlineFilter->GetOutputPort());

    vtkSmartPointer<vtkActor> actor =   vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);


    return actor;
}

vtkSmartPointer<vtkActor> Gpadre::mapear(vtkSmartPointer<vtkStructuredGrid> grid){

    vtkSmartPointer < vtkDataSetMapper> mapper =   vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputData(grid);

    vtkSmartPointer<vtkActor> actor =   vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    return actor;
}



void Gpadre::render(std::vector<vtkSmartPointer<vtkActor> > actors,bool mostrar){

    this->renderer->SetBackground(.2, .3, .4);

    if (mostrar){
        for(auto actor: actors){
           this-> renderer->AddActor(actor);
         }
    }
    else{
        for(unsigned int i=1;i<actors.size();++i){
            this->renderer->AddActor(actors[i]);
        }
    }



}

vtkSmartPointer<vtkAxesActor> Gpadre::axes(){
      vtkSmartPointer<vtkAxesActor> axes = vtkSmartPointer<vtkAxesActor>::New();
      //Axes
      vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
      transform->Translate(0.0, 0.0, 0.0);

      axes->SetUserTransform(transform);
      axes->SetTotalLength(5,5,5);
      return axes;
}



