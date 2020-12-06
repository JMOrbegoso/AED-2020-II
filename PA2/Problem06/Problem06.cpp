#include <iostream>
#include "Estructuras.h"
#include "Basicas.h"

using namespace std;
void registrarProducto(producto pro[max], int& np);
void mostrarProductos(producto pro[max], int np);
void calcularGanancia(producto pro[max], int np);
void ordenarProductosPorGanancia(producto pro[max], int np);

int main()
{
    producto pro[max];
    int np = 0;  // numero de alumnos
    int opc;
    do {
        opc = menu();
        switch (opc) {
        case 1: registrarProducto(pro, np);
            break;
        case 2: calcularGanancia(pro, np);
            break;
        case 3: ordenarProductosPorGanancia(pro, np);
            break;
        case 4: mostrarProductos(pro, np);
            break;
        }
    } while (!(opc == 4));
    return 0;
}

void registrarProducto(producto pro[max], int& np) {
    system("cls");
    if (np < max) {
        gotoxy(35, 5); pro[np].nombre = leerTexto("Ingrese el nombre del producto:");
        gotoxy(35, 6); pro[np].codigo = leerTexto("Ingrese el nombre del producto:");
        gotoxy(35, 7); pro[np].precioCosto = leerEntero("Ingrese precio de Costo: ");
        gotoxy(35, 7); pro[np].precioVenta = leerEntero("Ingrese precio de venta: ");
        gotoxy(35, 7); pro[np].cantidad = leerEntero("Ingrese la cantidad: ");
        gotoxy(35, 7); pro[np].ganancia = leerEntero("Ingrese la ganancia: ");
        Sleep(2000);
    }
}

void calcularGanancia(producto pro[max], int np) {

    float gananciaTotal = 0;
    for (int i = 0; i < np; i++) {
        pro[i].ganancia = pro[i].cantidad * (pro[i].precioVenta - pro[i].precioCosto);
        gananciaTotal += pro[i].ganancia;
    }

    cout << "El supermercado a ganado en total: S/ " << gananciaTotal << endl;
}

void mostrarProductos(producto est[max], int np) {
    system("cls");
    for (int y = 0; y < np; y++) {
        gotoxy(35, 5); cout << "Nombre del Producto: " << est[y].nombre;
        gotoxy(35, 6); cout << "Codigo del Producto: " << est[y].codigo;
        gotoxy(35, 7); cout << "Precio de costo del Producto  : " << est[y].precioCosto;
        gotoxy(35, 8); cout << "Cantidad del producto  : " << est[y].cantidad;
        gotoxy(35, 9); cout << "Precio de venta del Producto  : " << est[y].precioVenta;
        gotoxy(35, 10); cout << "La Ganancia del Mes es : " << ":" << est[y].ganancia;
        Sleep(1000);
    }
    system("pause");
}

void intercambiar(producto array[max], int i, int j) {

    producto temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}

void ordenar(producto productos[max], int nE) {

    int i, j;
    for (i = 0; i < nE - 1; i++)
    {
        for (j = 0; j < nE - i - 1; j++)
        {
            if (productos[j].ganancia < productos[j + 1].ganancia)
            {
                intercambiar(productos, j, j + 1);
            }
        }
    }
}

void ordenarProductosPorGanancia(producto productos[max], int nE) {

    ordenar(productos, nE);

    mostrarProductos(productos, nE);
}