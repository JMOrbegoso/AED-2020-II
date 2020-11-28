#include "Estructuras.h"

void inicializarEmpleadosDeVentas(empleadoDeVentas* empleadosDeVentas, int& empleadosDeVentasCantidad) {

    empleadosDeVentas[0].apellido = "Descalzi Tenorio";
    empleadosDeVentas[0].nombre = "Yessica Rubí";
    empleadosDeVentas[0].dni = "12569215";
    empleadosDeVentas[0].clave = "123456";

    empleadosDeVentas[1].apellido = "Sanchez Sanchez";
    empleadosDeVentas[1].nombre = "Joselyn";
    empleadosDeVentas[1].dni = "12569215";
    empleadosDeVentas[1].clave = "123456";

    empleadosDeVentas[2].apellido = "Zavala Salazar";
    empleadosDeVentas[2].nombre = "Edward Daniel";
    empleadosDeVentas[2].dni = "12569215";
    empleadosDeVentas[2].clave = "123456";

    empleadosDeVentas[3].apellido = "Orbegoso Rosas";
    empleadosDeVentas[3].nombre = "Juan Manuel";
    empleadosDeVentas[3].dni = "12569215";
    empleadosDeVentas[3].clave = "123456";

    empleadosDeVentasCantidad = 4;
}

void inicializarClientes(cliente* clientes, int& clientesCantidad) {

    clientes[0].razonSocial = "Computadoras S.A.";
    clientes[0].ruc = "11111111111";
    clientes[0].clave = "123456";

    clientes[1].razonSocial = "Laptops S.A.";
    clientes[1].ruc = "22222222222";
    clientes[1].clave = "123456";

    clientes[2].razonSocial = "Hardware E.I.R.L.";
    clientes[2].ruc = "33333333333";
    clientes[2].clave = "123456";

    clientesCantidad = 3;
}

void inicializarAlmacenes(almacen* almacenes) {

    almacenes[0].id = 1;
    almacenes[0].departamento = "Lima";
    almacenes[0].direccion = "Av. Los Heroes 777";

    almacenes[1].id = 2;
    almacenes[1].departamento = "Trujillo";
    almacenes[1].direccion = "Av. Los Girasoles 777";

    almacenes[2].id = 3;
    almacenes[2].departamento = "Chiclayo";
    almacenes[2].direccion = "Av. Los Conquistadores 777";

    almacenes[3].id = 4;
    almacenes[3].departamento = "Arequipa";
    almacenes[3].direccion = "Av. Los Naranjos 777";

    almacenes[4].id = 5;
    almacenes[4].departamento = "Cuzco";
    almacenes[4].direccion = "Av. Los Robles 777";
}

void inicializarTiposDeUso(tipoDeUso* tiposDeUso) {

    tiposDeUso[0].id = 1;
    tiposDeUso[0].tipo = "Producto Final";

    tiposDeUso[1].id = 2;
    tiposDeUso[1].tipo = "Componente";

    tiposDeUso[2].id = 3;
    tiposDeUso[2].tipo = "Suministro";

    tiposDeUso[3].id = 4;
    tiposDeUso[3].tipo = "Repuesto";

    tiposDeUso[4].id = 5;
    tiposDeUso[4].tipo = "Servicio";
}

void inicializarClasificaciones(clasificacion* clasificaciones, int& clasificacionesCantidad) {

    clasificaciones[0].id = 1;
    clasificaciones[0].nombre = "Cases";

    clasificaciones[1].id = 2;
    clasificaciones[1].nombre = "Computadoras Desktop";

    clasificaciones[2].id = 3;
    clasificaciones[2].nombre = "Discos Duros";

    clasificaciones[3].id = 4;
    clasificaciones[3].nombre = "CPU (Microprocesadores)";

    clasificaciones[4].id = 5;
    clasificaciones[4].nombre = "GPU (Tarjetas de video)";

    clasificacionesCantidad = 5;
}

void inicializarProductos(producto* productos, int& productosCantidad) {

    productos[0].id = 1;
    productos[0].marca = "AMD";
    productos[0].nombre = "Ryzen 3 3100";
    productos[0].precio = 150;
    productos[0].clasificacionId = 4;
    productos[0].tipoDeUsoId = 2;

    productos[1].id = 2;
    productos[1].marca = "AMD";
    productos[1].nombre = "Ryzen 5 3600";
    productos[1].precio = 210;
    productos[1].clasificacionId = 4;
    productos[1].tipoDeUsoId = 2;

    productos[2].id = 3;
    productos[2].marca = "AMD";
    productos[2].nombre = "Ryzen 7 3700X";
    productos[2].precio = 320;
    productos[2].clasificacionId = 4;
    productos[2].tipoDeUsoId = 2;

    productosCantidad = 10;
}

void inicializarProductosEnAlmacen(productoEnAlmacen* productosEnAlmacen, int& productosEnAlmacenCantidad) {

    productosEnAlmacen[0].id = 1;
    productosEnAlmacen[0].almacenId = 1;
    productosEnAlmacen[0].productoId = 1;
    productosEnAlmacen[0].stock = 10;

    productosEnAlmacen[1].id = 2;
    productosEnAlmacen[1].almacenId = 1;
    productosEnAlmacen[1].productoId = 3;
    productosEnAlmacen[1].stock = 15;

    productosEnAlmacen[2].id = 3;
    productosEnAlmacen[2].almacenId = 1;
    productosEnAlmacen[2].productoId = 2;
    productosEnAlmacen[2].stock = 20;

    productosEnAlmacenCantidad = 3;
}

void inicializarOrdenesDeCompra(ordenDeCompra* ordenesDeCompra, int& ordenesDeCompraCantidad) {

    ordenesDeCompra[0].id = 1;
    ordenesDeCompra[0].clienteId = 1;

    ordenesDeCompraCantidad = 3;
}

void inicializarProductosComprados(productoComprado* productosComprados, int& productosCompradosCantidad) {

    productosComprados[0].id = 1;
    productosComprados[0].productoEnAlmacenId = 1;
    productosComprados[0].ordenDeCompraId = 1;
    productosComprados[0].cantidad = 1;

    productosCompradosCantidad = 3;
}