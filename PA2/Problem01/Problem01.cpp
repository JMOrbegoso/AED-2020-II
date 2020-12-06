#include <iostream>
#include "Estructuras.h"

using namespace std;

void inicializar(equipo equipos[max], int& nE);
void registrarEquipo(equipo equipos[max], int& nE);
void buscarEquipo(equipo equipos[max], int nE);
void mostrarEquipo(equipo equipos[max], int nE);
void ordenarEquipos(equipo equipos[max], int nE);

int main()
{
    equipo equipos[max];

    int nE = 0;  // numero de equipos

    inicializar(equipos, nE);

    int opc;
    do {
        opc = menu();
        switch (opc) {
        case 1:
            registrarEquipo(equipos, nE);
            break;
        case 2:
            buscarEquipo(equipos, nE);
            system("pause"); // <--- Pausa la ejecución
            break;
        case 3:
            mostrarEquipo(equipos, nE);
            break;
        case 4:
            ordenarEquipos(equipos, nE);
            break;
        }
    } while (!(opc == 5));
    return 0;
}

void inicializar(equipo equipos[max], int& nE) {
    equipos[0].nombre = "Alianza Lima";
    equipos[0].ciudad = "Lima";
    equipos[0].estadio = "Lima 1";
    equipos[0].puntaje = 5;

    equipos[1].nombre = "Crystal";
    equipos[1].ciudad = "Lima";
    equipos[1].estadio = "Lima 2";
    equipos[1].puntaje = 10;

    equipos[2].nombre = "Universitario";
    equipos[2].ciudad = "Lima";
    equipos[2].estadio = "Lima 3";
    equipos[2].puntaje = 20;

    nE = 3;
}

void registrarEquipo(equipo equipos[max], int& nE) {
    system("cls");

    if (nE < max) {
        gotoxy(35, 5); equipos[nE].nombre = leerTexto("Ingrese el nombre:", 3);
        gotoxy(35, 6); equipos[nE].ciudad = leerTexto("Ingrese ciudad: ", 3);
        gotoxy(35, 7); equipos[nE].estadio = leerTexto("Ingrese estadio: ", 3);
        gotoxy(35, 8); equipos[nE].puntaje = leerEntero("Ingrese puntaje ", 0);
        nE++;
    }
    else {
        gotoxy(35, 10); cout << "Equipos de participantes completo";
        Sleep(2000);
    }
}

bool encontroTexto(string base, string terminoDeBusqueda) {
    if (base.find(terminoDeBusqueda, 0) != string::npos) {
        return true;
    }
    return false;
}

void buscarEquipo(equipo equipos[max], int nE) {
    int similares = 0;

    system("cls");

    string terminoDeBusqueda;
    terminoDeBusqueda = leerTexto("Ingrese el nombre del equipo a buscar", 3);

    for (int i = 0; i < nE; i++) {
        if (encontroTexto(equipos[i].nombre, terminoDeBusqueda))
        {
            cout << equipos[i].nombre << "puntaje: " << equipos[i].puntaje;
            similares++;
        }
    }

    if (similares == 0) {
        cout << "No se encontró ninguno.";
    }
}

void mostrarEquipo(equipo equipos[max], int nE) {
    system("cls");
    int fila = 0;
    for (int y = 0; y < nE; y++)
    {
        gotoxy(5, 5 + fila); cout << "Nombre  : " << equipos[y].nombre;
        gotoxy(25, 5 + fila); cout << "Ciudad : " << equipos[y].ciudad;
        gotoxy(45, 5 + fila); cout << "Estadio : " << equipos[y].estadio;
        gotoxy(65, 5 + fila); cout << "Puntaje :" << equipos[y].puntaje;
        fila++;
        Sleep(500);
    }
    system("pause");
}

void intercambiar(equipo* array, int i, int j) {

    equipo temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}

void ordenar(equipo equipos[max], int nE) {

    int i, j;
    for (i = 0; i < nE - 1; i++)
    {
        for (j = 0; j < nE - i - 1; j++)
        {
            if (equipos[j].puntaje < equipos[j + 1].puntaje)
            {
                intercambiar(equipos, j, j + 1);
            }
        }
    }
}

void ordenarEquipos(equipo equipos[max], int nE) {

    // 1. Ordenarlos segun puntaje
    ordenar(equipos, nE);

    // 2. Mostrarlos en pantalla
    mostrarEquipo(equipos, nE);
}