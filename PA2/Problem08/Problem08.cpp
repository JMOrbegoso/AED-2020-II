/*
Una clínica guarda los nombres de sus pacientes, su DNI, su edad, la especialidad en que se atiende
(medicina general, otorrinolaringología, pediatría, oftalmología, etc.). Además, el pago que realiza.

Se debe:
    - Ordena la lista de acuerdo al pago en forma descendente
    - Buscar un paciente
    - Mostrar el total del pago
*/

#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
int getSeletectOption();
void showProblem();
void showCredits();

int main()
{
    unsigned short seletectMenuOption;
    int patientsQuantity = 0;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:

                Sleep(500);
                break;

            case 2:

                Sleep(1000);
                break;

            case 3:

                Sleep(2000);
                break;

            case 4:

                Sleep(2000);
                break;

            case 5:
                showProblem();
                Sleep(3000);
                break;

            case 6:
                showCredits();
                Sleep(3000);
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

    cout << "\tBienvenido al Problema 08" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Registrar paciente" << endl;
    cout << "[2] Ordenar lista de pacientes de acuerdo al pago en forma descendente" << endl;
    cout << "[3] Buscar un paciente" << endl;
    cout << "[4] Ver el total de pagos" << endl;
    cout << "[5] Ver planteamiento del problema" << endl;
    cout << "[6] Ver Creditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 6)) {
        cout << "Introdujo una opción incorrecta, por favor seleccione una opción válida:";
        cin >> seletectOption;
    }

    return seletectOption;
}

void showProblem() {
    cout << "Una clínica guarda los nombres de sus pacientes, su DNI, su edad, el pago que realiza y la especialidad en que se atiende" << endl;
    cout << "(medicina general, otorrinolaringología, pediatría, oftalmología, etc.)." << endl;
    cout << "Se debe:" << endl;
    cout << "\t-> Ordena la lista de acuerdo al pago en forma descendente." << endl;
    cout << "\t-> Buscar un paciente." << endl;
    cout << "\t-> Mostrar el total del pago." << endl;
}

void showCredits() {
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
}