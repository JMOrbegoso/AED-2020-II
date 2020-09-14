#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    double valueX; // double para mayor rango
    double valueA; // double para mayor rango
    double valueB; // double para mayor rango
    double valueC; // double para mayor rango
    const unsigned long valueG = 1.5;

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #02" << endl;
    cout << "Resuelto por el grupo #03" << endl;

    cout << "\tPor favor ingrese el valor de la variable 'A':";
    cin >> valueA;

    cout << "\tPor favor ingrese el valor de la variable 'B':";
    cin >> valueB;

    cout << "\tPor favor ingrese el valor de la variable 'C':";
    cin >> valueC;

    // Proceso
    valueX = ((pow(valueB, 2) - (valueC * 3)) / (valueA * valueB + 1)) + valueG - (valueA / valueB);

    // Salida de datos
    cout << "El valor final es: " << endl << "x=" << valueX << endl;

    return 0;
}