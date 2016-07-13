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
    auto mapa = this->mapear(this->structuredGrid);
    this->actores.push_back(mapa);

}

void Graficador::add_filtros(){

    vtkSmartPointer<vtkActor> actor1 = this->filtro_lineas(this->structuredGrid);
    this->actores.push_back(actor1);

    vtkSmartPointer<vtkActor> actor2 = this->filtro_puntos(this->structuredGrid);
    this->actores.push_back(actor2);

}
void Graficador::add_axes(){

    renderer->AddActor(this->axes());
}

void Graficador::renderizar(bool mostrar){
    this->render(this->actores,mostrar);
}
