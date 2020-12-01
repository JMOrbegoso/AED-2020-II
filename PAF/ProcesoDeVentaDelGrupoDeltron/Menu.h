#include <iostream>
#include "Funciones.h"

using namespace std;

// Declaraciones adelantadas
int pedirOpcionDelMenuRol();
void menuLoginEmpleadoDeVentas(deltronXpand& deltronXpand);
void menuLoginCliente(deltronXpand& deltronXpand);
int pedirOpcionDelMenuLogin(string rol);
void menuEmpleadoDeVentas(deltronXpand& deltronXpand, string rucDelClienteLogeado);
int pedirOpcionDelMenuEmpleadoDeVentas(string nombreEmpleadoDeVentas);
void menuCliente(deltronXpand& deltronXpand, string rucDelClienteLogeado);
int pedirOpcionDelMenuCliente(string razonSocialCliente);

void menuPrincipal(deltronXpand deltronXpand) {
    int opcionSeleccionadaDelMenuRol;
    bool debeCerrar;

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
}

int pedirOpcionDelMenuRol() {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "¿Cúal es su rol?" << endl << endl;

    cout << "[1] Soy personal de ventas" << endl;
    cout << "[2] Soy cliente" << endl;
    cout << "[0] Salir" << endl;

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
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

                esperarMostrandoTexto("Ahora ya puede iniciar sesión");

            case 1:
                empleadoDeVentasDNI = loginPersonalDeVentas(deltronXpand);

                menuEmpleadoDeVentas(deltronXpand, empleadoDeVentasDNI);
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

                esperarMostrandoTexto("Ahora ya puede iniciar sesión");

            case 1:
                clienteRUC = loginCliente(deltronXpand);

                menuCliente(deltronXpand, clienteRUC);
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
    cout << "\t\t\tInicio de sesión como " << rol;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;

    cout << endl << "¿Desea iniciar sesión o registrarse?" << endl << endl;

    cout << "[1] Iniciar sesión" << endl;
    cout << "[2] Registrarse" << endl;
    cout << "[0] Volver" << endl;

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

void menuEmpleadoDeVentas(deltronXpand& deltronXpand, string dniDelEmpleadoDeVentasLogeado) {
    int opcionSeleccionada;

    string nombreCompletoDeEmpleadoDeVentas = obtenerNombreCompletoDeEmpleadoDeVentas(deltronXpand, dniDelEmpleadoDeVentasLogeado);

    do {
        opcionSeleccionada = pedirOpcionDelMenuEmpleadoDeVentas(nombreCompletoDeEmpleadoDeVentas);

        if (opcionSeleccionada != 0) {
            switch (opcionSeleccionada)
            {
            case 1:
                mostrarOrdenes(deltronXpand);
                system("pause");
                break;

            case 2:
                revisarAlmacenes(deltronXpand);
                system("pause");
                break;

            case 3:
                registrarProducto(deltronXpand);
                system("pause");
                break;

            case 4:
                editarProducto(deltronXpand);
                system("pause");
                break;

            case 5:
                editarProductoEnAlmacen(deltronXpand);
                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(opcionSeleccionada == 0));

    esperarMostrandoTexto("Volviendo");
}

int pedirOpcionDelMenuEmpleadoDeVentas(string nombreEmpleadoDeVentas) {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tBienvenid@ " << nombreEmpleadoDeVentas;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;

    cout << endl << "¿Que desea hacer hoy?" << endl << endl;

    cout << "[1] Mostrar todas las ordenes" << endl;
    cout << "[2] Revisar Almacenes" << endl;
    cout << "[3] Registrar nuevo producto" << endl;
    cout << "[4] Editar datos de producto existente" << endl;
    cout << "[5] Cambiar stock de producto en almacén" << endl;
    cout << "[0] Cerrar Sesión" << endl;

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 5)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

void menuCliente(deltronXpand& deltronXpand, string rucDelClienteLogeado) {
    int opcionSeleccionada;

    string razonSocialDeCliente = obtenerRazonSocialDeCliente(deltronXpand, rucDelClienteLogeado);

    do {
        opcionSeleccionada = pedirOpcionDelMenuCliente(razonSocialDeCliente);

        if (opcionSeleccionada != 0) {
            switch (opcionSeleccionada)
            {
            case 1:
                revisarCatalogo(deltronXpand);
                system("pause");
                break;

            case 2:
                buscarProductoPorNombre(deltronXpand);
                system("pause");
                break;

            case 3:
                buscarProductoPorMarca(deltronXpand);
                system("pause");
                break;

            case 4:
                crearOrdenDeCompra(deltronXpand);
                system("pause");
                break;

            case 5:
                verHistorialDeOrdenes(deltronXpand);
                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(opcionSeleccionada == 0));

    esperarMostrandoTexto("Volviendo");
}

int pedirOpcionDelMenuCliente(string razonSocialCliente) {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tBienvenid@ " << razonSocialCliente;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;

    cout << endl << "¿Que desea hacer hoy?" << endl << endl;

    cout << "[1] Revisar catalogo de productos" << endl;
    cout << "[2] Buscar producto por nombre" << endl;
    cout << "[3] Buscar producto por marca" << endl;
    cout << "[4] Crear orden de compra" << endl;
    cout << "[5] Ver historial de ordenes realizadas" << endl;
    cout << "[0] Cerrar Sesión" << endl;

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 5)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}