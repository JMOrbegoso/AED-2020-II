#include <iostream>
#include "Basicas.h"
#include "BasicasDeEstructuras.h"

using namespace std;

int main()
{
    // Declaración de variables y estructuras de datos

    empleadoDeVentas empleadosDeVentas[100];
    int empleadosDeVentasCantidad = 0;

    cliente clientes[100];
    int clientesCantidad = 0;

    almacen almacenes[5];

    tipoDeUso tiposDeUso[5];
    clasificacion clasificaciones[5];
    subclasificacion subclasificaciones[5];

    producto productos[100];
    int productosCantidad = 0;

    productoEnAlmacen productosEnAlmacen[100];
    int productosEnAlmacenCantidad = 0;

    ordenDeCompra ordenesDeCompra[100];
    int ordenesDeCompraCantidad = 0;

    productoComprado productosComprados[100];
    int productosCompradosCantidad = 0;

    // Inicializacion
    inicializarEmpleadosDeVentas(empleadosDeVentas, empleadosDeVentasCantidad);
    inicializarClientes(clientes, clientesCantidad);
    inicializarAlmacenes(almacenes);
    inicializarTiposDeUso(tiposDeUso);
    inicializarClasificaciones(clasificaciones);
    inicializarSubclasificaciones(subclasificaciones);
    inicializarProductos(productos, productosCantidad);
    inicializarProductosEnAlmacen(productosEnAlmacen, productosEnAlmacenCantidad);
    inicializarOrdenesDeCompra(ordenesDeCompra, ordenesDeCompraCantidad);
    inicializarProductosComprados(productosComprados, productosCompradosCantidad);

    // Menú
    menuPrincipal();

    return 0;
}