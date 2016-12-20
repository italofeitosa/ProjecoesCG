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

void MainWindow::on_X_valueChanged(double arg1)
{
    this->ui->GLwidget->x = arg1;
}

void MainWindow::on_Y_valueChanged(double arg1)
{
    this->ui->GLwidget->y = arg1;
}

void MainWindow::on_Z_valueChanged(double arg1)
{
    this->ui->GLwidget->z = arg1;
}

void MainWindow::on_R_valueChanged(double arg1)
{
    this->ui->GLwidget->R = arg1;
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    this->ui->GLwidget->wired = checked;
}
