/*
Leer un conjunto de numeros:
    -Ordenar
    -Buscar un numero
    -Hallar el promedio
*/

#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
int getSeletectOption();
void requestNumber(float* numbers, int& numbersQuantity);
void showNumbers(float* numbers, int numbersQuantity);
void sortNumbers(float* numbers, int n);
void findNumber(float* numbers, int numbersQuantity);
void showAverage(float* numbers, int numbersQuantity);
void showProblem();
void showCredits();

int main()
{
    unsigned short seletectMenuOption;
    float numbers[20];
    int numbersQuantity = 0;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                requestNumber(numbers, numbersQuantity);
                Sleep(500);
                break;

            case 2:
                showNumbers(numbers, numbersQuantity);
                Sleep(2000);
                break;

            case 3:
                sortNumbers(numbers, numbersQuantity);
                Sleep(1000);
                break;

            case 4:
                findNumber(numbers, numbersQuantity);
                Sleep(2000);
                break;

            case 5:
                showAverage(numbers, numbersQuantity);
                Sleep(2000);
                break;

            case 6:
                showProblem();
                Sleep(3000);
                break;

            case 7:
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

    cout << "\tBienvenido al Problema 01" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Ingresar n�mero" << endl;
    cout << "[2] Mostrar n�meros" << endl;
    cout << "[3] Ordenar" << endl;
    cout << "[4] Buscar un n�mero" << endl;
    cout << "[5] Calcular el promedio" << endl;
    cout << "[6] Ver planteamiento del problema" << endl;
    cout << "[7] Ver Creditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opci�n deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 7)) {
        cout << "Introdujo una opci�n incorrecta, por favor seleccione una opci�n v�lida:";
        cin >> seletectOption;
    }

    return seletectOption;
}

void requestNumber(float* numbers, int& numbersQuantity) {
    float enteredNumber;

    if (numbersQuantity >= 20) {
        cout << "\tYa no puede seguir ingresando m�s n�meros." << endl;
        return;
    }

    cout << "Ingrese un n�mero:" << endl;
    cin >> enteredNumber;

    numbers[numbersQuantity] = enteredNumber;
    numbersQuantity++;

    cout << "Registrado exitosamente." << endl;
}

void showNumbers(float* numbers, int numbersQuantity) {
    cout << "Los n�meros ingresados son:" << endl;

    for (int i = 0; i < numbersQuantity; i++) {
        cout << "\t" << numbers[i] << endl;
    }
}

void sortNumbers(float* numbers, int n) {
    float temp;
    int j = 0;

    for (int i = 0; j < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (numbers[i] > numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    cout << "Ordenamiento terminado." << endl;
}

void findNumber(float* numbers, int numbersQuantity) {
    float numberToFind;
    bool found = false;
    int index;

    cout << "Ingrese el n�mero que desea buscar:" << endl;
    cin >> numberToFind;

    for (int i = 0; !found && i < numbersQuantity; i++) {
        if (numbers[i] == numberToFind) {
            found = true;
            index = i;
        }
    }

    if (found) {
        cout << "El n�mero buscado fue encontrado en el indice: " << index << endl;
    }
    else {
        cout << "El n�mero buscado no fue encontrado." << endl;
    }
}

void showAverage(float* numbers, int numbersQuantity) {
    float sum = 0;
    float average;

    for (int i = 0; i < numbersQuantity; i++) {
        sum += numbers[i];
    }

    average = sum / numbersQuantity;

    cout << "El promedio es: " << average << endl;
}

void showProblem() {
    cout << "Leer un conjunto de numeros:" << endl;
    cout << "\t-> Ordenar." << endl;
    cout << "\t-> Buscar un n�mero." << endl;
    cout << "\t-> Hallar el promedio." << endl;
    cout << "\t-> Mostrar cuantos son menores y mayores de edad." << endl;
}

void showCredits() {
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
}