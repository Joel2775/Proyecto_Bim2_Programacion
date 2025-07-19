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

void buscar_usuario() {
    int id;
    cout << "Ingrese el ID del usuario a buscar: ";
    cin >> id;

    for (const auto& usuario : listaUsuarios) {
        if (usuario.id == id) {
            cout << "Usuario encontrado:\n";
            cout << "ID: " << usuario.id << endl;
            cout << "Nombre: " << usuario.nombre << endl;
            cout << "Juego: " << usuario.juego << endl;
            cout << "Nivel: " << usuario.nivel << endl;
            return;
        }
    }
    cout << "Usuario no encontrado\n";
}

void actualizarUsuario(){
	int id;
	cout<<"Ingrese el Id del usuario a Actualizar:";
	cin>> id;
	
	for (auto& usuario : listaUsuarios){
		if (usuario.id == id){
			cout<<"Ingrese los nuevo datos:\n";
			cin.ignore();		
			cout<<"Nuevo Nombre de Usuario: ";
			getline(cin, usuario.nombre);

			cout<<"Nuevo Juego del Usuario: ";
			getline(cin, usuario.juego);
			
			cout<<"Nuevo Nivel: ";
			cin>>usuario.nivel;
			
            cout << "Usuario actualizado exitosamente\n";
            return;
		}
	}
	cout << "El Usuario no fue encontrado\n";
}

void eliminar_usuario() {
    int id;
    cout << "Digite el ID del jugador a eliminar: ";
    cin >> id;

    for (size_t i = 0; i < listaUsuarios.size(); ++i) {
        if (listaUsuarios[i].id == id) {
            listaUsuarios.erase(listaUsuarios.begin() + i);
            cout << "El juagdor a sido eliminado con exito\n";
            return;
        }
    }
    cout << "Jugador no encontrado.\n";
}

void leer_Usuarios() {
    if (listaUsuarios.empty()) {
        cout << "\n No hay usuarios registrados";
    }else{
        for (const auto& usuario : listaUsuarios) {
            cout << "### Lista de usuarios registrados ###\n";
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
            buscar_usuario();
        }else if (opcion == 3) {
            actualizarUsuario();
        }else if (opcion == 4) {
            eliminar_usuario();
        }else if (opcion == 5) {
            leer_Usuarios();
        }else if (opcion == 6) {
            cout << "saliendo";
            break;
        }
    }
    return 0;
}
