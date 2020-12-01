#include "Estructuras.h"

void inicializarEmpleadosDeVentas(deltronXpand& deltronXpand) {

    deltronXpand.empleadosDeVentas[0].apellido = "Descalzi Tenorio";
    deltronXpand.empleadosDeVentas[0].nombre = "Yessica Rub�";
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

    deltronXpand.almacenes[0].id = 1;
    deltronXpand.almacenes[0].departamento = "Lima";
    deltronXpand.almacenes[0].direccion = "Av. Los Heroes 777";

    deltronXpand.almacenes[1].id = 2;
    deltronXpand.almacenes[1].departamento = "Trujillo";
    deltronXpand.almacenes[1].direccion = "Av. Los Girasoles 777";

    deltronXpand.almacenes[2].id = 3;
    deltronXpand.almacenes[2].departamento = "Chiclayo";
    deltronXpand.almacenes[2].direccion = "Av. Los Conquistadores 777";

    deltronXpand.almacenes[3].id = 4;
    deltronXpand.almacenes[3].departamento = "Arequipa";
    deltronXpand.almacenes[3].direccion = "Av. Los Naranjos 777";

    deltronXpand.almacenes[4].id = 5;
    deltronXpand.almacenes[4].departamento = "Cuzco";
    deltronXpand.almacenes[4].direccion = "Av. Los Robles 777";

    deltronXpand.almacenesCantidad = 5;
}

void inicializarTiposDeUso(deltronXpand& deltronXpand) {

    deltronXpand.tiposDeUso[0].id = 1;
    deltronXpand.tiposDeUso[0].tipo = "Producto Final";

    deltronXpand.tiposDeUso[1].id = 2;
    deltronXpand.tiposDeUso[1].tipo = "Componente";

    deltronXpand.tiposDeUso[2].id = 3;
    deltronXpand.tiposDeUso[2].tipo = "Suministro";

    deltronXpand.tiposDeUso[3].id = 4;
    deltronXpand.tiposDeUso[3].tipo = "Repuesto";

    deltronXpand.tiposDeUso[4].id = 5;
    deltronXpand.tiposDeUso[4].tipo = "Servicio";

    deltronXpand.tiposDeUsoCantidad = 5;
}

void inicializarClasificaciones(deltronXpand& deltronXpand) {

    deltronXpand.clasificaciones[0].id = 1;
    deltronXpand.clasificaciones[0].nombre = "Cases";

    deltronXpand.clasificaciones[1].id = 2;
    deltronXpand.clasificaciones[1].nombre = "Computadoras Desktop";

    deltronXpand.clasificaciones[2].id = 3;
    deltronXpand.clasificaciones[2].nombre = "Discos Duros";

    deltronXpand.clasificaciones[3].id = 4;
    deltronXpand.clasificaciones[3].nombre = "CPU (Microprocesadores)";

    deltronXpand.clasificaciones[4].id = 5;
    deltronXpand.clasificaciones[4].nombre = "GPU (Tarjetas de video)";

    deltronXpand.clasificacionesCantidad = 5;
}

void inicializarProductos(deltronXpand& deltronXpand) {

    deltronXpand.productos[0].id = 1;
    deltronXpand.productos[0].marca = "AMD";
    deltronXpand.productos[0].nombre = "Ryzen 3 3100";
    deltronXpand.productos[0].precio = 150;
    deltronXpand.productos[0].clasificacionId = 4;
    deltronXpand.productos[0].tipoDeUsoId = 2;

    deltronXpand.productos[1].id = 2;
    deltronXpand.productos[1].marca = "AMD";
    deltronXpand.productos[1].nombre = "Ryzen 5 3600";
    deltronXpand.productos[1].precio = 210;
    deltronXpand.productos[1].clasificacionId = 4;
    deltronXpand.productos[1].tipoDeUsoId = 2;

    deltronXpand.productos[2].id = 3;
    deltronXpand.productos[2].marca = "AMD";
    deltronXpand.productos[2].nombre = "Ryzen 7 3700X";
    deltronXpand.productos[2].precio = 320;
    deltronXpand.productos[2].clasificacionId = 4;
    deltronXpand.productos[2].tipoDeUsoId = 2;

    deltronXpand.productosCantidad = 10;
}

void inicializarProductosEnAlmacen(deltronXpand& deltronXpand) {

    deltronXpand.productosEnAlmacen[0].id = 1;
    deltronXpand.productosEnAlmacen[0].almacenId = 1;
    deltronXpand.productosEnAlmacen[0].productoId = 1;
    deltronXpand.productosEnAlmacen[0].stock = 10;

    deltronXpand.productosEnAlmacen[1].id = 2;
    deltronXpand.productosEnAlmacen[1].almacenId = 1;
    deltronXpand.productosEnAlmacen[1].productoId = 3;
    deltronXpand.productosEnAlmacen[1].stock = 15;

    deltronXpand.productosEnAlmacen[2].id = 3;
    deltronXpand.productosEnAlmacen[2].almacenId = 1;
    deltronXpand.productosEnAlmacen[2].productoId = 2;
    deltronXpand.productosEnAlmacen[2].stock = 20;

    deltronXpand.productosEnAlmacenCantidad = 3;
}

void inicializarOrdenesDeCompra(deltronXpand& deltronXpand) {

    deltronXpand.ordenesDeCompra[0].id = 1;
    deltronXpand.ordenesDeCompra[0].clienteRUC = "11111111111";

    deltronXpand.ordenesDeCompraCantidad = 3;
}

void inicializarProductosComprados(deltronXpand& deltronXpand) {

    deltronXpand.productosComprados[0].id = 1;
    deltronXpand.productosComprados[0].productoEnAlmacenId = 1;
    deltronXpand.productosComprados[0].ordenDeCompraId = 1;
    deltronXpand.productosComprados[0].cantidad = 1;
    deltronXpand.productosComprados[0].precio = 300;

    deltronXpand.productosCompradosCantidad = 3;
}

string loginPersonalDeVentas(deltronXpand deltronXpand) {
    // Pide DNI (8 caracteres)
    // Pide la clave (minimo 6 caracteres)
    // Buscar que el DNI sea exactamente igual al de un empleado de ventas existente
    //
    //      No encontro el DNI (El empleado de ventas no existe):
    //      Muestra texto diciendo que el empleado de ventas ingresado no existe
    //      Retorna ""
    //
    //      Si encontr� el DNI (El empleado de ventas s� existe):
    //      Verfica con un "if" si la clave ingresada es la misma del empleado de ventas guardado
    //
    //          Si es la misma clave:
    //          Muestra texto diciendo bienvenid@ *nombre del empleado de ventas*
    //          Retorna el DNI del empleado de ventas
    //
    //          No es la misma clave
    //          Muestra texto diciendo que la clave es incorrecta
    //          Retorna ""
    return "44444444";
}

string loginCliente(deltronXpand deltronXpand) {
    // Pide RUC (11 caracteres)
    // Pide la clave (minimo 6 caracteres)
    // Buscar que el RUC sea exactamente igual al de un cliente existente
    //
    //      No encontro el RUC (El cliente no existe):
    //      Muestra texto diciendo que el client ingresado no existe
    //      Retorna ""
    //
    //      Si encontr� el RUC (El cliente si existe):
    //      Verfica con un "if" si la clave ingresada es la misma del cliente guardado
    //
    //          Si es la misma clave:
    //          Muestra texto diciendo bienvenid@ *nombre del cliente*
    //          Retorna el RUC del cliente
    //
    //          No es la misma clave
    //          Muestra texto diciendo que la clave es incorrecta
    //          Retorna ""
    return "11111111111";
}

void registrarPersonalDeVentas(deltronXpand& deltronXpand) {
    // Pide nombres
    // Pide apellidos
    // Pide DNI (8 caracteres)
    // Pide la clave (minimo 6 caracteres)
    // Verifica con un "for" si el DNI del nuevo empleadoDeVentas ya est� en uso por otro empleadoDeVentas ya registrado
    //
    //      Si ya existe alguno registrado muestra un texto diciendo que el DNI usado ya est� en uso
    //
    //      Si no encontr� el DNI, a�ade el empleado de ventas al arreglo de empleados de ventas
    //      Le muestra un mensaje diciendo que fue registrado exitosamente y ya puede iniciar sesi�n
}

void registrarCliente(deltronXpand& deltronXpand) {
    // Pide la raz�n social
    // Pide RUC (11 caracteres)
    // Pide la clave (minimo 6 caracteres)
    // Verifica con un "for" si el RUC del nuevo cliente ya est� en uso por otro cliente ya registrado
    //
    //      Si ya existe alguno registrado muestra un texto diciendo que el RUC usado ya est� en uso
    //
    //      Si no encontr� el RUC, a�ade el cliente al arreglo de clientes
    //      Le muestra un mensaje diciendo que fue registrado exitosamente y ya puede iniciar sesi�n
}

void mostrarOrdenes(ordenDeCompra* ordenesDeCompra, int ordenesDeCompraCantidad, productoComprado* productosComprado, int productosCompradoCantidad) {

}

void revisarAlmacenes(almacen* almacenes, int almacenesCantidad, productoEnAlmacen* productosEnAlmacen, int productosEnAlmacenCantidad) {

}

void registrarProducto(producto* productos, int& productosCantidad, productoEnAlmacen* productosEnAlmacen, int& productosEnAlmacenCantidad) {

}

void editarProducto(producto* productos, int& productosCantidad) {

}

void editarProductoEnAlmacen(productoEnAlmacen* productosEnAlmacen, int& productosEnAlmacenCantidad) {

}

/// <summary>
/// Muestra todos los productos disponibles en stock
/// </summary>
void revisarCatalogo(producto* productos, int productosCantidad, productoEnAlmacen* productosEnAlmacen, int productosEnAlmacenCantidad) {

}

void buscarProductoPorNombre(producto* productos, int productosCantidad, productoEnAlmacen* productosEnAlmacen, int productosEnAlmacenCantidad) {

}

void buscarProductoPorMarca(producto* productos, int productosCantidad, productoEnAlmacen* productosEnAlmacen, int productosEnAlmacenCantidad) {

}

void buscarProductoPorClasificacion(producto* productos, int productosCantidad, productoEnAlmacen* productosEnAlmacen, int productosEnAlmacenCantidad) {

}

void crearOrdenDeCompra(int clienteId, int almacenId, productoEnAlmacen* productosEnAlmacen, int productosEnAlmacenCantidad, ordenDeCompra* ordenesDeCompra, int ordenesDeCompraCantidad, productoComprado* productosComprado, int productosCompradoCantidad) {

}

void verHistorialDeOrdenes(int clienteId, ordenDeCompra* ordenesDeCompra, int ordenesDeCompraCantidad, productoComprado* productosComprado, int productosCompradoCantidad) {

}

