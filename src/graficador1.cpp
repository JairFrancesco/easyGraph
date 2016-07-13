#include "graficador1.h"

Graficador1::Graficador1()
{
    vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
    transform->Translate(0.0, 0.0, 0.0);

    unsigned char red[3] = { 255, 255, 255 };
    // Create a vtkUnsignedCharArray container and store the colors in it
    colors->SetNumberOfComponents(3);
    colors->InsertNextTupleValue(red);

}


void Graficador1::clean(){


}
