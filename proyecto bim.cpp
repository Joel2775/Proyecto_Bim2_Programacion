#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Usuarios {
    int id;
    string nombre;
    string juego;
    int nivel;
};

vector<Usuarios> listaUsuarios;
string  ruta = "usuarios.txt";

vector<Usuarios> cargar_usuarios(){
    vector<Usuarios> usuarios;
    ifstream archivo(ruta);
    if(!archivo){
        cerr<<"Archivo no encontrado. Se iniciará una nueva lista.\n";
        return usuarios;
    }
    string linea;
    while(getline(archivo,linea)){
        Usuarios c;
        int pos = 0;
        int campo = 0;
        string token;
        while((pos = linea.find('|')) != string::npos){
            token = linea.substr(0,pos); 
            if(campo == 0){
                c.id = stoi(token);
            }else if (campo == 1){
                c.nombre = token;
            }else if(campo == 2){
                c.juego = token;
            }
            linea.erase(0, pos+1);
            campo++;
        }
        c.nivel = stof(linea);
        usuarios.push_back(c);
    }
    return usuarios;
}

Usuarios agregar_usuario() {
    Usuarios nuevoUsuario;
    cout << "Ingrese el ID del usuario: ";
    cin >> nuevoUsuario.id;
    for (const auto& usuario : listaUsuarios) {
        if (nuevoUsuario.id == usuario.id) {
            cout << "el usuario ya existe";
            return {};
        }
    }
    cin.ignore();
    cout << "Ingrese el nombre del usuario: ";
    getline(cin, nuevoUsuario.nombre);
    cout << "Ingrese el juego del usuario: ";
    getline(cin, nuevoUsuario.juego);
    cout << "Ingrese el nivel del usuario: ";
    cin >> nuevoUsuario.nivel;
    return nuevoUsuario;
}

void guardar_usuario(){
    ofstream archivo(ruta);
    if(!archivo){
        cerr<<"Error al abrir el archivo para guardar.\n";
        return;
    }
    for(const auto& c: listaUsuarios) {
        archivo << c.id<<"|"<<c.nombre<<"|"<<c.juego<<"|"<<c.nivel<<"\n";
    }
}

void buscar_usuario() {
    int id;
    cout << "Ingrese el ID del usuario a buscar: ";
    cin >> id;

    ifstream archivo("usuarios.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo usuarios.txt\n";
        return;
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

        c.nivel = stoi(linea);

        if (c.id == id) {
            cout << "Usuario encontrado:\n";
            cout << "ID: " << c.id << endl;
            cout << "Nombre: " << c.nombre << endl;
            cout << "Juego: " << c.juego << endl;
            cout << "Nivel: " << c.nivel << endl;
            return;
        }
    }

    cout << "Usuario no encontrado\n";
}

void actualizar_usuario(){
	
    if (listaUsuarios.empty()) {
        cout<< "No hay usuarios registrados\n";
        return;
    }
    
	int id;
	cout<<"Ingrese el Id del usuario a Actualizar:";
	cin>> id;
	
	bool encontrado = false;
	
	for (auto& usuario : listaUsuarios){
		if(usuario.id == id){
			encontrado = true;
			cout<<"Usuario Encontrado. Ingrese los nuevo datos:\n";
			cin.ignore();
			
			cout<<"Nuevo Nombre de Usuario: ";
			getline(cin, usuario.nombre);
			
			cout<<"Nuevo Juego del Usuario: ";
			getline(cin, usuario.juego);
			
			cout<<"Nuevo Nivel: ";
			cin>>usuario.nivel;
			
			guardar_usuario();
            cout << "Usuario actualizado exitosamente\n";
            break;
		}
	}	
	if(!encontrado){
		cout<<"El Usuario no fue encontrado\n";
	}
}

void eliminar_usuario() {
    int id;
    cout << "Digite el ID del jugador a eliminar: ";
    cin >> id;

    for (size_t i = 0; i < listaUsuarios.size(); ++i) {
        if (listaUsuarios[i].id == id) {
            listaUsuarios.erase(listaUsuarios.begin() + i);
	    guardar_usuario();
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
	cout << "### Lista de usuarios registrados ###\n";
        for (const auto& usuario : listaUsuarios) {
            cout << usuario.id << ", " << usuario.nombre << ", " <<usuario.juego << ", " << usuario.nivel << endl;
        }
    }
}

int main (){
    listaUsuarios = cargar_usuarios();
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
            Usuarios nuevoUsuario = agregar_usuario();
            if (nuevoUsuario.id != 0) {
                listaUsuarios.push_back(nuevoUsuario);
                guardar_usuario();
            }
        }else if (opcion == 2) {
            buscar_usuario();
        }else if (opcion == 3) {
            actualizar_usuario();
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
