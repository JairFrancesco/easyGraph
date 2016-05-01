#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setValueLabel(int value)
{
    QString s("%1");
    //ui->label->setText(s.arg(value));
}


void MainWindow::on_actionConfiguraciones_triggered()
{
    //SettingsDialog settingDialog;
    //settingDialog.setModal(true);
    //settingDialog.exec();
    settingDialog = new SettingsDialog(this);
    settingDialog->show();
}
