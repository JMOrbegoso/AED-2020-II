#include <windows.h>

using namespace std;

// Declaraciones adelantadas
int pedirOpcionDelMenuRol();
void login(bool esCliente);
void esperarMostrandoTexto(string mensaje);
int pedirOpcionDelMenuLogin(bool esCliente);
void mostrarAppTitulo();

// Metodos
void menuPrincipal() {

    // Declaración de variables y estructuras de datos
    int opcionSeleccionadaDelMenuRol;
    bool debeCerrar;

    do {
        opcionSeleccionadaDelMenuRol = pedirOpcionDelMenuRol();

        if (opcionSeleccionadaDelMenuRol != 0) {
            switch (opcionSeleccionadaDelMenuRol)
            {
            case 1:
                login(false);
                debeCerrar = false;
                break;

            case 2:
                login(true);
                debeCerrar = false;
                break;

            default:
                debeCerrar = true;
                break;
            }
        }

    } while (!(opcionSeleccionadaDelMenuRol == 0) && !debeCerrar);
}

int pedirOpcionDelMenuRol() {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "¿Cúal es su rol?" << endl << endl;

    cout << "[1] Soy personal de ventas " << endl;
    cout << "[2] Soy cliente" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

/// <summary>
/// 
/// </summary>
/// <param name="esCliente">Si es true: es cliente, si es false es de personal de ventas</param>
void login(bool esCliente) {

    int opcionSeleccionadaDelMenuLogin;

    do {
        opcionSeleccionadaDelMenuLogin = pedirOpcionDelMenuLogin(esCliente);

        if (opcionSeleccionadaDelMenuLogin != 0) {
            switch (opcionSeleccionadaDelMenuLogin)
            {
            case 1:
                cout << endl << "Va a iniciar sesion *INSERT METHOD* " << endl << endl;
                system("pause");
                break;

            case 2:
                cout << endl << "Se va a registrar *INSERT METHOD*" << endl << endl;
                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(opcionSeleccionadaDelMenuLogin == 0));

    esperarMostrandoTexto("Volviendo");
}

/// <summary>
/// 
/// </summary>
/// <param name="esCliente">Si es true: es cliente, si es false es de personal de ventas</param>
int pedirOpcionDelMenuLogin(bool esCliente) {

    int opcionSeleccionada;
    string rol;

    if (esCliente) {
        rol = "Cliente";
    }
    else {
        rol = "Empleado de ventas";
    }

    system("cls");

    mostrarAppTitulo();

    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tInicio de sesión como " << rol;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;

    cout << endl << "¿Desea iniciar sesión o registrarse?" << endl << endl;

    cout << "[1] Iniciar sesión " << endl;
    cout << "[2] Registrarse" << endl;
    cout << "[0] Volver" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

void esperarMostrandoTexto(string mensaje) {

    cout << mensaje << " ";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
}

void mostrarAppTitulo() {

    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl << "\t\t\tSistema del Grupo Deltron S.A." << endl;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
}