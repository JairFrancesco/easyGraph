#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkDoubleArray.h>
#include <vtkPoints.h>
#include <vtkPolyLine.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkAxesActor.h>
#include <iostream>
#include <vector>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      // Create a vtkPoints object and store the points in it
      vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

      for(double i=0.0; i<5; i+=0.1){
          double origin[3] = {0.0, i, i*i};
          points->InsertNextPoint(origin);
      }

      int numberids = 50;
      vtkSmartPointer<vtkPolyLine> polyLine = vtkSmartPointer<vtkPolyLine>::New();
      polyLine->GetPointIds()->SetNumberOfIds(numberids);
      for(unsigned int i = 0; i < numberids; i++)
      {
        polyLine->GetPointIds()->SetId(i,i);
      }

      // Create a cell array to store the lines in and add the lines to it
      vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
      cells->InsertNextCell(polyLine);

      // Create a polydata to store everything in
      vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();

      // Add the points to the dataset
      polyData->SetPoints(points);

      // Add the lines to the dataset
      polyData->SetLines(cells);

      // Create two colors - one for each line
      unsigned char red[3] = { 255, 0, 0 };


        // Create a vtkUnsignedCharArray container and store the colors in it
        vtkSmartPointer<vtkUnsignedCharArray> colors = vtkSmartPointer<vtkUnsignedCharArray>::New();
        colors->SetNumberOfComponents(3);
        colors->InsertNextTupleValue(red);

      polyData->GetCellData()->SetScalars(colors);

      // Setup actor and mapper
      vtkSmartPointer<vtkPolyDataMapper> mapper =  vtkSmartPointer<vtkPolyDataMapper>::New();
      mapper->SetInputData(polyData);


      vtkSmartPointer<vtkActor> actor =
        vtkSmartPointer<vtkActor>::New();
      actor->SetMapper(mapper);

      // Setup render window, renderer, and interactor
      vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();



     renderer->AddActor(actor);
     this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
     this->ui->qvtkWidget->GetRenderWindow()->Render();

}

MainWindow::~MainWindow()
{
    delete ui;
}
