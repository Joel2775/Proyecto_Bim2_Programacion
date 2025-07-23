#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_boton_registrar_clicked()
{

}


void MainWindow::on_boton_modificar_clicked()
{

}


void MainWindow::on_boton_eliminar_clicked()
{

}


void MainWindow::on_boton_buscar_clicked()
{

}



void MainWindow::on_boton_mostrar_clicked()
{

}

