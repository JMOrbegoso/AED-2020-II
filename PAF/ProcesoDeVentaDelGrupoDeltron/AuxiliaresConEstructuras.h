#include "Basicas.h"
#include "Estructuras.h"

using namespace std;

#pragma region Funciones Basicas con estructuras

string obtenerNombreCompletoDeEmpleadoDeVentas(deltronXpand deltronXpand, string dni) {
    string nombreCompleto;

    for (int i = 0; i < deltronXpand.empleadosDeVentasCantidad; i++)
    {
        if (deltronXpand.empleadosDeVentas[i].dni == dni) {
            nombreCompleto = deltronXpand.empleadosDeVentas[i].apellido + " " + deltronXpand.empleadosDeVentas[i].nombre;
            return nombreCompleto;
        }
    }

    return "";
}

string obtenerRazonSocialDeCliente(deltronXpand deltronXpand, string ruc) {
    string razonSocial;

    for (int i = 0; i < deltronXpand.clientesCantidad; i++)
    {
        if (deltronXpand.clientes[i].ruc == ruc) {
            razonSocial = deltronXpand.clientes[i].razonSocial;
            return razonSocial;
        }
    }

    return "";
}

#pragma endregion

#pragma region Funciones de Inicializacion

void inicializarEmpleadosDeVentas(deltronXpand& deltronXpand) {

    deltronXpand.empleadosDeVentas[0].apellido = "Descalzi Tenorio";
    deltronXpand.empleadosDeVentas[0].nombre = "Yessica Rubí";
    deltronXpand.empleadosDeVentas[0].dni = "11111111";
    deltronXpand.empleadosDeVentas[0].clave = "123456";

    deltronXpand.empleadosDeVentas[1].apellido = "Sanchez Sanchez";
    deltronXpand.empleadosDeVentas[1].nombre = "Joselyn";
    deltronXpand.empleadosDeVentas[1].dni = "22222222";
    deltronXpand.empleadosDeVentas[1].clave = "123456";

    deltronXpand.empleadosDeVentas[2].apellido = "Zavala Salazar";
    deltronXpand.empleadosDeVentas[2].nombre = "Edward Daniel";
    deltronXpand.empleadosDeVentas[2].dni = "33333333";
    deltronXpand.empleadosDeVentas[2].clave = "123456";

    deltronXpand.empleadosDeVentas[3].apellido = "Orbegoso Rosas";
    deltronXpand.empleadosDeVentas[3].nombre = "Juan Manuel";
    deltronXpand.empleadosDeVentas[3].dni = "44444444";
    deltronXpand.empleadosDeVentas[3].clave = "123456";

    deltronXpand.empleadosDeVentasCantidad = 4;
}

void inicializarClientes(deltronXpand& deltronXpand) {

    deltronXpand.clientes[0].razonSocial = "Computadoras S.A.";
    deltronXpand.clientes[0].ruc = "11111111111";
    deltronXpand.clientes[0].clave = "123456";

    deltronXpand.clientes[1].razonSocial = "Laptops S.A.";
    deltronXpand.clientes[1].ruc = "22222222222";
    deltronXpand.clientes[1].clave = "123456";

    deltronXpand.clientes[2].razonSocial = "Hardware E.I.R.L.";
    deltronXpand.clientes[2].ruc = "33333333333";
    deltronXpand.clientes[2].clave = "123456";

    deltronXpand.clientesCantidad = 3;
}

void inicializarAlmacenes(deltronXpand& deltronXpand) {

    deltronXpand.almacenes[0].almacenId = 1;
    deltronXpand.almacenes[0].departamento = "Lima";
    deltronXpand.almacenes[0].direccion = "Av. Los Heroes 777";

    deltronXpand.almacenes[1].almacenId = 2;
    deltronXpand.almacenes[1].departamento = "Trujillo";
    deltronXpand.almacenes[1].direccion = "Av. Los Girasoles 777";

    deltronXpand.almacenes[2].almacenId = 3;
    deltronXpand.almacenes[2].departamento = "Chiclayo";
    deltronXpand.almacenes[2].direccion = "Av. Los Conquistadores 777";

    deltronXpand.almacenes[3].almacenId = 4;
    deltronXpand.almacenes[3].departamento = "Arequipa";
    deltronXpand.almacenes[3].direccion = "Av. Los Naranjos 777";

    deltronXpand.almacenes[4].almacenId = 5;
    deltronXpand.almacenes[4].departamento = "Cuzco";
    deltronXpand.almacenes[4].direccion = "Av. Los Robles 777";

    deltronXpand.almacenesCantidad = 5;
}

void inicializarTiposDeUso(deltronXpand& deltronXpand) {

    deltronXpand.tiposDeUso[0].tipoDeUsoId = 1;
    deltronXpand.tiposDeUso[0].tipo = "Producto Final";

    deltronXpand.tiposDeUso[1].tipoDeUsoId = 2;
    deltronXpand.tiposDeUso[1].tipo = "Componente";

    deltronXpand.tiposDeUso[2].tipoDeUsoId = 3;
    deltronXpand.tiposDeUso[2].tipo = "Suministro";

    deltronXpand.tiposDeUso[3].tipoDeUsoId = 4;
    deltronXpand.tiposDeUso[3].tipo = "Repuesto";

    deltronXpand.tiposDeUso[4].tipoDeUsoId = 5;
    deltronXpand.tiposDeUso[4].tipo = "Servicio";

    deltronXpand.tiposDeUsoCantidad = 5;
}

void inicializarClasificaciones(deltronXpand& deltronXpand) {

    deltronXpand.clasificaciones[0].clasificacionId = 1;
    deltronXpand.clasificaciones[0].nombre = "Cases";

    deltronXpand.clasificaciones[1].clasificacionId = 2;
    deltronXpand.clasificaciones[1].nombre = "Computadoras Desktop";

    deltronXpand.clasificaciones[2].clasificacionId = 3;
    deltronXpand.clasificaciones[2].nombre = "Discos Duros";

    deltronXpand.clasificaciones[3].clasificacionId = 4;
    deltronXpand.clasificaciones[3].nombre = "CPU (Microprocesadores)";

    deltronXpand.clasificaciones[4].clasificacionId = 5;
    deltronXpand.clasificaciones[4].nombre = "GPU (Tarjetas de video)";

    deltronXpand.clasificacionesCantidad = 5;
}

void inicializarProductos(deltronXpand& deltronXpand) {

    deltronXpand.productos[0].productoId = 1;
    deltronXpand.productos[0].marca = "AMD";
    deltronXpand.productos[0].nombre = "Ryzen 3 3100";
    deltronXpand.productos[0].precio = 150;
    deltronXpand.productos[0].clasificacionId = 4;
    deltronXpand.productos[0].tipoDeUsoId = 2;

    deltronXpand.productos[1].productoId = 2;
    deltronXpand.productos[1].marca = "AMD";
    deltronXpand.productos[1].nombre = "Ryzen 5 3600";
    deltronXpand.productos[1].precio = 210;
    deltronXpand.productos[1].clasificacionId = 4;
    deltronXpand.productos[1].tipoDeUsoId = 2;

    deltronXpand.productos[2].productoId = 3;
    deltronXpand.productos[2].marca = "AMD";
    deltronXpand.productos[2].nombre = "Ryzen 7 3700X";
    deltronXpand.productos[2].precio = 320;
    deltronXpand.productos[2].clasificacionId = 4;
    deltronXpand.productos[2].tipoDeUsoId = 2;

    deltronXpand.productosCantidad = 3;
}

void inicializarProductosEnAlmacen(deltronXpand& deltronXpand) {

    deltronXpand.productosEnAlmacen[0].productoEnAlmacenId = 1;
    deltronXpand.productosEnAlmacen[0].almacenId = 1;
    deltronXpand.productosEnAlmacen[0].productoId = 1;
    deltronXpand.productosEnAlmacen[0].stock = 10;

    deltronXpand.productosEnAlmacen[1].productoEnAlmacenId = 2;
    deltronXpand.productosEnAlmacen[1].almacenId = 1;
    deltronXpand.productosEnAlmacen[1].productoId = 3;
    deltronXpand.productosEnAlmacen[1].stock = 15;

    deltronXpand.productosEnAlmacen[2].productoEnAlmacenId = 3;
    deltronXpand.productosEnAlmacen[2].almacenId = 1;
    deltronXpand.productosEnAlmacen[2].productoId = 2;
    deltronXpand.productosEnAlmacen[2].stock = 20;

    deltronXpand.productosEnAlmacenCantidad = 3;
}

void inicializarOrdenesDeCompra(deltronXpand& deltronXpand) {

    deltronXpand.ordenesDeCompra[0].ordenDeCompraId = 1;
    deltronXpand.ordenesDeCompra[0].clienteRUC = "11111111111";
    deltronXpand.ordenesDeCompra[0].clienteRazonSocial = "Computadoras S.A.";

    deltronXpand.ordenesDeCompraCantidad = 1;
}

void inicializarProductosComprados(deltronXpand& deltronXpand) {

    deltronXpand.productosComprados[0].productoCompradoId = 1;
    deltronXpand.productosComprados[0].productoEnAlmacenId = 1;
    deltronXpand.productosComprados[0].ordenDeCompraId = 1;
    deltronXpand.productosComprados[0].cantidad = 1;
    deltronXpand.productosComprados[0].marca = "AMD";
    deltronXpand.productosComprados[0].nombre = "Ryzen 3 3100";
    deltronXpand.productosComprados[0].precio = 250;

    deltronXpand.productosCompradosCantidad = 1;
}

void inicializacion(deltronXpand& deltronXpand) {
    inicializarEmpleadosDeVentas(deltronXpand);
    inicializarClientes(deltronXpand);
    inicializarAlmacenes(deltronXpand);
    inicializarTiposDeUso(deltronXpand);
    inicializarClasificaciones(deltronXpand);
    inicializarProductos(deltronXpand);
    inicializarProductosEnAlmacen(deltronXpand);
    inicializarOrdenesDeCompra(deltronXpand);
    inicializarProductosComprados(deltronXpand);
}

#pragma endregion