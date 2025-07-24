#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

std::vector<Usuarios> listaUsuarios;
std::string ruta = "usuarios.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listaUsuarios = cargar_usuarios();
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<Usuarios> MainWindow::cargar_usuarios() {
    vector<Usuarios> usuarios;
    ifstream archivo(ruta);
    if (!archivo) {
        cerr << "Archivo no encontrado. Se iniciará una nueva lista.\n";
        return usuarios;
    }

    string linea;
    while (getline(archivo, linea)) {
        Usuarios c;
        int pos = 0;
        int campo = 0;
        string token;

        while ((pos = linea.find('|')) != string::npos) {
            token = linea.substr(0, pos);
            if (campo == 0) {
                c.id = stoi(token);
            } else if (campo == 1) {
                c.nombre = token;
            } else if (campo == 2) {
                c.juego = token;
            }
            linea.erase(0, pos + 1);
            campo++;
        }
        c.nivel = stof(linea);
        usuarios.push_back(c);
    }
    return usuarios;
}

Usuarios MainWindow::agregar_usuario() {
    Usuarios nuevoUsuario;

    nuevoUsuario.id = ui->digitar_id->text().toInt();
    for (const auto& usuario : listaUsuarios) {
        if (nuevoUsuario.id == usuario.id) {
            ui->mostrar->setText(QString::fromStdString("Ya hay un usuario que esta usando ese ID"));
            return {};
        }
    }

    nuevoUsuario.nombre = ui->digitar_nombre->text().toStdString();
    nuevoUsuario.juego = ui->digitar_juego->text().toStdString();
    nuevoUsuario.nivel = ui->digitar_nivel->text().toInt();

    return nuevoUsuario;
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

