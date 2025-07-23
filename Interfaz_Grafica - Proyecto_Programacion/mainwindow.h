#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_boton_registrar_clicked();

    void on_boton_modificar_clicked();

    void on_boton_eliminar_clicked();

    void on_boton_buscar_clicked();

    void on_boton_mostrar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
