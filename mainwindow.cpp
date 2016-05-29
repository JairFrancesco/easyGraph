#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkSmartPointer.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Sphere
      vtkSmartPointer<vtkSphereSource> sphereSource =
          vtkSmartPointer<vtkSphereSource>::New();
      sphereSource->Update();
      vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
          vtkSmartPointer<vtkPolyDataMapper>::New();
      sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
      vtkSmartPointer<vtkActor> sphereActor =
          vtkSmartPointer<vtkActor>::New();
      sphereActor->SetMapper(sphereMapper);

      // VTK Renderer
      vtkSmartPointer<vtkRenderer> renderer =
          vtkSmartPointer<vtkRenderer>::New();
      renderer->AddActor(sphereActor);

      // VTK/Qt wedded
      this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

      // Set up action signals and slots
      //connect(this->ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
