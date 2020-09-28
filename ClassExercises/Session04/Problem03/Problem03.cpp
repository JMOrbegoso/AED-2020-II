#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    char fullName[100];
    unsigned short day, age; // 0: Lunes, 1: Martes, 2:Miercoles, 3: Jueves, 4: Viernes, 5: Sabado, 6: Domingo
    float grossAmount, igvAmount, netAmount;
    float discount = 0;

    // Entrada de datos

    cout << "BIENVENIDO A LA LICORERÍA" << endl;

    cout << "\tPor favor ingrese su nombre y apellidos completos (max. 100 letras):";
    fflush(stdin);
    cin.getline(fullName, 100);

    cout << "\tPor favor ingrese el día de hoy [0: Lunes, 1: Martes, 2:Miercoles, 3: Jueves, 4: Viernes, 5: Sabado, 6: Domingo]:";
    cin >> day;

    cout << "\tPor favor ingrese el monto bruto de hoy (S/):";
    cin >> grossAmount;

    cout << "\tPor favor ingrese la edad del cliente (años):";
    cin >> age;

    // Proceso
    system("cls");

    if (age < 18) {
        cout << "\tNo se puede realizar la compra por ser menor de edad.";
        return 0;
    }

    switch (day) {
    case 0:
        if (grossAmount > 3000) {
            discount = 5 * grossAmount / 100;
        }
        break;
    case 1:
        if (3000 < grossAmount && grossAmount < 5000) {
            discount = 7 * grossAmount / 100;
        }
        break;
    case 2:
    case 3:
        if (5000 < grossAmount) {
            discount = 8 * grossAmount / 100;
        }
        break;
    case 4:
        if (5000 < grossAmount) {
            discount = 6 * grossAmount / 100;
        }
        break;
    case 5:
    case 6:
        if (2000 < grossAmount) {
            discount = 2 * grossAmount / 100;
        }
        break;

    default:
        cout << "\tEl día no es válido, intente nuevamente.";
        return 0;
        break;
    }

    grossAmount = grossAmount - discount;

    igvAmount = grossAmount * 18 / 100;

    netAmount = grossAmount + igvAmount;

    // Salida de datos
    cout << "El cliente " << fullName << "." << endl;
    Sleep(500);
    cout << "Tiene un descuento de S/ " << discount << "." << endl;
    Sleep(500);
    cout << "Su IGV fue de S/ " << igvAmount << "." << endl;
    Sleep(500);
    cout << "Por lo que debe de pagar S/" << netAmount << "." << endl;

    system("pause");

    return 0;
}