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
    nuevoUsuario.nivel = ui->digitar_nivel->text().toDouble();

    return nuevoUsuario;
}

void MainWindow::guardar_usuario() {
    ofstream archivo(ruta);
    if (!archivo) {
        cerr << "Error al abrir el archivo para guardar." << endl;
        return;
    }

    for (const auto& c : listaUsuarios) {
        archivo << c.id << "|" << c.nombre << "|" << c.juego << "|" << c.nivel << "\n";
    }
    ui->mostrar->setText(QString::fromStdString("usuario ingreado correctamente"));
}

void MainWindow::leer_Usuarios() {
    ui->tabla_registros->setRowCount(0); // limpia la tabla

    int fila = 0;

    if (listaUsuarios.empty()) {
        cout << "No hay usuarios registrados.\n";
        return;
    }
    cout << "\n--- Lista de Usuarios ---\n";
    for (const auto& c : listaUsuarios) {

        ui->tabla_registros->insertRow(fila); //insertar una nueva fila

        ui->tabla_registros->setItem(fila, 0, new QTableWidgetItem(QString::number(c.id)));
        ui->tabla_registros->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(c.nombre)));
        ui->tabla_registros->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(c.juego)));
        ui->tabla_registros->setItem(fila, 3, new QTableWidgetItem(QString::number(c.nivel)));

        fila++;
    }
}

void MainWindow::actualizar_usuario(){

    int id;
    id = ui->digitar_id->text().toInt();

    bool encontrado = false;

    for (auto& usuario : listaUsuarios){
        if(usuario.id == id){
            encontrado = true;
            ui->mostrar->setText(QString::fromStdString("Usuario Encontrado"));

            usuario.nombre = ui->digitar_nombre->text().toStdString();

            usuario.juego = ui->digitar_juego->text().toStdString();

            usuario.nivel = ui->digitar_nivel->text().toDouble();

            guardar_usuario();
            break;
        }
    }
    ui->mostrar->setText(QString::fromStdString("Usuario Modificado correctamente"));
    if(!encontrado){
        ui->mostrar->setText(QString::fromStdString("El Usuario no fue encontrado"));
    }
}

void MainWindow::eliminar_usuario()
{
    int id = ui->digitar_id->text().toInt();

    for (size_t i = 0; i < listaUsuarios.size(); ++i) {
        if (listaUsuarios[i].id == id){
            listaUsuarios.erase(listaUsuarios.begin()+i);
            guardar_usuario();
            ui->mostrar->setText("El juagdor ha sido eliminado con exito\n");
            return;
        }
    }
    ui->mostrar->setText("Jugador no encontrado");
}

void MainWindow::buscar_usuario() {
    int idBuscado = ui->digitar_id->text().toInt();
    if (idBuscado == 0) {
        ui->mostrar->setText("Por favor, ingrese un ID válido.");
        return;
    }

    ifstream archivo(ruta);
    if (!archivo) {
        ui->mostrar->setText("No se pudo abrir el archivo usuarios.txt");
        return;
    }

    string linea;
    bool encontrado = false;
    ui->tabla_registros->setRowCount(0);

    while (getline(archivo, linea)) {
        Usuarios c;
        int pos = 0;
        int campo = 0;
        string token;

        while ((pos = linea.find('|')) != string::npos) {
            token = linea.substr(0, pos);
            if (campo == 0) c.id = stoi(token);
            else if (campo == 1) c.nombre = token;
            else if (campo == 2) c.juego = token;
            linea.erase(0, pos + 1);
            campo++;
        }

        c.nivel = stoi(linea);

        if (c.id == idBuscado) {
            int fila = ui->tabla_registros->rowCount();
            ui->tabla_registros->insertRow(fila);
            ui->tabla_registros->setItem(fila, 0, new QTableWidgetItem(QString::number(c.id)));
            ui->tabla_registros->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(c.nombre)));
            ui->tabla_registros->setItem(fila, 2, new QTableWidgetItem(QString::number(c.nivel)));
            ui->tabla_registros->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(c.juego)));


            ui->mostrar->setText("Usuario encontrado");
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        ui->mostrar->setText("Usuario no encontrado");
    }
}


void MainWindow::on_boton_modificar_clicked()
{
    actualizar_usuario();
    leer_Usuarios();
}


void MainWindow::on_boton_eliminar_clicked()
{
    eliminar_usuario();
    leer_Usuarios();
}


void MainWindow::on_boton_buscar_clicked()
{
    buscar_usuario();
}



void MainWindow::on_boton_mostrar_clicked()
{
    leer_Usuarios();
}

