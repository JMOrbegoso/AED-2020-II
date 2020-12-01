#include <iostream>
#include "Basicas.h"

using namespace std;

// Declaraciones adelantadas
int pedirOpcionDelMenuRol();
void menuLogin(empleadoDeVentas* empleadosDeVentas, int empleadosDeVentasCantidad);
void menuLogin(cliente* clientes, int clientesCantidad);
int pedirOpcionDelMenuLogin(string rol);
int pedirOpcionDelMenuCliente();
void menuCliente(cliente* clientes, int clientesCantidad);
int pedirOpcionDelMenuEmpleadoDeVentas();
void menuEmpleadoDeVentas(empleadoDeVentas* empleadosDeVentas, int empleadosDeVentasCantidad);

int main()
{
    // Declaraci�n de estructuras de datos

    empleadoDeVentas empleadosDeVentas[100];
    int empleadosDeVentasCantidad = 0;

    cliente clientes[100];
    int clientesCantidad = 0;

    almacen almacenes[5];
    int almacenesCantidad = 0;

    tipoDeUso tiposDeUso[5];
    int tiposDeUsoCantidad = 0;

    clasificacion clasificaciones[5];
    int clasificacionesCantidad = 0;

    producto productos[100];
    int productosCantidad = 0;

    productoEnAlmacen productosEnAlmacen[100];
    int productosEnAlmacenCantidad = 0;

    ordenDeCompra ordenesDeCompra[100];
    int ordenesDeCompraCantidad = 0;

    productoComprado productosComprados[100];
    int productosCompradosCantidad = 0;

    // Declaraci�n de variables y estructuras de datos

    int opcionSeleccionadaDelMenuRol;
    bool debeCerrar;

    // Inicializacion
    inicializarEmpleadosDeVentas(empleadosDeVentas, empleadosDeVentasCantidad);
    inicializarClientes(clientes, clientesCantidad);
    inicializarAlmacenes(almacenes, almacenesCantidad);
    inicializarTiposDeUso(tiposDeUso, tiposDeUsoCantidad);
    inicializarClasificaciones(clasificaciones, clasificacionesCantidad);
    inicializarProductos(productos, productosCantidad);
    inicializarProductosEnAlmacen(productosEnAlmacen, productosEnAlmacenCantidad);
    inicializarOrdenesDeCompra(ordenesDeCompra, ordenesDeCompraCantidad);
    inicializarProductosComprados(productosComprados, productosCompradosCantidad);

    // Men�
    do {
        opcionSeleccionadaDelMenuRol = pedirOpcionDelMenuRol();

        if (opcionSeleccionadaDelMenuRol != 0) {
            switch (opcionSeleccionadaDelMenuRol)
            {
            case 1:
                menuLogin(empleadosDeVentas, empleadosDeVentasCantidad);
                debeCerrar = false;
                break;

            case 2:
                menuLogin(clientes, clientesCantidad);
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

void menuLogin(empleadoDeVentas* empleadosDeVentas, int empleadosDeVentasCantidad) {

    int opcionSeleccionadaDelMenuLogin;
    int empleadoDeVentasId;

    do {
        opcionSeleccionadaDelMenuLogin = pedirOpcionDelMenuLogin("Empleado de ventas");

        if (opcionSeleccionadaDelMenuLogin != 0) {
            switch (opcionSeleccionadaDelMenuLogin)
            {
            case 2:
                registrarPersonalDeVentas(empleadosDeVentas, empleadosDeVentasCantidad);

                esperarMostrandoTexto("Ahora ya puede iniciar sesi�n");

            case 1:
                empleadoDeVentasId = loginPersonalDeVentas(empleadosDeVentas, empleadosDeVentasCantidad);

                menuEmpleadoDeVentas(empleadosDeVentas, empleadosDeVentasCantidad);
                break;

            default:
                break;
            }
        }

    } while (!(opcionSeleccionadaDelMenuLogin == 0));

    esperarMostrandoTexto("Volviendo");
}

void menuLogin(cliente* clientes, int clientesCantidad) {

    int opcionSeleccionadaDelMenuLogin;
    int clienteId;

    do {
        opcionSeleccionadaDelMenuLogin = pedirOpcionDelMenuLogin("Cliente");

        if (opcionSeleccionadaDelMenuLogin != 0) {
            switch (opcionSeleccionadaDelMenuLogin)
            {
            case 2:
                registrarCliente(clientes, clientesCantidad);

                esperarMostrandoTexto("Ahora ya puede iniciar sesi�n");

            case 1:
                clienteId = loginCliente(clientes, clientesCantidad);

                menuCliente(clientes, clientesCantidad);
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

void menuCliente(cliente* clientes, int clientesCantidad) {

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

void menuEmpleadoDeVentas(empleadoDeVentas* empleadosDeVentas, int empleadosDeVentasCantidad) {

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