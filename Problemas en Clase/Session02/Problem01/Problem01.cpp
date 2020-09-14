#include <iostream>

using namespace std;

int main()
{
    // Declaración de variables
    double finalVelocity; // double para mayor rango
    double initialVelocity; // double para mayor rango
    double acceleration; // double para mayor rango
    unsigned long elapsedTime;

    // Entrada de datos

    cout << "Bienvenido" << endl;

    cout << "\tPor favor ingrese la velocidad inicial (m/s):";
    cin >> initialVelocity;

    cout << "\tPor favor ingrese la aceleración (m/s2):";
    cin >> acceleration;

    cout << "\tPor favor ingrese el tiempo (s):";
    cin >> elapsedTime;

    // Proceso
    finalVelocity = initialVelocity + acceleration * elapsedTime;

    // Salida de datos
    cout << "La velocidad final es de : " << finalVelocity << " (m/s)." << endl;

    return 0;
}