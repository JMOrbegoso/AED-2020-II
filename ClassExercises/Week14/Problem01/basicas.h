#include "estructuras.h"

int getSeletectOption() {
    int seletectOption;

    system("cls");

    cout << "\tBienvenido al Problema 01" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Registrar Estudiante" << endl;
    cout << "[2] Registrar Curso" << endl;
    cout << "[3] Ver Estudiantes" << endl;
    cout << "[4] Ver Cursos" << endl;
    cout << "[5] Ver Cr�ditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opci�n deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 5)) {
        cout << "Introdujo una opci�n incorrecta, por favor seleccione una opci�n v�lida:";
        cin >> seletectOption;
    }

    return seletectOption;
}
