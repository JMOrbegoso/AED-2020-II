#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    double valueM;
    double valueN;
    double valueA;
    const double valueB = 9;
    double valueC;
    double finalAverage;

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #07" << endl;
    cout << "Resuelto por el grupo #03" << endl;

    cout << "\tPor favor ingrese el valor de la variable 'A':";
    cin >> valueA;

    cout << "\tPor favor ingrese el valor de la variable 'C':";
    cin >> valueC;

    // Proceso
    valueM = -(pow((((valueB - valueA) * valueC) / (valueB + 1 + valueA)), 2) / pow((pow(valueB, 2) + valueC), 3));

    valueN = pow((valueA * valueB - 5 * valueC) / (pow(valueB * valueC, 2)), 2);

    finalAverage = (valueM + valueN) / 2;

    // Salida de datos
    cout << "El valor de M es " << valueM << ", el valor de N es " << valueN << ", y su promedio es de " << finalAverage << ".";

    return 0;
}