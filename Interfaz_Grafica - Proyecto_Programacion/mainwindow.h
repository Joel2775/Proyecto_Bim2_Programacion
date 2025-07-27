#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// Definimos la estructura
struct Usuarios {
    int id;
    std::string nombre;
    std::string juego;
    double nivel;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//ya se define con la creacion de la interface
    void on_boton_registrar_clicked();

    void on_boton_modificar_clicked();

    void on_boton_eliminar_clicked();

    void on_boton_buscar_clicked();

    void on_boton_mostrar_clicked();

private:
    Ui::MainWindow *ui;

//definimos las funciones
    std::vector<Usuarios> cargar_usuarios();
    Usuarios agregar_usuario();
    void guardar_usuario();
    void leer_Usuarios();
    void actualizar_usuario();
    void buscar_usuario();
};
#endif // MAINWINDOW_H
