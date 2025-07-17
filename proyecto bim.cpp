#include <iostream>
#include <vector>

using namespace std;
struct Usuarios {
    int id;
    string nombre;
    string juego;
    int nivel;
};

vector<Usuarios> listaUsuarios;

void agregar_usuario() {
    Usuarios nuevoUsuario;
    cout << "Ingrese el ID del usuario: ";
    cin >> nuevoUsuario.id;
    for (const auto& usuario : listaUsuarios) {
        if (nuevoUsuario.id == usuario.id) {
            cout << "el usuario ya existe";
            return;
        }
    }
    cin.ignore();
    cout << "Ingrese el nombre del usuario: ";
    getline(cin, nuevoUsuario.nombre);
    cout << "Ingrese el juego del usuario: ";
    getline(cin, nuevoUsuario.juego);
    cout << "Ingrese el nivel del usuario: ";
    cin >> nuevoUsuario.nivel;
    listaUsuarios.push_back(nuevoUsuario);
}

void leer_Usuarios(vector<Usuarios>& listaUsuarios) {
    if (listaUsuarios.empty()) {
        cout << "no hay usuarios registrados";
    }else{
        for (const auto& usuario : listaUsuarios) {
            cout << "### lista de usuarios registrados ###\n";
            cout << usuario.id << ", " << usuario.nombre << ", " <<usuario.juego << ", " << usuario.nivel << endl;
        }
    }
}

int main (){
    while (true) {
        int opcion;
        cout << "\n--- MENU USUARIOS DE VIDEOJUEGOS ---\n";
        cout << "1. Registrar nuevo usuario\n";
        cout << "2. Buscar un usuario\n";
        cout << "3. Actualizar un usuario\n";
        cout << "4. Eliminar un usuario\n";
        cout << "5. Mostrar todos los usuarios\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if (opcion == 1) {
            agregar_usuario();
        }else if (opcion == 2) {
            cout << "falta";
        }else if (opcion == 3) {
            cout << "falta";
        }else if (opcion == 4) {
            cout << "falta";
        }else if (opcion == 5) {
            leer_Usuarios();
        }else if (opcion == 6) {
            cout << "saliendo";
            break;
        }
    }
    return 0;
}
