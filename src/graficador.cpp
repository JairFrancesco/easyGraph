#include "graficador.h"

Graficador::Graficador()
{
    this->camera->SetPosition(0, 0, 20);
    this->camera->SetFocalPoint(0, 0, 0);


    // Setup render window, renderer, and interactor
    //g->renderer->AddActor(g->actor);
    this->renderer->SetActiveCamera(this->camera);
    this->renderer->SetBackground(0.35,0.35,0.90);

}

void Graficador::crear(std::vector<std::vector<double>> vec, int x, int y){
    vtkSmartPointer<vtkPoints> pointss = vtkSmartPointer<vtkPoints>::New();

    for(auto i:vec){
        std::cout <<i[0]<< " /" <<i[1]<< " /"<<i[2]<<"\n" ;
        //Dos veces para que no explote, esto es por teoria no borrar please ..
        this->next_point(i,pointss);
        this->next_point(i,pointss);
    }


    this->structuredGrid->SetDimensions(2, x, y);
    this->structuredGrid->SetPoints(pointss);


    this->print_grid(this->structuredGrid);
    auto actor = this->mapear(this->structuredGrid);
    actor->GetProperty()->SetInterpolationToFlat();

    // Set the color for edges of the sphere
    actor->GetProperty()->SetColor(0,255,0);
    actor->GetProperty()->SetEdgeColor(1.0, 0.0, 0.0); //(R,G,B)
    actor->GetProperty()->EdgeVisibilityOn();
    this->actores.push_back(actor);

}

void Graficador::add_filtros(){

    vtkSmartPointer<vtkActor> actor1 = this->filtro_lineas(this->structuredGrid);
    this->actores.push_back(actor1);

    vtkSmartPointer<vtkActor> actor2 = this->filtro_puntos(this->structuredGrid);
    this->actores.push_back(actor2);

}
void Graficador::add_axes(){
    vtkSmartPointer<vtkCubeAxesActor> cubeAxesActor =
      vtkSmartPointer<vtkCubeAxesActor>::New();

    cubeAxesActor->SetBounds(-10,10,-10,10,-40,40);
    cubeAxesActor->SetCamera(renderer->GetActiveCamera());
    cubeAxesActor->GetTitleTextProperty(0)->SetColor(1.0, 0.0, 0.0);
    cubeAxesActor->GetLabelTextProperty(0)->SetColor(1.0, 0.0, 0.0);

    cubeAxesActor->GetTitleTextProperty(1)->SetColor(0.0, 1.0, 0.0);
    cubeAxesActor->GetLabelTextProperty(1)->SetColor(0.0, 1.0, 0.0);

    cubeAxesActor->GetTitleTextProperty(2)->SetColor(0.0, 0.0, 1.0);
    cubeAxesActor->GetLabelTextProperty(2)->SetColor(0.0, 0.0, 1.0);

    cubeAxesActor->DrawXGridlinesOn();
    cubeAxesActor->DrawYGridlinesOn();
    cubeAxesActor->DrawZGridlinesOn();
  #if VTK_MAJOR_VERSION == 6
    cubeAxesActor->SetGridLineLocation(VTK_GRID_LINES_FURTHEST);
  #endif
  #if VTK_MAJOR_VERSION > 6
    cubeAxesActor->SetGridLineLocation(2);
  #endif

    cubeAxesActor->XAxisMinorTickVisibilityOff();
    cubeAxesActor->YAxisMinorTickVisibilityOff();
    cubeAxesActor->ZAxisMinorTickVisibilityOff();

    renderer->AddActor(cubeAxesActor);
    renderer->AddActor(this->axes());
}

void Graficador::renderizar(bool mostrar){
    this->render(this->actores,mostrar);
}
