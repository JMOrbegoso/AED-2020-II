#include <iostream>
#include "Funciones.h"

using namespace std;

#pragma region Declaraciones adelantadas

void menuEmpleadoDeVentas(deltronXpand& deltronXpand, string dniDelEmpleadoDeVentasLogeado);
void menuCliente(deltronXpand& deltronXpand, string rucDelClienteLogeado);
void menuLoginEmpleadoDeVentas(deltronXpand& deltronXpand);
void menuLoginCliente(deltronXpand& deltronXpand);

#pragma endregion

#pragma region Funciones del Menú

void menuPrincipal(deltronXpand& deltronXpand) {
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

                if (empleadoDeVentasDNI != ""){
                    menuEmpleadoDeVentas(deltronXpand, empleadoDeVentasDNI);
                }
                else {
                    cout << endl;
                    esperarMostrandoTexto("Intente nuevamente o registrese");
                }

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

                if (clienteRUC != "") {
                    menuCliente(deltronXpand, clienteRUC);
                }
                else {
                    cout << endl;
                    esperarMostrandoTexto("Intente nuevamente o registrese");
                }
                
                break;

            default:
                break;
            }
        }

    } while (!(opcionSeleccionadaDelMenuLogin == 0));

    esperarMostrandoTexto("Volviendo");
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

    esperarMostrandoTexto("Cerrando Sesión");
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
                verHistorialDeOrdenes(deltronXpand, rucDelClienteLogeado);
                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(opcionSeleccionada == 0));

    esperarMostrandoTexto("Cerrando Sesión");
}

#pragma endregion