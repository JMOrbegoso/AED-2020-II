#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
int getSeletectOption();
void generateValueY(float& valueY);
void generateValueZ(float& valueY, float& valueZ);
void showResults(float& valueY, float& valueZ);
int getFactorialValue(int number);
void showCredits();

int main()
{
    unsigned short seletectMenuOption;
    float valueY = 0;
    float valueZ = 0;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                generateValueY(valueY);
                break;

            case 2:
                generateValueZ(valueY, valueZ);
                break;

            case 3:
                showResults(valueY, valueZ);
                break;

            case 4:
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

    cout << "\tBienvenido al Problema 01 de la Práctica Calificada" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Generar el valor de la variable Y" << endl;
    cout << "[2] Generar el valor de la variable Z" << endl;
    cout << "[3] Ver resultados" << endl;
    cout << "[4] Ver Creditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 4)) {
        cout << "Introdujo una opción incorrecta, por favor seleccione una opción válida:";
        cin >> seletectOption;
    }

    return seletectOption;
}

void generateValueY(float& valueY) {
    int numbersQuantity;
    int valueX;
    valueY = 1;

    cout << "---------------GENERADOR DE LA VARIABLE Y---------------" << endl;

    do {
        cout << "Introduzca la cantidad de terminos deseada (mayor o igual que cero):" << endl;
        cin >> numbersQuantity;
    } while (!(numbersQuantity >= 0));

    for (int i = 0; i < numbersQuantity; i++) {
        cout << "Introduzca el valor del X #" << (i + 1) << ":" << endl;
        cin >> valueX;

        valueY += (float)valueX / (float)getFactorialValue(i + 1);
    }

    cout << endl << "El valor de la variable Y es " << valueY << "." << endl;
    Sleep(2000);
}

void generateValueZ(float& valueY, float& valueZ) {
    int numbersQuantity;
    int valueX;
    valueZ = 1;

    if (valueY == 0) {
        cout << "No puede proceder, primero debe de generar el valor de la variable Y." << endl;
        Sleep(2000);
        return;
    }

    cout << "---------------GENERADOR DE LA VARIABLE Z---------------" << endl;

    do {
        cout << "Introduzca la cantidad de terminos deseada (mayor o igual que cero):" << endl;
        cin >> numbersQuantity;
    } while (!(numbersQuantity >= 0));

    for (int i = 0; i < numbersQuantity; i++) {
        cout << "Introduzca el valor del X #" << (i + 1) << ":" << endl;
        cin >> valueX;

        valueZ += (float)valueX / (float)valueY;
    }

    cout << endl << "El valor de la variable Z es " << valueZ << "." << endl;
    Sleep(2000);
}

void showResults(float& valueY, float& valueZ) {
    cout << "-------------RESULTADOS-------------" << endl;
    cout << "Variable Y: " << valueY << "." << endl;
    cout << "Variable Z: " << valueZ << "." << endl;
    cout << endl << "Valor de (Y+Z)/2:" << endl;
    Sleep(500);
    cout << "(" << valueY << " + " << valueZ << ")/2" << endl;
    Sleep(500);
    cout << "(" << (valueY + valueZ) << ")/2" << endl;
    Sleep(500);
    cout << (valueY + valueZ) / 2 << endl;

    system("pause");
}

int getFactorialValue(int number) {
    int factorialValue = 1;

    for (int i = 1; i <= number; i++) {
        factorialValue = factorialValue * i;
    }

    return factorialValue;
}

void showCredits() {
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;

    system("pause");
}