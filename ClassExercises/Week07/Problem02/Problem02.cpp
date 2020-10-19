//Elabore un programa que lea 2 números enteros.Validar que no sea iguales no mayores
//que 1000. Luego de ello debe hallar la suma y el promedio de los números comprendidos
//entre ellos.

#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
int getSeletectOption();
void startProcess();
void showProblem();
void showCredits();

int main()
{
    unsigned short seletectMenuOption;

    do {
        seletectMenuOption = getSeletectOption();

        cout << "selecionó la opción" << seletectMenuOption << endl;
        Sleep(2000);

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                void startProcess();
                break;

            case 2:
                showProblem();
                break;

            case 3:
                showCredits();
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

    cout << "\tBienvenido al Problema 02" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com/" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Empezar" << endl;
    cout << "[2] Ver planteamiento del problema" << endl;
    cout << "[3] Ver Creditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 3)) {
        cout << "Introdujo una opción incorrecta, por favor seleccione una opción válida:";
        cin >> seletectOption;
    }

    return 0;
}

void startProcess() {

}

void showProblem() {
    cout << "Elabore un programa que lea 2 números enteros.Validar que no sea iguales no mayores que 1000. Luego de ello debe hallar la suma y el promedio de los números comprendidos entre ellos." << endl;
}

void showCredits() {
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com/" << endl;
}