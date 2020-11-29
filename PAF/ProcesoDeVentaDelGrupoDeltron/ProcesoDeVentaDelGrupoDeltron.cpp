#include <iostream>
#include "Basicas.h"

using namespace std;

// Declaraciones adelantadas
int pedirOpcionDelMenuRol();
void menuLogin(bool esCliente, empleadoDeVentas* empleadosDeVentas, int empleadosDeVentasCantidad, cliente* clientes, int clientesCantidad);
int pedirOpcionDelMenuLogin(bool esCliente);

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
                menuLogin(false, empleadosDeVentas, empleadosDeVentasCantidad, clientes, clientesCantidad);
                debeCerrar = false;
                break;

            case 2:
                menuLogin(true, empleadosDeVentas, empleadosDeVentasCantidad, clientes, clientesCantidad);
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

    cout << "[1] Soy personal de ventas " << endl;
    cout << "[2] Soy cliente" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

/// <summary>
/// 
/// </summary>
/// <param name="esCliente">Si es true: es cliente, si es false es de personal de ventas</param>
void menuLogin(bool esCliente, empleadoDeVentas* empleadosDeVentas, int empleadosDeVentasCantidad, cliente* clientes, int clientesCantidad) {

    int opcionSeleccionadaDelMenuLogin;

    do {
        opcionSeleccionadaDelMenuLogin = pedirOpcionDelMenuLogin(esCliente);

        if (opcionSeleccionadaDelMenuLogin != 0) {
            switch (opcionSeleccionadaDelMenuLogin)
            {
            case 1:

                if (esCliente) {
                    loginCliente(clientes, clientesCantidad);
                }
                else {
                    loginPersonalDeVentas(empleadosDeVentas, empleadosDeVentasCantidad);
                }
                
                system("pause");
                break;

            case 2:
                if (esCliente) {
                    registrarCliente(clientes, clientesCantidad);
                }
                else {
                    registrarPersonalDeVentas(empleadosDeVentas, empleadosDeVentasCantidad);
                }
                
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
    cout << "\t\t\tInicio de sesi�n como " << rol;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;

    cout << endl << "�Desea iniciar sesi�n o registrarse?" << endl << endl;

    cout << "[1] Iniciar sesi�n " << endl;
    cout << "[2] Registrarse" << endl;
    cout << "[0] Volver" << endl;

    cout << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}