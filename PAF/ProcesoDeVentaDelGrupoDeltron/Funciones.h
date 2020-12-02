#include "AuxiliaresConEstructuras.h"

using namespace std;

#pragma region Funciones Basicas con estructuras

string loginPersonalDeVentas(deltronXpand deltronXpand) {
    // Pide DNI (8 caracteres)
    // Pide la clave (minimo 6 caracteres)
    // Buscar que el DNI sea exactamente igual al de un empleado de ventas existente
    //
    //      No encontro el DNI (El empleado de ventas no existe):
    //      Muestra texto diciendo que el empleado de ventas ingresado no existe
    //      Retorna ""
    //
    //      Si encontró el DNI (El empleado de ventas sí existe):
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
    //      Si encontró el RUC (El cliente si existe):
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
    // Verifica con un "for" si el DNI del nuevo empleadoDeVentas ya estï¿½ en uso por otro empleadoDeVentas ya registrado
    //
    //      Si ya existe alguno registrado muestra un texto diciendo que el DNI usado ya estï¿½ en uso
    //
    //      Si no encontrï¿½ el DNI, aï¿½ade el empleado de ventas al arreglo de empleados de ventas
    //      Le muestra un mensaje diciendo que fue registrado exitosamente y ya puede iniciar sesiï¿½n
}

void registrarCliente(deltronXpand& deltronXpand) {
    // Pide la razï¿½n social
    // Pide RUC (11 caracteres)
    // Pide la clave (minimo 6 caracteres)
    // Verifica con un "for" si el RUC del nuevo cliente ya estï¿½ en uso por otro cliente ya registrado
    //
    //      Si ya existe alguno registrado muestra un texto diciendo que el RUC usado ya estï¿½ en uso
    //
    //      Si no encontrï¿½ el RUC, aï¿½ade el cliente al arreglo de clientes
    //      Le muestra un mensaje diciendo que fue registrado exitosamente y ya puede iniciar sesiï¿½n
}

void mostrarOrdenes(deltronXpand deltronXpand) {
    // Muestra todas las ordenes del arreglo de ordenesDeCompra, mostrando su comprador y monto total

    float parcial;
    string clienteRazonSocial;

    // Limpia la pantalla
    system("cls");

    // Recorre con un for todo el arreglo de ordenesDeCompra
    for (int i = 0; i < deltronXpand.ordenesDeCompraCantidad; i++)
    {
        parcial = 0;
        cout << "El cliente: " << deltronXpand.ordenesDeCompra[i].clienteRazonSocial << " ha comprado:" << endl;

        // Obtener el producto comprado desde sus propiedades originales
        for (int j = 0; j < deltronXpand.productosCompradosCantidad; j++)
        {
            if (deltronXpand.productosComprados[j].ordenDeCompraId == deltronXpand.ordenesDeCompra[i].ordenDeCompraId)
            {
                // Se agrega el precio del producto al parcial acumulado
                parcial += deltronXpand.productosComprados[j].precio * deltronXpand.productosComprados[j].cantidad;

                // Se imprime en pantalla el producto
                cout << deltronXpand.productosComprados[j].nombre << endl;
            }
        }

        // Muestra el precio total de la compra:
        mostrarPieDePresupuesto(parcial);

        cout << endl;
    }
}

void revisarAlmacenes(deltronXpand deltronXpand) {
    // Pregunta de que almacen desea revisar y lo almacena en *almacenId*
    // Recorre con un *for* todos los *productos en almacen*
    // Busca los elementos de *productos en almacen* que tengan la propiedad almacenId igual que lo pedido por el usuario
    // Cuando encuentra uno de estos elementos busca su productoId en el arreglo de productos
    // Cuando lo encuentre lo muestra en pantalla con su stock
}

void registrarProducto(deltronXpand& deltronXpand) {
    // Agrega un nuevo producto preguntando al usuario
    // Cuando termine de agregarlo debe de mostrar un menu pidiendo que añada el stock del producto en los almacenes deseados
}

void editarProducto(deltronXpand& deltronXpand) {
}

void editarProductoEnAlmacen(deltronXpand& deltronXpand) {
}

/// <summary>
/// Muestra todos los productos disponibles en stock
/// </summary>
void revisarCatalogo(deltronXpand deltronXpand) {
    int almacenId;
    int clasificacionId;

    // Pregunta almacï¿½n
    almacenId = 1;

    // Pregunta Clasificaciï¿½n
    clasificacionId = 4;

    // Muestra productos que cumplan ese requerimiento


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
                        cout << deltronXpand.productos[j].nombre << endl;
                    }
                }
            }
        }
    }
}

void buscarProductoPorNombre(deltronXpand deltronXpand) {
    int almacenId;
    string terminoDeBusqueda;

    // Pregunta el almacen
    almacenId = 1;

    // Pregunta el termino de busqueda
    terminoDeBusqueda = "3600";

    // Busca el termino de busqueda en el arreglo de productos
    for (int i = 0; i < deltronXpand.productosEnAlmacenCantidad; i++)
    {
        if (deltronXpand.productosEnAlmacen[i].almacenId == almacenId)
        {
            for (int j = 0; j < deltronXpand.productosCantidad; j++)
            {
                if (deltronXpand.productos[j].productoId == deltronXpand.productosEnAlmacen[i].productoId)
                {
                    if (contieneTexto(convertirEnMinusculas(deltronXpand.productos[j].nombre), terminoDeBusqueda))
                    {
                        // Y los muestra en pantalla
                        cout << deltronXpand.productos[j].nombre << endl;
                    }
                }
            }
        }
    }
}

void buscarProductoPorMarca(deltronXpand deltronXpand) {
    // Pregunta el termino de busqueda

    // Busca el termino de busqueda en el arreglo de productos

    // Proceso similar a la funcion buscarProductoPorNombre pero en lugar de comparar el nombre, compara la marca.
}

void crearOrdenDeCompra(deltronXpand& deltronXpand) {
}

void verHistorialDeOrdenes(deltronXpand deltronXpand, string clienteRUC) {
    float parcial;
    int compraNumero = 1;

    // Recorre con un for todo el arreglo de ordenesDeCompra
    // Buscando las compras realizadas por un cliente con el ruc *clienteRUC*

    // Limpia la pantalla
    system("cls");

    // Recorre con un for todo el arreglo de ordenesDeCompra
    for (int i = 0; i < deltronXpand.ordenesDeCompraCantidad; i++)
    {
        if (deltronXpand.ordenesDeCompra[i].clienteRUC == clienteRUC)
        {
            parcial = 0;
            cout << "Compra #" << compraNumero << endl;
            cout << "------------------------------------------------" << endl;

            // Obtener el producto comprado desde sus propiedades originales
            for (int j = 0; j < deltronXpand.productosCompradosCantidad; j++)
            {
                if (deltronXpand.productosComprados[j].ordenDeCompraId == deltronXpand.ordenesDeCompra[i].ordenDeCompraId)
                {
                    // Se agrega el precio del producto al parcial acumulado
                    parcial += deltronXpand.productosComprados[j].precio * deltronXpand.productosComprados[j].cantidad;

                    // Se imprime en pantalla el producto
                    cout << deltronXpand.productosComprados[j].nombre << endl;
                }
            }

            // Muestra el precio total de la compra:
            mostrarPieDePresupuesto(parcial);
            compraNumero++;

            cout << endl;
        }
    }
}

#pragma endregion