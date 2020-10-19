//Elabore un programa que lea 2 números enteros.Validar que no sea iguales no mayores
//que 1000. Luego de ello debe hallar la suma y el promedio de los números comprendidos
//entre ellos.

#include <iostream>

using namespace std;

// Forward declarations
int getSeletectOption();
void requestNumbers(short& firstNumber, short& secondNumber);
void startProcess(short firstNumber, short secondNumber);
void showProblem();
void showCredits();

int main()
{
    unsigned short seletectMenuOption;
    short firstNumber;
    short secondNumber;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                requestNumbers(firstNumber, secondNumber);
                startProcess(firstNumber, secondNumber);
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
    cout << "https://www.jmorbegoso.com" << endl;
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

void requestNumbers(short& firstNumber, short& secondNumber) {

    cout << "Introduzca el primer número entero (menor que 1000):" << endl;
    cin >> firstNumber;
    while (!(firstNumber < 1000)) {
        cout << "Por favor introduzca un número menor que 1000:";
        cin >> firstNumber;
    }

    cout << "Introduzca el segundo número entero (menor que 1000):" << endl;
    cin >> secondNumber;
    while (!(secondNumber < 1000)) {
        cout << "Por favor introduzca un número menor que 1000:";
        cin >> secondNumber;
    }
}

void startProcess(short firstNumber, short secondNumber) {
    short sum = firstNumber + secondNumber;
    short average = sum / 2;

    cout << "La suma de los números ingresados es: " << sum << endl;
    cout << "Y su promedio es de : " << average << endl;
    cout << "-----Fin del Problema------" << endl;
}

void showProblem() {
    cout << "Elabore un programa que lea 2 números enteros." << endl;
    cout << "Validar que no sea iguales no mayores que 1000. " << endl;
    cout << "Luego de ello debe hallar la suma y el promedio de los números comprendidos entre ellos." << endl;
}

void showCredits() {
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com/" << endl;
}