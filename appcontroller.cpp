#include "appcontroller.h"
#include <QApplication>
#include <iostream>
#include <ui_mainwindow.h>

using namespace Controller;

AppController::~AppController()
{
    delete mCounterController;
}

void AppController::createObjects()
{
    mCounterController = new CountController();
    mMainWindowView = new MainWindow();
    mModel = QSharedPointer<CountModel>(new CountModel());
}

int AppController::main(int argc, char *argv[])
{
    AppController app;
    return app.run(argc, argv);
}

int AppController::run(int argc, char *argv[])
{
    QApplication qapp(argc, argv);
    // NB: Parse cli here with QCommandLineParser.
    createObjects();
    connectObjects();
    mMainWindowView->show();

    return qapp.exec();
}

void AppController::connectObjects()
{

    mCounterController->setModel(mModel);
    QObject::connect(mCounterController, SIGNAL(valueChanged(int)),
                     mMainWindowView, SLOT(setValueLabel(int)));

    mMainWindowView->ui->label->setText("sdasd");


    QObject::connect(mMainWindowView->ui->btnStart, SIGNAL(clicked(bool)),
                     mCounterController, SLOT(onStart()));
    QObject::connect(mMainWindowView->ui->btnStop, SIGNAL(clicked(bool)),
                     mCounterController, SLOT(onStop()));

}
