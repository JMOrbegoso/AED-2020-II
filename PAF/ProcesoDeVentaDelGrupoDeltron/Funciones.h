#include "AuxiliaresConEstructuras.h"

using namespace std;

#pragma region Funciones Basicas con estructuras

string loginPersonalDeVentas(deltronXpand deltronXpand) {

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Inicio de Sesión de personal de ventas");

    // Pide DNI (8 caracteres)
    string dniIngresado = pedirDNI();
    // Pide la clave (minimo 6 caracteres)
    string claveIngresada = pedirClave();

    bool encontroPersonalDeVentas = false;

    // Buscar que el DNI sea exactamente igual al de un empleado de ventas existente
    for (int i = 0; i < deltronXpand.empleadosDeVentasCantidad; i++) {
        if (deltronXpand.empleadosDeVentas[i].dni == dniIngresado) {
            // Se encontro un empleado de ventas con ese DNI
            // Significa que el empleado de ventas fue encontrado
            encontroPersonalDeVentas = true;

            // Verfica con un "if" si la clave ingresada es la misma del empleado de ventas guardado
            if (claveIngresada == deltronXpand.empleadosDeVentas[i].clave) {
                // Significa que el usuario ingreso su clave correctamente.
                system("cls");

                gotoxy(10, 15); cout << "Bienvenid@ " << obtenerNombreCompletoDeEmpleadoDeVentas(deltronXpand, dniIngresado) << endl;

                gotoxy(0, 30); esperarMostrandoTexto("Ingresando", true);

                return deltronXpand.empleadosDeVentas[i].dni;
            }
            else {
                // Significa que el usuario NO ingreso su clave correctamente.
                cout << "Contraseña incorrecta, por favor corrijala" << endl;
                return "";
            }
        }
    }

    // Verfica si no se encontro ningun empleado de ventas como ese DNI
    if (encontroPersonalDeVentas == false) {
        cout << "No fue encontrado su DNI. Usuario no existe" << endl;
    }

    return "";
}

string loginCliente(deltronXpand deltronXpand) {

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Inicio de Sesión de cliente");

    // Pide RUC (11 caracteres)
    string rucIngresado = pedirRUC();
    // Pide la clave (minimo 6 caracteres)
    string claveIngresada = pedirClave();

    bool encontroCliente = false;

    // Buscar que el RUC sea exactamente igual al de un cliente existente
    for (int i = 0; i < deltronXpand.clientesCantidad; i++) {
        if (deltronXpand.clientes[i].ruc == rucIngresado) {
            // Se encontro un cliente con ese RUC
            // Significa que el cliente fue encontrado
            encontroCliente = true;

            // Verfica con un "if" si la clave ingresada es la misma del cliente guardado
            if (claveIngresada == deltronXpand.clientes[i].clave) {
                // Significa que el usuario ingreso su clave correctamente.
                system("cls");

                gotoxy(10, 15); cout << "Bienvenid@ " << obtenerRazonSocialDeCliente(deltronXpand, rucIngresado) << endl;

                gotoxy(0, 30); esperarMostrandoTexto("Ingresando", true);

                return deltronXpand.clientes[i].ruc;
            }
            else {
                // Significa que el usuario NO ingreso su clave correctamente.
                cout << "Contraseña incorrecta, por favor corrijala" << endl;
                return "";
            }
        }
    }

    // Verfica si no se encontro ningun cliente como ese DNI
    if (encontroCliente == false) {
        cout << "No fue encontrado su DNI. Usuario no existe" << endl;
    }

    return "";
}

void registrarPersonalDeVentas(deltronXpand& deltronXpand) {

    string nombre, apellido, dni, clave;

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Registrar personal de ventas");

    // Pide nombres
    nombre = pedirTexto("¿Cúal es su nombre?", 1);
    // Pide apellidos
    apellido = pedirTexto("¿Cúal es su apellido?", 2);
    // Pide DNI (8 caracteres)
    dni = pedirDNI();
    // Pide la clave (minimo 6 caracteres)
    clave = pedirClave();

    // Verifica con un "for" si el DNI del nuevo empleadoDeVentas ya estï¿½ en uso por otro empleadoDeVentas ya registrado
    bool usuarioYaExiste = false;
    for (int i = 0; i < deltronXpand.empleadosDeVentasCantidad; i++) {
        if (deltronXpand.empleadosDeVentas[i].dni == dni) {
            usuarioYaExiste = true;
            break;
        }
    }

    if (usuarioYaExiste) {
        // Si ya existe alguno registrado muestra un texto diciendo que el RUC usado ya estï¿½ en uso
        system("cls");
        cout << "Usted ya se habia registrado con su DNI, por favor inicie sesión." << endl;
        esperarMostrandoTexto("Por favor inicie sesión", true);
    }
    else {
        // Si no encontrï¿½ el DNI, aï¿½ade el empleado de ventas al arreglo de empleados de ventas
        deltronXpand.empleadosDeVentas[deltronXpand.empleadosDeVentasCantidad].nombre = nombre;
        deltronXpand.empleadosDeVentas[deltronXpand.empleadosDeVentasCantidad].apellido = apellido;
        deltronXpand.empleadosDeVentas[deltronXpand.empleadosDeVentasCantidad].dni = dni;
        deltronXpand.empleadosDeVentas[deltronXpand.empleadosDeVentasCantidad].clave = clave;
        deltronXpand.empleadosDeVentasCantidad++;

        // Le muestra un mensaje diciendo que fue registrado exitosamente y ya puede iniciar sesiï¿½n
        cout << "Fue registrado exitosamente" << endl;
        esperarMostrandoTexto("Ahora ya puede iniciar sesión", true);
    }
}

void registrarCliente(deltronXpand& deltronXpand) {
    string razonSocial, ruc, clave;

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Registrar cliente");

    // Pide razon social
    razonSocial = pedirTexto("¿Cúal es su razón social?", 1);
    // Pide ruc (11 caracteres)
    ruc = pedirRUC();
    // Pide la clave (minimo 6 caracteres)
    clave = pedirClave();

    // Verifica con un "for" si el ruc del nuevo cliente ya estï¿½ en uso por otro cliente ya registrado
    bool usuarioYaExiste = false;
    for (int i = 0; i < deltronXpand.clientesCantidad; i++) {
        if (deltronXpand.clientes[i].ruc == ruc) {
            usuarioYaExiste = true;
            break;
        }
    }

    if (usuarioYaExiste) {
        // Si ya existe alguno registrado muestra un texto diciendo que el RUC usado ya estï¿½ en uso
        system("cls");
        cout << "Usted ya se habia registrado con su ruc, por favor inicie sesión." << endl;
        esperarMostrandoTexto("Por favor inicie sesión", true);
    }
    else {
        // Si no encontrï¿½ el ruc, aï¿½ade el empleado de ventas al arreglo de empleados de ventas
        deltronXpand.clientes[deltronXpand.clientesCantidad].razonSocial = razonSocial;
        deltronXpand.clientes[deltronXpand.clientesCantidad].ruc = ruc;
        deltronXpand.clientes[deltronXpand.clientesCantidad].clave = clave;
        deltronXpand.clientesCantidad++;

        // Le muestra un mensaje diciendo que fue registrado exitosamente y ya puede iniciar sesiï¿½n
        cout << "Fue registrado exitosamente" << endl;
        esperarMostrandoTexto("Ahora ya puede iniciar sesión", true);
    }
}

void mostrarOrdenes(deltronXpand deltronXpand) {
    // Muestra todas las ordenes del arreglo de ordenesDeCompra, mostrando su comprador y monto total

    float parcial;
    string clienteRazonSocial;

    // Limpia la pantalla
    system("cls");

    mostrarAppTitulo();
    mostrarTituloDeOpcion("Ordenes realizadas por los clientes");

    int fila = 0;
    // Recorre con un for todo el arreglo de ordenesDeCompra
    for (int i = 0; i < deltronXpand.ordenesDeCompraCantidad; i++)
    {
        parcial = 0;
        cout << endl << "El " << deltronXpand.ordenesDeCompra[i].fecha << " el cliente " << obtenerRazonSocialDeCliente(deltronXpand, deltronXpand.ordenesDeCompra[i].clienteRUC) << " ha comprado:" << endl;
        mostrarCabeceraDeListaDeProductosComprados(12 + fila);

        // Obtener el producto comprado desde sus propiedades originales
        for (int j = 0; j < deltronXpand.productosCompradosCantidad; j++)
        {
            if (deltronXpand.productosComprados[j].ordenDeCompraId == deltronXpand.ordenesDeCompra[i].ordenDeCompraId)
            {
                // Se agrega el precio del producto al parcial acumulado
                parcial += deltronXpand.productosComprados[j].precio * deltronXpand.productosComprados[j].cantidad;

                // Se imprime en pantalla el producto
                mostrarFilaDeListaDeProductosComprados(deltronXpand, 13 + fila, deltronXpand.productosComprados[j]);
                fila++;
            }
        }

        // Muestra el precio total de la compra:
        mostrarPieDePresupuesto(parcial, 14 + fila);

        fila = fila + 10;

        cout << endl << endl;
        mostrarLineaSeparadora();
    }
}

void revisarAlmacenes(deltronXpand deltronXpand) {
    system("cls");

    mostrarAppTitulo();
    mostrarTituloDeOpcion("Revisar almacenes");

    int almacenId = pedirAlmacenId(deltronXpand);

    // Primero pregunta el almacen que desea buscar usando almacenId = pedirAlmacenId(deltronXpand);
    system("cls");

    string nombreDelAlmacen = obtenerNombreDeAlmacen(deltronXpand, almacenId);
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Producto en almacén de " + nombreDelAlmacen);

    mostrarCabeceraDeListaDeProductosEnAlmacen(10);

    // Luego debe de mostrar los productos en ese almacen, para saber los datos debe de usar un for dentro de otro for
    int fila = 1;
    for (int i = 0; i < deltronXpand.productosEnAlmacenCantidad; i++) {
        if (deltronXpand.productosEnAlmacen[i].almacenId == almacenId) {
            for (int j = 0; j < deltronXpand.productosCantidad; j++) {
                if (deltronXpand.productos[j].productoId == deltronXpand.productosEnAlmacen[i].productoId) {
                    // Mostrar los productos en pantalla
                    mostrarFilaDeListaDeProductosEnAlmacen(deltronXpand, 10 + fila, deltronXpand.productosEnAlmacen[i], deltronXpand.productos[j]);
                    fila++;
                }
            }
        }
    }
}

void registrarProducto(deltronXpand& deltronXpand) {
    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Registrar producto");

    // Agrega un nuevo producto preguntando al usuario
    deltronXpand.productos[deltronXpand.productosCantidad].productoId = deltronXpand.productosCantidad;
    deltronXpand.productos[deltronXpand.productosCantidad].marca = pedirTexto("Ingrese la marca del producto", 2);
    deltronXpand.productos[deltronXpand.productosCantidad].nombre = pedirTexto("Ingrese el nombre del producto", 2);
    deltronXpand.productos[deltronXpand.productosCantidad].precio = pedirDinero("Ingrese el costo del producto", 1);
    deltronXpand.productos[deltronXpand.productosCantidad].clasificacionId = pedirClasificacionId(deltronXpand);
    deltronXpand.productos[deltronXpand.productosCantidad].tipoDeUsoId = pedirTipoDeUsoId(deltronXpand);
    deltronXpand.productos[deltronXpand.productosCantidad].activo = true;
    deltronXpand.productosCantidad++;

    // Cuando termine de agregarlo debe de mostrar un menu pidiendo que añada el stock del producto en los almacenes deseados

    int almacenId = 0;
    int stock = 0;

    do {
        cout << "Especifique el almacen donde desea añadir su producto, o ingrese 0 para dejar de añadir:";
        cout << almacenId;

        if (almacenId == 0) {
            return;
        }

        almacenId = pedirAlmacenId(deltronXpand);
        stock = pedirEntero("Ingrese el stock", 0);

        deltronXpand.productosEnAlmacen[deltronXpand.productosEnAlmacenCantidad].productoEnAlmacenId = deltronXpand.productosEnAlmacenCantidad;
        deltronXpand.productosEnAlmacen[deltronXpand.productosEnAlmacenCantidad].almacenId = almacenId;
        deltronXpand.productosEnAlmacen[deltronXpand.productosEnAlmacenCantidad].productoId = deltronXpand.productosCantidad - 1;
        deltronXpand.productosEnAlmacen[deltronXpand.productosEnAlmacenCantidad].stock = stock;
        deltronXpand.productosEnAlmacenCantidad++;

    } while (almacenId != 0);
}

void editarProducto(deltronXpand& deltronXpand) {
    int productoIdPorEditar;

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Editar producto");

    mostrarCabeceraDeListaDeProductos(10);
    int fila = 0;
    for (int i = 0; i < deltronXpand.productosCantidad; i++) {
        mostrarFilaDeListaDeProductos(deltronXpand, 12 + fila, deltronXpand.productos[i]);
        fila++;
    }

    cout << "¿Cual es el Id del producto a editar?" << endl;
    cin >> productoIdPorEditar;

    // Valida si el Id ingresado es valido
    for (int i = 0; i < deltronXpand.productosCantidad; i++) {
        if (deltronXpand.productos[i].productoId == productoIdPorEditar) {
            // Encontró el producto, entonces lo edita
            //      string marca;
            deltronXpand.productos[i].marca = pedirTexto("Ingrese la nueva marca del producto", 2);
            //      string nombre;
            deltronXpand.productos[i].nombre = pedirTexto("Ingrese el nuevo nombre del producto", 2);
            //      float precio;
            deltronXpand.productos[i].precio = pedirDinero("Ingrese el nuevo costo del producto", 1);
            //      int clasificacionId;
            deltronXpand.productos[i].clasificacionId = pedirClasificacionId(deltronXpand);
            //      int tipoDeUsoId;
            deltronXpand.productos[i].tipoDeUsoId = pedirTipoDeUsoId(deltronXpand);

            cout << "Editó el producto correctamente." << endl;
            return;
        }
    }

    cout << "No se encontró el producto por editar." << endl;
}

void editarProductoEnAlmacen(deltronXpand& deltronXpand) {
    int productoIdPorEditar;

    system("cls");

    mostrarAppTitulo();
    mostrarTituloDeOpcion("Editar stock de un producto en almacén");

    int almacenId = pedirAlmacenId(deltronXpand);

    // Primero pregunta el almacen que desea buscar usando *almacenId = pedirAlmacenId(deltronXpand);*
    system("cls");

    string nombreDelAlmacen = obtenerNombreDeAlmacen(deltronXpand, almacenId);
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Editar stock de un producto en almacén de " + nombreDelAlmacen);

    mostrarCabeceraDeListaDeProductosEnAlmacen(10);

    // Luego debe de mostrar los productos en ese almacen, para saber los datos debe de usar un *for* dentro de otro *for*
    int fila = 1;
    for (int i = 0; i < deltronXpand.productosEnAlmacenCantidad; i++) {
        if (deltronXpand.productosEnAlmacen[i].almacenId == almacenId) {
            for (int j = 0; j < deltronXpand.productosCantidad; j++) {
                if (deltronXpand.productos[j].productoId == deltronXpand.productosEnAlmacen[i].productoId) {
                    // Mostrar los productos en pantalla
                    mostrarFilaDeListaDeProductosEnAlmacen(deltronXpand, 10 + fila, deltronXpand.productosEnAlmacen[i], deltronXpand.productos[j]);
                    fila++;
                }
            }
        }
    }

    // Se le pide al usuario que escoja ingrese el ID del *producto en almacen* a editar
    cout << "¿Cual es el Id del producto a editar?" << endl;
    cin >> productoIdPorEditar;

    // Busca en el arreglo de *productos en almacen* el elemento que tenga ese productoEnAlmacenId

    // Valida si el Id ingresado es valido
    for (int i = 0; i < deltronXpand.productosEnAlmacenCantidad; i++) {
        if (deltronXpand.productosEnAlmacen[i].productoEnAlmacenId == productoIdPorEditar) {
            // Encontró el producto, entonces lo edita
            // stock;
            deltronXpand.productosEnAlmacen[i].stock = pedirEntero("Ingrese el nuevo stock del producto", 0);

            cout << "Editó el producto correctamente." << endl;
            return;
        }
    }

    cout << "No se encontró el producto por editar." << endl;
}

void retirarProducto(deltronXpand& deltronXpand) {
    int productoIdPorRemover;

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Remover producto");

    mostrarCabeceraDeListaDeProductos(10);
    int fila = 0;
    for (int i = 0; i < deltronXpand.productosCantidad; i++) {
        mostrarFilaDeListaDeProductos(deltronXpand, 12 + fila, deltronXpand.productos[i]);
        fila++;
    }

    cout << "¿Cual es el Id del producto que desea remover?" << endl;
    cin >> productoIdPorRemover;

    // Valida si el Id ingresado es valido
    for (int i = 0; i < deltronXpand.productosCantidad; i++) {
        if (deltronXpand.productos[i].productoId == productoIdPorRemover) {
            // Encontró el producto, entonces lo remueve
            deltronXpand.productos[i].activo = false;
            cout << "Borró el producto correctamente." << endl;
            return;
        }
    }

    cout << "No se encontró el producto a borrar." << endl;
}

/// <summary>
/// Muestra un buscador de productos / catalogo al usuario
/// </summary>
void revisarCatalogo(deltronXpand deltronXpand) {
    int almacenId;
    int clasificacionId;

    // Limpia la pantalla
    system("cls");

    mostrarAppTitulo();
    mostrarTituloDeOpcion("Catalogo de productos");

    // Pregunta almacï¿½n
    almacenId = pedirAlmacenId(deltronXpand);

    // Limpia la pantalla
    system("cls");

    mostrarAppTitulo();
    mostrarTituloDeOpcion("Catalogo de productos");

    // Pregunta Clasificaciï¿½n
    clasificacionId = pedirClasificacionId(deltronXpand);

    // Limpia la pantalla
    system("cls");

    mostrarAppTitulo();
    mostrarTituloDeOpcion("Catalogo de productos");

    mostrarCabeceraDeListaDeProductos(9);

    // Muestra productos que cumplan ese requerimiento
    int fila = 1;
    for (int i = 0; i < deltronXpand.productosEnAlmacenCantidad; i++)
    {
        if (deltronXpand.productosEnAlmacen[i].almacenId == almacenId)
        {
            for (int j = 0; j < deltronXpand.productosCantidad; j++)
            {
                if (deltronXpand.productos[j].productoId == deltronXpand.productosEnAlmacen[i].productoId)
                {
                    if (deltronXpand.productos[j].clasificacionId == clasificacionId)
                    {
                        if (deltronXpand.productos[j].activo) {
                            mostrarFilaDeListaDeProductos(deltronXpand, 9 + fila, deltronXpand.productos[j]);
                            fila++;
                        }
                    }
                }
            }
        }
    }
}

void buscarProductoPorNombre(deltronXpand deltronXpand) {
    int almacenId;
    string terminoDeBusqueda;

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Buscar producto por nombre");

    // Pregunta el almacen
    almacenId = pedirAlmacenId(deltronXpand);

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Buscar producto por nombre");

    // Pregunta el termino de busqueda
    terminoDeBusqueda = pedirTerminoDeBusqueda();

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Buscar producto por nombre");

    cout << endl << "Productos con nombre similar a '" + terminoDeBusqueda + "' en el almacén " + obtenerNombreDeAlmacen(deltronXpand, almacenId) << endl;

    mostrarCabeceraDeListaDeProductos(12);

    int fila = 1;
    // Busca el termino de busqueda en el arreglo de productos
    for (int i = 0; i < deltronXpand.productosEnAlmacenCantidad; i++)
    {
        if (deltronXpand.productosEnAlmacen[i].almacenId == almacenId)
        {
            for (int j = 0; j < deltronXpand.productosCantidad; j++)
            {
                if (deltronXpand.productos[j].productoId == deltronXpand.productosEnAlmacen[i].productoId)
                {
                    // Verifica si el termino de busqueda se encuentra en el nombre del producto
                    if (contieneTexto(convertirEnMinusculas(deltronXpand.productos[j].nombre), terminoDeBusqueda))
                    {
                        // Ahora verifica si el producto está activo
                        if (deltronXpand.productos[j].activo) {
                            // Y los muestra en pantalla
                            mostrarFilaDeListaDeProductos(deltronXpand, 12 + fila, deltronXpand.productos[j]);
                            fila++;
                        }
                    }
                }
            }
        }
    }
}

void buscarProductoPorMarca(deltronXpand deltronXpand) {
    int almacenId;
    string terminoDeBusqueda;

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Buscar producto por marca");

    // Pregunta el almacen
    almacenId = pedirAlmacenId(deltronXpand);

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Buscar producto por marca");

    // Pregunta el termino de busqueda
    terminoDeBusqueda = pedirTerminoDeBusqueda();

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Buscar producto por marca");

    cout << endl << "Productos con marca similar a '" + terminoDeBusqueda + "' en el almacén " + obtenerNombreDeAlmacen(deltronXpand, almacenId) << endl;

    mostrarCabeceraDeListaDeProductos(12);

    int fila = 1;
    // Busca el termino de busqueda en el arreglo de productos
    for (int i = 0; i < deltronXpand.productosEnAlmacenCantidad; i++)
    {
        if (deltronXpand.productosEnAlmacen[i].almacenId == almacenId)
        {
            for (int j = 0; j < deltronXpand.productosCantidad; j++)
            {
                if (deltronXpand.productos[j].productoId == deltronXpand.productosEnAlmacen[i].productoId)
                {
                    // Verifica si el termino de busqueda se encuentra en el marca del producto
                    if (contieneTexto(convertirEnMinusculas(deltronXpand.productos[j].marca), terminoDeBusqueda))
                    {
                        // Ahora verifica si el producto está activo
                        if (deltronXpand.productos[j].activo) {
                            // Y los muestra en pantalla
                            mostrarFilaDeListaDeProductos(deltronXpand, 12 + fila, deltronXpand.productos[j]);
                            fila++;
                        }
                    }
                }
            }
        }
    }
}

void crearOrdenDeCompra(deltronXpand& deltronXpand, string clienteRUC) {
    productoDisponible productosDisponibles[100];
    int productosDisponiblesCantidad = 0;

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Generar orden de compra");

    // Pregunta el almacen
    int almacenId = pedirAlmacenId(deltronXpand);

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Generar orden de compra");

    // Genera un arreglo de productos disponibles para su compra

    for (int i = 0; i < deltronXpand.productosEnAlmacenCantidad; i++) {
        if (deltronXpand.productosEnAlmacen[i].almacenId == almacenId) {
            for (int j = 0; j < deltronXpand.productosCantidad; j++) {
                if (deltronXpand.productos[j].productoId == deltronXpand.productosEnAlmacen[i].productoId) {

                    if (deltronXpand.productos[j].activo) {
                        productosDisponibles[productosDisponiblesCantidad].productoEnAlmacenId = deltronXpand.productosEnAlmacen[i].productoEnAlmacenId;
                        productosDisponibles[productosDisponiblesCantidad].almacenId = deltronXpand.productosEnAlmacen[i].almacenId;
                        productosDisponibles[productosDisponiblesCantidad].productoId = deltronXpand.productosEnAlmacen[i].productoId;
                        productosDisponibles[productosDisponiblesCantidad].stock = deltronXpand.productosEnAlmacen[i].stock;
                        productosDisponibles[productosDisponiblesCantidad].marca = deltronXpand.productos[j].marca;
                        productosDisponibles[productosDisponiblesCantidad].nombre = deltronXpand.productos[j].nombre;
                        productosDisponibles[productosDisponiblesCantidad].precio = deltronXpand.productos[j].precio;
                        productosDisponibles[productosDisponiblesCantidad].clasificacionId = deltronXpand.productos[j].clasificacionId;
                        productosDisponibles[productosDisponiblesCantidad].tipoDeUsoId = deltronXpand.productos[j].tipoDeUsoId;

                        productosDisponiblesCantidad++;
                    }
                }
            }
        }
    }

    // Genera las estructuras de la orden de compra
    productoComprado productosComprados[100];
    int productosCompradosCantidad = 0;

    // Pide al usuario los productos a su orden
    int productoDeseadoId = 0;
    bool productoEncontrado = false;
    int cantidad = 0;

    do {
        system("cls");
        mostrarAppTitulo();
        mostrarTituloDeOpcion("Generar orden de compra");
        mostrarTituloDeOpcion("Productos disponibles en el almacén seleccionado");

        mostrarListaDeProductosDisponibles(deltronXpand, productosDisponibles, productosDisponiblesCantidad);

        cout << endl << "Seleccione el Id del producto deseado o '0' para dejar de añadir productos a su carrito de compra." << endl;
        cin >> productoDeseadoId;

        if (productoDeseadoId != 0) {
            int i;
            for (i = 0; i < productosDisponiblesCantidad; i++) {
                if (productoDeseadoId == productosDisponibles[i].productoEnAlmacenId) {
                    productoEncontrado = true;
                    break;
                }
            }

            if (productoEncontrado) {
                cantidad = pedirEntero("Ingrese la cantidad del producto (" + productosDisponibles[i].nombre + ")", 1, productosDisponibles[i].stock);

                productosComprados[productosCompradosCantidad].productoEnAlmacenId = productosDisponibles[i].almacenId;
                productosComprados[productosCompradosCantidad].marca = productosDisponibles[i].marca;
                productosComprados[productosCompradosCantidad].nombre = productosDisponibles[i].nombre;
                productosComprados[productosCompradosCantidad].precio = productosDisponibles[i].precio;
                productosComprados[productosCompradosCantidad].cantidad = cantidad;

                productosDisponibles[i].stock = productosDisponibles[i].stock - cantidad;

                productosCompradosCantidad++;

                cout << endl << productosDisponibles[i].nombre << " x" << cantidad << " añadido/s a su orden." << endl;
                esperarMostrandoTexto("Puede continuar añadiendo más productos.", true);
            }
            else {
                cout << endl << "Por favor ingrese un id valido." << endl;
            }
        }
    } while (productoDeseadoId != 0);

    if (productosCompradosCantidad == 0) {
        cout << endl << "Orden no creada, no introdujo ningún producto." << endl;
        return;
    }

    // Añadir los elementos del carrito de compra a los arreglos de deltronXpand
    deltronXpand.ordenesDeCompra[deltronXpand.ordenesDeCompraCantidad].ordenDeCompraId = deltronXpand.ordenesDeCompraCantidad + 1;
    deltronXpand.ordenesDeCompra[deltronXpand.ordenesDeCompraCantidad].clienteRUC = clienteRUC;
    deltronXpand.ordenesDeCompra[deltronXpand.ordenesDeCompraCantidad].fecha = deltronXpand.fecha;

    for (int i = 0; i < productosCompradosCantidad; i++) {

        deltronXpand.productosComprados[deltronXpand.productosCompradosCantidad].productoCompradoId = deltronXpand.productosCompradosCantidad + 1;
        deltronXpand.productosComprados[deltronXpand.productosCompradosCantidad].productoEnAlmacenId = productosComprados[i].productoEnAlmacenId;
        deltronXpand.productosComprados[deltronXpand.productosCompradosCantidad].ordenDeCompraId = deltronXpand.ordenesDeCompraCantidad + 1;

        deltronXpand.productosComprados[deltronXpand.productosCompradosCantidad].marca = productosComprados[i].marca;
        deltronXpand.productosComprados[deltronXpand.productosCompradosCantidad].nombre = productosComprados[i].nombre;
        deltronXpand.productosComprados[deltronXpand.productosCompradosCantidad].precio = productosComprados[i].precio;

        deltronXpand.productosComprados[deltronXpand.productosCompradosCantidad].cantidad = productosComprados[i].cantidad;

        deltronXpand.productosCompradosCantidad++;
    }

    deltronXpand.ordenesDeCompraCantidad++;

    cout << endl << "Orden creada correctamente, ya puede pagar sus productos haciendo uso de una pasarela de pago." << endl;
}

void verHistorialDeOrdenes(deltronXpand deltronXpand, string clienteRUC) {
    float parcial;
    int fila = 1;

    // Recorre con un for todo el arreglo de ordenesDeCompra
    // Buscando las compras realizadas por un cliente con el ruc *clienteRUC*

    // Limpia la pantalla
    system("cls");

    // Muestra titulo
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Historial de Ordenes");

    // Recorre con un for todo el arreglo de ordenesDeCompra
    for (int i = 0; i < deltronXpand.ordenesDeCompraCantidad; i++)
    {
        if (deltronXpand.ordenesDeCompra[i].clienteRUC == clienteRUC)
        {
            parcial = 0;
            cout << endl << "[Orden #" << deltronXpand.ordenesDeCompra[i].ordenDeCompraId << "]. Realizada el día " << deltronXpand.ordenesDeCompra[i].fecha << ":" << endl;

            mostrarCabeceraDeListaDeProductosComprados(10 + fila);

            // Obtener el producto comprado desde sus propiedades originales
            for (int j = 0; j < deltronXpand.productosCompradosCantidad; j++)
            {
                if (deltronXpand.productosComprados[j].ordenDeCompraId == deltronXpand.ordenesDeCompra[i].ordenDeCompraId)
                {
                    // Se agrega el precio del producto al parcial acumulado
                    parcial += deltronXpand.productosComprados[j].precio * deltronXpand.productosComprados[j].cantidad;

                    // Se imprime en pantalla el producto
                    mostrarFilaDeListaDeProductosComprados(deltronXpand, 11 + fila, deltronXpand.productosComprados[j]);

                    fila++;
                }
            }

            // Muestra el precio total de la compra:
            mostrarPieDePresupuesto(parcial, 11 + fila);

            fila = fila + 8;

            cout << endl << endl;

            mostrarLineaSeparadora();
        }
    }
}

#pragma endregion
