#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
int getSeletectOption();
void leerDatos(char nombre[40], char dni[8], float& sueldo);

int main()
{
    unsigned short seletectMenuOption;

    do {

        seletectMenuOption = getSeletectOption();

        cout << "selecionó la opción" << seletectMenuOption;

        Sleep(2000);

    } while (!(seletectMenuOption == 0));

    return 0;
}

int getSeletectOption() {
    int seletectOption;
    char nombre[40];
    char dni[9];
    float sueldo;

    system("cls");
    cout << "1. Entrar" << endl;
    cout << "0. Salir" << endl;

    // do {
    //     cout << "Introduzca la opción deseada:";
    //    cin >> seletectOption;
    //  } while (!(0 <= seletectOption && seletectOption <= 5));

    leerDatos(nombre, dni, sueldo);

    cout << "Introduzca la opción deseada:";
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 5)) {
        cout << "Introdujo un valor incorrecto, por favor seleccione una opción válida:";
        cin >> seletectOption;
    }

    return 0;
}

void leerDatos(char nombre[40], char dni[9], float& sueldo) {

    system("cls");

    cout << "Ingrese nombre:";
    fflush(stdin);
    cin.getline(nombre, 40);

    cout << "Ingrese DNI:";
    fflush(stdin);
    cin.getline(dni, 9);

    cout << "Ingrese sueldo:";
    cin >> sueldo;
}