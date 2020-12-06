#include <iostream>
#include "Estructuras.h"

using namespace std;

void registrarEstudiantes(estudiantes est[max], int& ne);
void mostrarEstudiantes(estudiantes est[max], int ne);
void calcularPromedios(estudiantes est[max], int ne);
void ordenarEstudiantes(estudiantes est[max], int ne);

int main()
{
    estudiantes est[max];
    int ne = 0;  // numero de alumnos
    int opc;
    do {
        opc = menu();
        switch (opc) {
        case 1: registrarEstudiantes(est, ne);
            break;
        case 2: mostrarEstudiantes(est, ne);
            break;
        case 3: ordenarEstudiantes(est, ne);
            break;
        case 4: calcularPromedios(est, ne);
            break;
        }
    } while (!(opc == 4));
    return 0;
}


void registrarEstudiantes(estudiantes est[max], int& ne) {
    system("cls");
    if (ne < max) {
        gotoxy(35, 5); est[ne].codigo = leerTexto("Ingrese el codigo:");
        gotoxy(35, 6); est[ne].apellidos = leerTexto("Ingrese apellidos: ");
        gotoxy(35, 7); est[ne].nombres = leerTexto("Ingrese nombres: ");
        for (int x = 0; x < maxPracticas; x++) {
            gotoxy(35, 8 + x); est[ne].notaspracticas[x] = leerEntero("Ingrese nota de Practica: ", x + 1);

        }
        for (int x = 0; x < maxExamenes; x++) {
            gotoxy(35, 8 + x); est[ne].notasexamenes[x] = leerEntero("Ingrese nota de Examen: ", x + 1);

        }
        ne++;
    }
    else {
        gotoxy(35, 10); cout << "Datos llenos";
        Sleep(2000);
    }
}

void mostrarEstudiantes(estudiantes est[max], int ne) {
    system("cls");
    for (int y = 0; y < ne; y++) {
        gotoxy(35, 5); cout << "Codigo   : " << est[y].codigo;
        gotoxy(35, 6); cout << "Apellidos: " << est[y].apellidos;
        gotoxy(35, 7); cout << "Nombres  : " << est[y].nombres;
        gotoxy(35, 8); cout << "Promedio  : " << est[y].promFinal;
        for (int x = 0; x < maxPracticas; x++) {
            gotoxy(35, 9 + x); cout << "Nota de Practica " << x + 1 << ":" << est[y].notaspracticas[x];
        }
        for (int x = 0; x < maxExamenes; x++) {
            gotoxy(35, 10 + x); cout << "Nota de Examenes " << x + 1 << ":" << est[y].notasexamenes[x];
        }
        Sleep(2000);
    }
    system("pause");
}

void calcularPromedios(estudiantes est[max], int ne) {
    float suma = 0;
    float suma2 = 0;
    for (int y = 0; y < ne; y++) {
        suma = 0;
        suma2 = 0;
        for (int x = 0; x < maxPracticas; x++) {
            suma += est[y].notaspracticas[x];
        }
        for (int x = 0; x < maxPracticas; x++) {
            suma2 += (est[y].notasexamenes[x] * 2);
        }
        est[y].promFinal = (suma + suma2) / maxNotas;
    }
}

void intercambiar(estudiantes* array, int i, int j) {

    estudiantes temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}

void ordenarEstudiantes(estudiantes est[max], int estudiantesCantidad) {

    int i, j;
    for (i = 0; i < estudiantesCantidad - 1; i++)
    {
        for (j = 0; j < estudiantesCantidad - i - 1; j++)
        {
            if (est[j].promFinal < est[j + 1].promFinal)
            {
                intercambiar(est, j, j + 1);
            }
        }
    }
}