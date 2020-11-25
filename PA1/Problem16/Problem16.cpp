#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    char firstName[100];
    char lastName[100];
    unsigned short chosenNumber;
    float originalAmount, netAmount;
    float discount = 0;

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #16" << endl;
    cout << "Resuelto por el grupo #03" << endl << endl << endl;

    cout << "Por favor ingrese el nombre del cliente (max. 100 caracteres): ";
    fflush(stdin);
    cin.getline(firstName, 100);

    cout << "Por favor ingrese el apellido del cliente (max. 100 caracteres): ";
    fflush(stdin);
    cin.getline(lastName, 100);

    cout << "Por favor ingrese el monto original de la compra (S/):";
    cin >> originalAmount;

    cout << "Por favor ingrese el número elegido por el cliente:";
    cin >> chosenNumber;

    // Proceso

    // Se limpia la pantalla
    system("cls");

    switch (chosenNumber)
    {
    case 1:
    case 3:
        if (originalAmount > 100) {
            discount = 15;
        }
        break;

    case 2:
    case 9:
        discount = 10 * originalAmount / 100;
        break;

    case 4:
    case 7:
        discount = 15 * originalAmount / 100;
        break;

    case 5:
        if (originalAmount < 50) {
            discount = originalAmount;
        }
        break;

    default:
        discount = 0;
        break;
    }

    netAmount = originalAmount - discount;

    // Datos de salida

    cout << "El cliente " << firstName << " " << lastName;
    if (discount == 0) {
        cout << " no ha obtenido ningun descuento";
    }
    else {
        cout << " ha obtenido descuento de S/" << discount;
    }

    Sleep(1000);

    cout << ", y deberá pagar S/" << netAmount << " por su compra.";

    cout << endl;

    system("pause");

    return 0;
}