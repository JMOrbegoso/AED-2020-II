#include <iostream>
#include "Basicas.h"

using namespace std;

// Declaraciones adelantadas
int pedirOpcionDelMenuRol();
void menuLoginEmpleadoDeVentas(deltronXpand& deltronXpand);
void menuLoginCliente(deltronXpand& deltronXpand);
int pedirOpcionDelMenuLogin(string rol);
int pedirOpcionDelMenuCliente();
void menuCliente(deltronXpand& deltronXpand);
int pedirOpcionDelMenuEmpleadoDeVentas();
void menuEmpleadoDeVentas(deltronXpand& deltronXpand);

int main()
{
    // Declaraci�n de estructuras de datos
    deltronXpand deltronXpand;

    // Declaraci�n de variables
    int opcionSeleccionadaDelMenuRol;
    bool debeCerrar;

    // Inicializacion
    inicializarEmpleadosDeVentas(deltronXpand);
    inicializarClientes(deltronXpand);
    inicializarAlmacenes(deltronXpand);
    inicializarTiposDeUso(deltronXpand);
    inicializarClasificaciones(deltronXpand);
    inicializarProductos(deltronXpand);
    inicializarProductosEnAlmacen(deltronXpand);
    inicializarOrdenesDeCompra(deltronXpand);
    inicializarProductosComprados(deltronXpand);

    // Men�
    do {
        opcionSeleccionadaDelMenuRol = pedirOpcionDelMenuRol();

        if (opcionSeleccionadaDelMenuRol != 0) {
            switch (opcionSeleccionadaDelMenuRol)
            {
            case 1:
                menuLoginEmpleadoDeVentas(deltronXpand);
                debeCerrar = false;
                break;

            case 2:
                menuLoginCliente(deltronXpand);
                debeCerrar = false;
                break;

            default:
                debeCerrar = true;
                break;
            }
        }

    } while (!(opcionSeleccionadaDelMenuRol == 0) && !debeCerrar);

    return 0;
}

int pedirOpcionDelMenuRol() {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "�C�al es su rol?" << endl << endl;

    cout << "[1] Soy personal de ventas" << endl;
    cout << "[2] Soy cliente" << endl;
    cout << "[0] Salir" << endl;

    cout << endl << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

void menuLoginEmpleadoDeVentas(deltronXpand& deltronXpand) {

    int opcionSeleccionadaDelMenuLogin;
    string empleadoDeVentasDNI;

    do {
        opcionSeleccionadaDelMenuLogin = pedirOpcionDelMenuLogin("Empleado de ventas");

        if (opcionSeleccionadaDelMenuLogin != 0) {
            switch (opcionSeleccionadaDelMenuLogin)
            {
            case 2:
                registrarPersonalDeVentas(deltronXpand);

                esperarMostrandoTexto("Ahora ya puede iniciar sesi�n");

            case 1:
                empleadoDeVentasDNI = loginPersonalDeVentas(deltronXpand);

                menuEmpleadoDeVentas(deltronXpand);
                break;

            default:
                break;
            }
        }

    } while (!(opcionSeleccionadaDelMenuLogin == 0));

    esperarMostrandoTexto("Volviendo");
}

void menuLoginCliente(deltronXpand& deltronXpand) {

    int opcionSeleccionadaDelMenuLogin;
    string clienteRUC;

    do {
        opcionSeleccionadaDelMenuLogin = pedirOpcionDelMenuLogin("Cliente");

        if (opcionSeleccionadaDelMenuLogin != 0) {
            switch (opcionSeleccionadaDelMenuLogin)
            {
            case 2:
                registrarCliente(deltronXpand);

                esperarMostrandoTexto("Ahora ya puede iniciar sesi�n");

            case 1:
                clienteRUC = loginCliente(deltronXpand);

                menuCliente(deltronXpand);
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
int pedirOpcionDelMenuLogin(string rol) {

    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tInicio de sesi�n como " << rol;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;

    cout << endl << "�Desea iniciar sesi�n o registrarse?" << endl << endl;

    cout << "[1] Iniciar sesi�n" << endl;
    cout << "[2] Registrarse" << endl;
    cout << "[0] Volver" << endl;

    cout << endl << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

void menuCliente(deltronXpand& deltronXpand) {

    int opcionSeleccionada;
    int clienteId;

    do {
        opcionSeleccionada = pedirOpcionDelMenuCliente();

        if (opcionSeleccionada != 0) {
            switch (opcionSeleccionada)
            {
            case 1:
                cout << "[1] Revisar catalogo de productos" << endl;
                system("pause");
                break;

            case 2:
                cout << "[2] Buscar producto por nombre" << endl;
                system("pause");
                break;

            case 3:
                cout << "[3] Buscar producto por marca" << endl;
                system("pause");
                break;

            case 4:
                cout << "[4] Buscar producto por clasificaci�n" << endl;
                system("pause");
                break;

            case 5:
                cout << "[5] Crear orden de compra" << endl;
                system("pause");
                break;

            case 6:
                cout << "[6] Ver historial de ordenes realizadas" << endl;
                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(opcionSeleccionada == 0));

    esperarMostrandoTexto("Volviendo");
}

int pedirOpcionDelMenuCliente() {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tBienvenid@";
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;

    cout << endl << "�Que desea hacer hoy?" << endl << endl;

    cout << "[1] Revisar catalogo de productos" << endl;
    cout << "[2] Buscar producto por nombre" << endl;
    cout << "[3] Buscar producto por marca" << endl;
    cout << "[4] Buscar producto por clasificaci�n" << endl;
    cout << "[5] Crear orden de compra" << endl;
    cout << "[6] Ver historial de ordenes realizadas" << endl;
    cout << "[0] Cerrar Sesi�n" << endl;

    cout << endl << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 6)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

void menuEmpleadoDeVentas(deltronXpand& deltronXpand) {

    int opcionSeleccionada;
    int empleadoDeVentasId;

    do {
        opcionSeleccionada = pedirOpcionDelMenuEmpleadoDeVentas();

        if (opcionSeleccionada != 0) {
            switch (opcionSeleccionada)
            {
            case 1:
                cout << "[1] Mostrar todas las ordenes" << endl;
                system("pause");
                break;

            case 2:
                cout << "[2] Revisar Almacenes" << endl;
                system("pause");
                break;

            case 3:
                cout << "[3] Registrar nuevo producto" << endl;
                system("pause");
                break;

            case 4:
                cout << "[4] Editar datos de producto existente" << endl;
                system("pause");
                break;

            case 5:
                cout << "[5] Cambiar stock de producto en almac�n" << endl;
                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(opcionSeleccionada == 0));

    esperarMostrandoTexto("Volviendo");
}

int pedirOpcionDelMenuEmpleadoDeVentas() {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tBienvenid@";
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;

    cout << endl << "�Que desea hacer hoy?" << endl << endl;

    cout << "[1] Mostrar todas las ordenes" << endl;
    cout << "[2] Revisar Almacenes" << endl;
    cout << "[3] Registrar nuevo producto" << endl;
    cout << "[4] Editar datos de producto existente" << endl;
    cout << "[5] Cambiar stock de producto en almac�n" << endl;
    cout << "[0] Cerrar Sesi�n" << endl;

    cout << endl << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 5)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}