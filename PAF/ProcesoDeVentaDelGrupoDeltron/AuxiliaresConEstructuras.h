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

int pedirAlmacenId(deltronXpand deltronXpand) {
    int opcionSeleccionada;

    cout << endl << "Escoja un almacén:" << endl << endl;

    for (int i = 0; i < deltronXpand.almacenesCantidad; i++)
    {
        cout << "[" << deltronXpand.almacenes[i].almacenId << "] " << deltronXpand.almacenes[i].departamento << " -> " << deltronXpand.almacenes[i].direccion << endl;
    }

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(1 <= opcionSeleccionada && opcionSeleccionada <= deltronXpand.almacenesCantidad)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

int pedirClasificacionId(deltronXpand deltronXpand) {
    int opcionSeleccionada;

    cout << endl << "Escoja una clasificación:" << endl << endl;

    for (int i = 0; i < deltronXpand.clasificacionesCantidad; i++)
    {
        cout << "[" << deltronXpand.clasificaciones[i].clasificacionId << "] " << deltronXpand.clasificaciones[i].nombre << endl;
    }

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(1 <= opcionSeleccionada && opcionSeleccionada <= deltronXpand.clasificacionesCantidad)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

int pedirTipoDeUsoId(deltronXpand deltronXpand) {
    int opcionSeleccionada;

    cout << endl << "Escoja un tipo de uso:" << endl << endl;

    for (int i = 0; i < deltronXpand.tiposDeUsoCantidad; i++)
    {
        cout << "[" << deltronXpand.tiposDeUso[i].tipoDeUsoId << "] " << deltronXpand.tiposDeUso[i].tipo << endl;
    }

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(1 <= opcionSeleccionada && opcionSeleccionada <= deltronXpand.tiposDeUsoCantidad)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

string obtenerNombreDeAlmacen(deltronXpand deltronXpand, int almacenId) {
    for (int i = 0; i < deltronXpand.almacenesCantidad; i++) {
        if (deltronXpand.almacenes[i].almacenId == almacenId) {
            return deltronXpand.almacenes[i].departamento;
        }
    }
    return "Clasifición desconocida";
}

string obtenerNombreDeClasificacion(deltronXpand deltronXpand, int clasificacionId) {
    for (int i = 0; i < deltronXpand.clasificacionesCantidad; i++) {
        if (deltronXpand.clasificaciones[i].clasificacionId == clasificacionId) {
            return deltronXpand.clasificaciones[i].nombre;
        }
    }
    return "Clasifición desconocida";
}

string obtenerNombreDeTipoDeUso(deltronXpand deltronXpand, int tipoDeUsoId) {
    for (int i = 0; i < deltronXpand.tiposDeUsoCantidad; i++) {
        if (deltronXpand.tiposDeUso[i].tipoDeUsoId == tipoDeUsoId) {
            return deltronXpand.tiposDeUso[i].tipo;
        }
    }
    return "Tipo de uso desconocido";
}

/// <param name="y">eje-y</param>
void mostrarCabeceraDeListaDeProductos(int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);

    gotoxy(0, y); cout << "Id" << endl;
    gotoxy(5, y); cout << "Marca" << endl;
    gotoxy(20, y); cout << "Nombre" << endl;
    gotoxy(40, y); cout << "Precio (S/)" << endl;
    gotoxy(60, y); cout << "Clasificación" << endl;
    gotoxy(80, y); cout << "Tipo de Uso" << endl;

    SetConsoleTextAttribute(hConsole, 15);
}

/// <param name="y">eje-y</param>
void mostrarFilaDeListaDeProductos(deltronXpand deltronXpand, int y, producto producto) {

    gotoxy(0, y); cout << producto.productoId << endl;
    gotoxy(5, y); cout << producto.marca << endl;
    gotoxy(20, y); cout << producto.nombre << endl;
    gotoxy(40, y); cout << producto.precio << endl;
    gotoxy(60, y); cout << obtenerNombreDeClasificacion(deltronXpand, producto.clasificacionId) << endl;
    gotoxy(80, y); cout << obtenerNombreDeTipoDeUso(deltronXpand, producto.tipoDeUsoId) << endl;
}

/// <param name="y">eje-y</param>
void mostrarCabeceraDeListaDeProductosEnAlmacen(int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);

    gotoxy(0, y); cout << "Id" << endl;
    gotoxy(5, y); cout << "Marca" << endl;
    gotoxy(20, y); cout << "Nombre" << endl;
    gotoxy(50, y); cout << "Precio (S/)" << endl;
    gotoxy(65, y); cout << "Stock" << endl;
    gotoxy(75, y); cout << "Clasificación" << endl;
    gotoxy(90, y); cout << "Tipo de Uso" << endl;

    SetConsoleTextAttribute(hConsole, 15);
}

/// <param name="y">eje-y</param>
void mostrarFilaDeListaDeProductosEnAlmacen(deltronXpand deltronXpand, int y, productoEnAlmacen productoEnAlmacen, producto producto) {

    gotoxy(0, y); cout << productoEnAlmacen.productoEnAlmacenId << endl;
    gotoxy(5, y); cout << producto.marca << endl;
    gotoxy(20, y); cout << producto.nombre << endl;
    gotoxy(50, y); cout << producto.precio << endl;
    gotoxy(65, y); cout << productoEnAlmacen.stock << endl;
    gotoxy(75, y); cout << obtenerNombreDeClasificacion(deltronXpand, producto.clasificacionId) << endl;
    gotoxy(90, y); cout << obtenerNombreDeTipoDeUso(deltronXpand, producto.tipoDeUsoId) << endl;
}

/// <param name="y">eje-y</param>
void mostrarCabeceraDeListaDeProductosDisponibles(int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);

    gotoxy(0, y); cout << "Id" << endl;
    gotoxy(5, y); cout << "Marca" << endl;
    gotoxy(20, y); cout << "Nombre" << endl;
    gotoxy(50, y); cout << "Precio (S/)" << endl;
    gotoxy(65, y); cout << "Stock" << endl;
    gotoxy(75, y); cout << "Clasificación" << endl;
    gotoxy(90, y); cout << "Tipo de Uso" << endl;

    SetConsoleTextAttribute(hConsole, 15);
}

/// <param name="y">eje-y</param>
void mostrarFilaDeListaDeProductosDisponibles(deltronXpand deltronXpand, int y, productoDisponible productoDisponible) {

    gotoxy(0, y); cout << productoDisponible.productoEnAlmacenId << endl;
    gotoxy(5, y); cout << productoDisponible.marca << endl;
    gotoxy(20, y); cout << productoDisponible.nombre << endl;
    gotoxy(50, y); cout << productoDisponible.precio << endl;
    gotoxy(65, y); cout << productoDisponible.stock << endl;
    gotoxy(75, y); cout << obtenerNombreDeClasificacion(deltronXpand, productoDisponible.clasificacionId) << endl;
    gotoxy(90, y); cout << obtenerNombreDeTipoDeUso(deltronXpand, productoDisponible.tipoDeUsoId) << endl;
}

/// <param name="y">eje-y</param>
void mostrarCabeceraDeListaDeProductosComprados(int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);

    gotoxy(0, y); cout << "Marca" << endl;
    gotoxy(15, y); cout << "Nombre" << endl;
    gotoxy(35, y); cout << "Precio (S/)" << endl;
    gotoxy(55, y); cout << "Cantidad" << endl;
    gotoxy(75, y); cout << "Parcial (S/)" << endl;

    SetConsoleTextAttribute(hConsole, 15);
}

/// <param name="y">eje-y</param>
void mostrarFilaDeListaDeProductosComprados(deltronXpand deltronXpand, int y, productoComprado productoComprado) {
    gotoxy(0, y); cout << productoComprado.marca << endl;
    gotoxy(15, y); cout << productoComprado.nombre << endl;
    gotoxy(35, y); cout << productoComprado.precio << endl;
    gotoxy(55, y); cout << productoComprado.cantidad << endl;
    gotoxy(75, y); cout << (productoComprado.precio * productoComprado.cantidad) << endl;
}

void mostrarListaDeProductosDisponibles(deltronXpand deltronXpand, productoDisponible* productosDisponibles, int productosDisponiblesCantidad) {
    int fila = 1;
    mostrarCabeceraDeListaDeProductosDisponibles(12);
    for (int i = 0; i < productosDisponiblesCantidad; i++) {
        if (productosDisponibles[i].stock > 0) {
            mostrarFilaDeListaDeProductosDisponibles(deltronXpand, 12 + fila, productosDisponibles[i]);
            fila++;
        }
    }
}

#pragma endregion

#pragma region Funciones de Inicializacion

void inicializarEmpleadosDeVentas(deltronXpand& deltronXpand) {

    deltronXpand.empleadosDeVentas[0].apellido = "Descalzi";
    deltronXpand.empleadosDeVentas[0].nombre = "Yessica Rubí";
    deltronXpand.empleadosDeVentas[0].dni = "11111111";
    deltronXpand.empleadosDeVentas[0].clave = "123456";

    deltronXpand.empleadosDeVentas[1].apellido = "Sanchez";
    deltronXpand.empleadosDeVentas[1].nombre = "Joselyn";
    deltronXpand.empleadosDeVentas[1].dni = "22222222";
    deltronXpand.empleadosDeVentas[1].clave = "123456";

    deltronXpand.empleadosDeVentas[2].apellido = "Zavala";
    deltronXpand.empleadosDeVentas[2].nombre = "Edward Daniel";
    deltronXpand.empleadosDeVentas[2].dni = "33333333";
    deltronXpand.empleadosDeVentas[2].clave = "123456";

    deltronXpand.empleadosDeVentas[3].apellido = "Orbegoso";
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
    deltronXpand.clasificaciones[1].nombre = "Computadoras";

    deltronXpand.clasificaciones[2].clasificacionId = 3;
    deltronXpand.clasificaciones[2].nombre = "Discos Duros";

    deltronXpand.clasificaciones[3].clasificacionId = 4;
    deltronXpand.clasificaciones[3].nombre = "CPU";

    deltronXpand.clasificaciones[4].clasificacionId = 5;
    deltronXpand.clasificaciones[4].nombre = "GPU";

    deltronXpand.clasificacionesCantidad = 5;
}

void inicializarProductos(deltronXpand& deltronXpand) {

    deltronXpand.productos[0].productoId = 1;
    deltronXpand.productos[0].marca = "AMD";
    deltronXpand.productos[0].nombre = "Ryzen 3 3100";
    deltronXpand.productos[0].precio = 650;
    deltronXpand.productos[0].clasificacionId = 4;
    deltronXpand.productos[0].tipoDeUsoId = 2;
    deltronXpand.productos[0].activo = true;

    deltronXpand.productos[1].productoId = 2;
    deltronXpand.productos[1].marca = "AMD";
    deltronXpand.productos[1].nombre = "Ryzen 5 3600";
    deltronXpand.productos[1].precio = 910;
    deltronXpand.productos[1].clasificacionId = 4;
    deltronXpand.productos[1].tipoDeUsoId = 2;
    deltronXpand.productos[1].activo = true;

    deltronXpand.productos[2].productoId = 3;
    deltronXpand.productos[2].marca = "DELL";
    deltronXpand.productos[2].nombre = "NOTEBOOK DELL LATITUDE CORE I7";
    deltronXpand.productos[2].precio = 3404;
    deltronXpand.productos[2].clasificacionId = 2;
    deltronXpand.productos[2].tipoDeUsoId = 1;
    deltronXpand.productos[2].activo = true;

    deltronXpand.productos[3].productoId = 4;
    deltronXpand.productos[3].marca = "HP";
    deltronXpand.productos[3].nombre = "AII-IN-ONE CORE i7";
    deltronXpand.productos[3].precio = 3497.68;
    deltronXpand.productos[3].clasificacionId = 2;
    deltronXpand.productos[3].tipoDeUsoId = 1;
    deltronXpand.productos[3].activo = true;

    deltronXpand.productos[4].productoId = 5;
    deltronXpand.productos[4].marca = "LG";
    deltronXpand.productos[4].nombre = "All-In-One Core i7 ";
    deltronXpand.productos[4].precio = 5021.75;
    deltronXpand.productos[4].clasificacionId = 2;
    deltronXpand.productos[4].tipoDeUsoId = 1;
    deltronXpand.productos[4].activo = true;

    deltronXpand.productos[5].productoId = 6;
    deltronXpand.productos[5].marca = "ADVANCE";
    deltronXpand.productos[5].nombre = "All-In-One Core i7";
    deltronXpand.productos[5].precio = 3797.36;
    deltronXpand.productos[5].clasificacionId = 2;
    deltronXpand.productos[5].tipoDeUsoId = 1;
    deltronXpand.productos[5].activo = true;

    deltronXpand.productos[6].productoId = 7;
    deltronXpand.productos[6].marca = "DELL";
    deltronXpand.productos[6].nombre = "All-In-One Core i7";
    deltronXpand.productos[6].precio = 5539.74;
    deltronXpand.productos[6].clasificacionId = 2;
    deltronXpand.productos[6].tipoDeUsoId = 1;
    deltronXpand.productos[6].activo = true;

    deltronXpand.productos[7].productoId = 8;
    deltronXpand.productos[7].marca = "LENOVO";
    deltronXpand.productos[7].nombre = "All-In-One Core i7";
    deltronXpand.productos[7].precio = 4108.15;
    deltronXpand.productos[7].clasificacionId = 2;
    deltronXpand.productos[7].tipoDeUsoId = 1;
    deltronXpand.productos[7].activo = true;

    deltronXpand.productos[8].productoId = 9;
    deltronXpand.productos[8].marca = "LENOVO";
    deltronXpand.productos[8].nombre = "All-In-One Core i7 M920z";
    deltronXpand.productos[8].precio = 5638.23;
    deltronXpand.productos[8].clasificacionId = 2;
    deltronXpand.productos[8].tipoDeUsoId = 1;
    deltronXpand.productos[8].activo = true;

    deltronXpand.productos[9].productoId = 10;
    deltronXpand.productos[9].marca = "ADVANCE";
    deltronXpand.productos[9].nombre = "All-In-One Core i5";
    deltronXpand.productos[9].precio = 2418.84;
    deltronXpand.productos[9].clasificacionId = 2;
    deltronXpand.productos[9].tipoDeUsoId = 1;
    deltronXpand.productos[9].activo = true;

    deltronXpand.productos[10].productoId = 11;
    deltronXpand.productos[10].marca = "ADVANCE";
    deltronXpand.productos[10].nombre = "All-in-One Advance AIO AI8670";
    deltronXpand.productos[10].precio = 4259.96;
    deltronXpand.productos[10].clasificacionId = 2;
    deltronXpand.productos[10].tipoDeUsoId = 1;
    deltronXpand.productos[10].activo = true;

    deltronXpand.productos[11].productoId = 12;
    deltronXpand.productos[11].marca = "ADVANCE";
    deltronXpand.productos[11].nombre = "ADV1060";
    deltronXpand.productos[11].precio = 115.61;
    deltronXpand.productos[11].clasificacionId = 1;
    deltronXpand.productos[11].tipoDeUsoId = 2;
    deltronXpand.productos[11].activo = true;

    deltronXpand.productos[12].productoId = 13;
    deltronXpand.productos[12].marca = "BOOMER";
    deltronXpand.productos[12].nombre = "ATX P4 Version 1.1";
    deltronXpand.productos[12].precio = 107.05;
    deltronXpand.productos[12].clasificacionId = 1;
    deltronXpand.productos[12].tipoDeUsoId = 2;
    deltronXpand.productos[12].activo = true;

    deltronXpand.productos[13].productoId = 14;
    deltronXpand.productos[13].marca = "BOOMER";
    deltronXpand.productos[13].nombre = "ATX P4 Version 1.1";
    deltronXpand.productos[13].precio = 93.12;
    deltronXpand.productos[13].clasificacionId = 1;
    deltronXpand.productos[13].tipoDeUsoId = 2;
    deltronXpand.productos[13].activo = true;

    deltronXpand.productos[14].productoId = 15;
    deltronXpand.productos[14].marca = "WESTERN DIGITAL";
    deltronXpand.productos[14].nombre = "WD Black 2TB";
    deltronXpand.productos[14].precio = 521.87;
    deltronXpand.productos[14].clasificacionId = 3;
    deltronXpand.productos[14].tipoDeUsoId = 2;
    deltronXpand.productos[14].activo = true;

    deltronXpand.productos[15].productoId = 16;
    deltronXpand.productos[15].marca = "HP";
    deltronXpand.productos[15].nombre = "SSD - HP-COMPAQ";
    deltronXpand.productos[15].precio = 509.47;
    deltronXpand.productos[15].clasificacionId = 3;
    deltronXpand.productos[15].tipoDeUsoId = 2;
    deltronXpand.productos[15].activo = true;

    deltronXpand.productos[16].productoId = 17;
    deltronXpand.productos[16].marca = "HP";
    deltronXpand.productos[16].nombre = "HP S750";
    deltronXpand.productos[16].precio = 149.39;
    deltronXpand.productos[16].clasificacionId = 3;
    deltronXpand.productos[16].tipoDeUsoId = 2;
    deltronXpand.productos[16].activo = true;

    deltronXpand.productos[17].productoId = 18;
    deltronXpand.productos[17].marca = "kingston";
    deltronXpand.productos[17].nombre = "KC2500, 250GB.";
    deltronXpand.productos[17].precio = 232.46;
    deltronXpand.productos[17].clasificacionId = 3;
    deltronXpand.productos[17].tipoDeUsoId = 2;
    deltronXpand.productos[17].activo = true;

    deltronXpand.productos[18].productoId = 19;
    deltronXpand.productos[18].marca = "Intel";
    deltronXpand.productos[18].nombre = "Core i9-10900X";
    deltronXpand.productos[18].precio = 3200.68;
    deltronXpand.productos[18].clasificacionId = 4;
    deltronXpand.productos[18].tipoDeUsoId = 2;
    deltronXpand.productos[18].activo = true;

    deltronXpand.productos[19].productoId = 20;
    deltronXpand.productos[19].marca = "Intel";
    deltronXpand.productos[19].nombre = "Core i9-10920X";
    deltronXpand.productos[19].precio = 2996.77;
    deltronXpand.productos[19].clasificacionId = 4;
    deltronXpand.productos[19].tipoDeUsoId = 2;
    deltronXpand.productos[19].activo = true;

    deltronXpand.productos[20].productoId = 21;
    deltronXpand.productos[20].marca = "Intel";
    deltronXpand.productos[20].nombre = "Core i5-9600K";
    deltronXpand.productos[20].precio = 1125.95;
    deltronXpand.productos[20].clasificacionId = 4;
    deltronXpand.productos[20].tipoDeUsoId = 2;
    deltronXpand.productos[20].activo = true;

    deltronXpand.productos[21].productoId = 22;
    deltronXpand.productos[21].marca = "Intel";
    deltronXpand.productos[21].nombre = "Core i3-9100";
    deltronXpand.productos[21].precio = 520.16;
    deltronXpand.productos[21].clasificacionId = 4;
    deltronXpand.productos[21].tipoDeUsoId = 2;
    deltronXpand.productos[21].activo = true;

    deltronXpand.productos[22].productoId = 23;
    deltronXpand.productos[22].marca = "Intel";
    deltronXpand.productos[22].nombre = "Core i3-9100F";
    deltronXpand.productos[22].precio = 331.80;
    deltronXpand.productos[22].clasificacionId = 4;
    deltronXpand.productos[22].tipoDeUsoId = 2;
    deltronXpand.productos[22].activo = true;

    deltronXpand.productos[23].productoId = 24;
    deltronXpand.productos[23].marca = "Intel";
    deltronXpand.productos[23].nombre = "Core i7-9700K";
    deltronXpand.productos[23].precio = 1686.75;
    deltronXpand.productos[23].clasificacionId = 4;
    deltronXpand.productos[23].tipoDeUsoId = 2;
    deltronXpand.productos[23].activo = true;

    deltronXpand.productos[24].productoId = 25;
    deltronXpand.productos[24].marca = "Intel";
    deltronXpand.productos[24].nombre = "Core i7-9700F";
    deltronXpand.productos[24].precio = 1340.08;
    deltronXpand.productos[24].clasificacionId = 4;
    deltronXpand.productos[24].tipoDeUsoId = 2;
    deltronXpand.productos[24].activo = true;

    deltronXpand.productos[25].productoId = 26;
    deltronXpand.productos[25].marca = "MSI";
    deltronXpand.productos[25].nombre = "GEFORCE GTX 1650";
    deltronXpand.productos[25].precio = 850.75;
    deltronXpand.productos[25].clasificacionId = 5;
    deltronXpand.productos[25].tipoDeUsoId = 2;
    deltronXpand.productos[25].activo = true;

    deltronXpand.productos[26].productoId = 27;
    deltronXpand.productos[26].marca = "MSI";
    deltronXpand.productos[26].nombre = "GEFORCE GTX 1050";
    deltronXpand.productos[26].precio = 600.05;
    deltronXpand.productos[26].clasificacionId = 5;
    deltronXpand.productos[26].tipoDeUsoId = 2;
    deltronXpand.productos[26].activo = true;

    deltronXpand.productos[27].productoId = 28;
    deltronXpand.productos[27].marca = "RADEON";
    deltronXpand.productos[27].nombre = "RADEON RX 568";
    deltronXpand.productos[27].precio = 450.78;
    deltronXpand.productos[27].clasificacionId = 5;
    deltronXpand.productos[27].tipoDeUsoId = 2;
    deltronXpand.productos[27].activo = true;

    deltronXpand.productos[28].productoId = 29;
    deltronXpand.productos[28].marca = "MSI";
    deltronXpand.productos[28].nombre = "SLI Bridge L MSI, 2-WAY";
    deltronXpand.productos[28].precio = 100.95;
    deltronXpand.productos[28].clasificacionId = 5;
    deltronXpand.productos[28].tipoDeUsoId = 2;
    deltronXpand.productos[28].activo = true;

    deltronXpand.productos[29].productoId = 30;
    deltronXpand.productos[29].marca = "AMD";
    deltronXpand.productos[29].nombre = "Ryzen 7 3700X";
    deltronXpand.productos[29].precio = 1520;
    deltronXpand.productos[29].clasificacionId = 4;
    deltronXpand.productos[29].tipoDeUsoId = 2;
    deltronXpand.productos[29].activo = true;

    deltronXpand.productosCantidad = 30;
}

void inicializarProductosEnAlmacen(deltronXpand& deltronXpand) {
    int i = 0;

    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 1;
    deltronXpand.productosEnAlmacen[i].productoId = 1;
    deltronXpand.productosEnAlmacen[i].stock = 1;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 2;
    deltronXpand.productosEnAlmacen[i].productoId = 2;
    deltronXpand.productosEnAlmacen[i].stock = 3;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 3;
    deltronXpand.productosEnAlmacen[i].productoId = 3;
    deltronXpand.productosEnAlmacen[i].stock = 9;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 4;
    deltronXpand.productosEnAlmacen[i].productoId = 4;
    deltronXpand.productosEnAlmacen[i].stock = 13;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 5;
    deltronXpand.productosEnAlmacen[i].productoId = 5;
    deltronXpand.productosEnAlmacen[i].stock = 6;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 1;
    deltronXpand.productosEnAlmacen[i].productoId = 6;
    deltronXpand.productosEnAlmacen[i].stock = 7;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 2;
    deltronXpand.productosEnAlmacen[i].productoId = 7;
    deltronXpand.productosEnAlmacen[i].stock = 13;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 3;
    deltronXpand.productosEnAlmacen[i].productoId = 8;
    deltronXpand.productosEnAlmacen[i].stock = 21;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 4;
    deltronXpand.productosEnAlmacen[i].productoId = 9;
    deltronXpand.productosEnAlmacen[i].stock = 4;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 5;
    deltronXpand.productosEnAlmacen[i].productoId = 10;
    deltronXpand.productosEnAlmacen[i].stock = 8;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 1;
    deltronXpand.productosEnAlmacen[i].productoId = 11;
    deltronXpand.productosEnAlmacen[i].stock = 9;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 2;
    deltronXpand.productosEnAlmacen[i].productoId = 12;
    deltronXpand.productosEnAlmacen[i].stock = 11;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 3;
    deltronXpand.productosEnAlmacen[i].productoId = 13;
    deltronXpand.productosEnAlmacen[i].stock = 13;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 4;
    deltronXpand.productosEnAlmacen[i].productoId = 14;
    deltronXpand.productosEnAlmacen[i].stock = 7;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 5;
    deltronXpand.productosEnAlmacen[i].productoId = 15;
    deltronXpand.productosEnAlmacen[i].stock = 10;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 1;
    deltronXpand.productosEnAlmacen[i].productoId = 16;
    deltronXpand.productosEnAlmacen[i].stock = 11;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 2;
    deltronXpand.productosEnAlmacen[i].productoId = 17;
    deltronXpand.productosEnAlmacen[i].stock = 18;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 3;
    deltronXpand.productosEnAlmacen[i].productoId = 18;
    deltronXpand.productosEnAlmacen[i].stock = 17;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 4;
    deltronXpand.productosEnAlmacen[i].productoId = 19;
    deltronXpand.productosEnAlmacen[i].stock = 18;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 5;
    deltronXpand.productosEnAlmacen[i].productoId = 20;
    deltronXpand.productosEnAlmacen[i].stock = 21;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 1;
    deltronXpand.productosEnAlmacen[i].productoId = 21;
    deltronXpand.productosEnAlmacen[i].stock = 22;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 2;
    deltronXpand.productosEnAlmacen[i].productoId = 22;
    deltronXpand.productosEnAlmacen[i].stock = 11;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 3;
    deltronXpand.productosEnAlmacen[i].productoId = 23;
    deltronXpand.productosEnAlmacen[i].stock = 10;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 4;
    deltronXpand.productosEnAlmacen[i].productoId = 24;
    deltronXpand.productosEnAlmacen[i].stock = 18;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 5;
    deltronXpand.productosEnAlmacen[i].productoId = 25;
    deltronXpand.productosEnAlmacen[i].stock = 21;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 1;
    deltronXpand.productosEnAlmacen[i].productoId = 26;
    deltronXpand.productosEnAlmacen[i].stock = 22;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 2;
    deltronXpand.productosEnAlmacen[i].productoId = 27;
    deltronXpand.productosEnAlmacen[i].stock = 12;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 3;
    deltronXpand.productosEnAlmacen[i].productoId = 28;
    deltronXpand.productosEnAlmacen[i].stock = 10;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 4;
    deltronXpand.productosEnAlmacen[i].productoId = 29;
    deltronXpand.productosEnAlmacen[i].stock = 10;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 5;
    deltronXpand.productosEnAlmacen[i].productoId = 30;
    deltronXpand.productosEnAlmacen[i].stock = 1;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 1;
    deltronXpand.productosEnAlmacen[i].productoId = 25;
    deltronXpand.productosEnAlmacen[i].stock = 21;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 2;
    deltronXpand.productosEnAlmacen[i].productoId = 26;
    deltronXpand.productosEnAlmacen[i].stock = 4;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 3;
    deltronXpand.productosEnAlmacen[i].productoId = 27;
    deltronXpand.productosEnAlmacen[i].stock = 3;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 4;
    deltronXpand.productosEnAlmacen[i].productoId = 28;
    deltronXpand.productosEnAlmacen[i].stock = 10;
    i++;
    deltronXpand.productosEnAlmacen[i].productoEnAlmacenId = i + 1;
    deltronXpand.productosEnAlmacen[i].almacenId = 5;
    deltronXpand.productosEnAlmacen[i].productoId = 30;
    deltronXpand.productosEnAlmacen[i].stock = 15;
    i++;

    deltronXpand.productosEnAlmacenCantidad = i;
}

void inicializarOrdenesDeCompra(deltronXpand& deltronXpand) {

    deltronXpand.ordenesDeCompra[0].ordenDeCompraId = 1;
    deltronXpand.ordenesDeCompra[0].clienteRUC = "11111111111";
    deltronXpand.ordenesDeCompra[0].fecha = "2020/Enero/12";

    deltronXpand.ordenesDeCompra[1].ordenDeCompraId = 2;
    deltronXpand.ordenesDeCompra[1].clienteRUC = "22222222222";
    deltronXpand.ordenesDeCompra[1].fecha = "2020/Febrero/15";

    deltronXpand.ordenesDeCompra[2].ordenDeCompraId = 3;
    deltronXpand.ordenesDeCompra[2].clienteRUC = "11111111111";
    deltronXpand.ordenesDeCompra[2].fecha = "2020/Agosto/24";

    deltronXpand.ordenesDeCompra[3].ordenDeCompraId = 4;
    deltronXpand.ordenesDeCompra[3].clienteRUC = "11111111111";
    deltronXpand.ordenesDeCompra[3].fecha = "2020/Octubre/29";

    deltronXpand.ordenesDeCompraCantidad = 4;
}

void inicializarProductosComprados(deltronXpand& deltronXpand) {

    deltronXpand.productosComprados[0].productoCompradoId = 1;
    deltronXpand.productosComprados[0].productoEnAlmacenId = 1;
    deltronXpand.productosComprados[0].ordenDeCompraId = 1;
    deltronXpand.productosComprados[0].cantidad = 1;
    deltronXpand.productosComprados[0].marca = "AMD";
    deltronXpand.productosComprados[0].nombre = "Ryzen 3 3100";
    deltronXpand.productosComprados[0].precio = 250;

    deltronXpand.productosComprados[1].productoCompradoId = 2;
    deltronXpand.productosComprados[1].productoEnAlmacenId = 2;
    deltronXpand.productosComprados[1].ordenDeCompraId = 2;
    deltronXpand.productosComprados[1].cantidad = 2;
    deltronXpand.productosComprados[1].marca = "AMD";
    deltronXpand.productosComprados[1].nombre = "Ryzen 5 3600";
    deltronXpand.productosComprados[1].precio = 200;

    deltronXpand.productosComprados[2].productoCompradoId = 3;
    deltronXpand.productosComprados[2].productoEnAlmacenId = 3;
    deltronXpand.productosComprados[2].ordenDeCompraId = 2;
    deltronXpand.productosComprados[2].cantidad = 1;
    deltronXpand.productosComprados[2].marca = "AMD";
    deltronXpand.productosComprados[2].nombre = "Ryzen 7 3700X";
    deltronXpand.productosComprados[2].precio = 300;

    deltronXpand.productosComprados[3].productoCompradoId = 4;
    deltronXpand.productosComprados[3].productoEnAlmacenId = 3;
    deltronXpand.productosComprados[3].ordenDeCompraId = 3;
    deltronXpand.productosComprados[3].cantidad = 1;
    deltronXpand.productosComprados[3].marca = "AMD";
    deltronXpand.productosComprados[3].nombre = "Ryzen 7 3700X";
    deltronXpand.productosComprados[3].precio = 290;

    deltronXpand.productosComprados[4].productoCompradoId = 5;
    deltronXpand.productosComprados[4].productoEnAlmacenId = 3;
    deltronXpand.productosComprados[4].ordenDeCompraId = 4;
    deltronXpand.productosComprados[4].cantidad = 1;
    deltronXpand.productosComprados[4].marca = "AMD";
    deltronXpand.productosComprados[4].nombre = "Ryzen 7 3700X";
    deltronXpand.productosComprados[4].precio = 295;

    deltronXpand.productosCompradosCantidad = 5;
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
