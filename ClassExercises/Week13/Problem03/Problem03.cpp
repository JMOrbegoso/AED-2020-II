/* Deseamos guardar los datos de un conjunto de productos de una tienda
Estudiante:
    -Codigo
    -Nombre
    -Edad
    -5 notas
    -Promedio
    -Carrera profesional

Crear una lista enlazada simple.
*/

#include <iostream>
#include <windows.h>
#include "Structs.h"

using namespace std;

void init(listaEstudiantes &estudiantes) {
    estudiantes.cabecera = NULL;
    estudiantes.largo = 0;
}






void registerStudent(studentsList& classroom) {
    studentNode studentNode;

    classroom.first->next = &studentNode;

    classroom.size++;
}

int main()
{
    studentsList classroom;

    initList(classroom);

    int seletectMenuOption;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                registerStudent(classroom);
                Sleep(750);
                break;

            case 2:
                
                system("pause");
                break;

            case 3:
                
                system("pause");
                break;

            case 4:
                
                system("pause");
                break;

            case 5:

                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(seletectMenuOption == 0));

    return 0;
}

int getSeletectOption() {
    int seletectOption;

    system("cls");

    cout << "\tBienvenido al Problema 03" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Registrar estudiante" << endl;
    cout << "[2] Lista de estudiantes" << endl;
    cout << "[3] Buscar estudiante" << endl;
    cout << "[4] Eliminar estudiante" << endl;
    cout << "[5] Ordernar estudiantes" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 5)) {
        cout << "Introdujo una opción incorrecta, por favor seleccione una opción válida:";
        cin >> seletectOption;
    }

    return seletectOption;
}