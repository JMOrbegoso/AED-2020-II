#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

// Forward declaration: Informa al compilador que la función existe
unsigned short getChange(unsigned short amount, unsigned short unitChangeValue, bool isBill);

int main()
{
    // Declaración de variables y constantes
    unsigned short originalAmount, amount;

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #08" << endl;
    cout << "Resuelto por el grupo #03" << endl;

    cout << "Por favor ingrese el monto entero de dinero (S/):";
    cin >> originalAmount;

    // Proceso

    // Se limpia la pantalla
    system("cls");

    cout << "El cambio de S/" << originalAmount << " es de:" << endl;

    amount = originalAmount;
    amount = getChange(amount, 200, true);
    amount = getChange(amount, 100, true);
    amount = getChange(amount, 50, true);
    amount = getChange(amount, 20, true);
    amount = getChange(amount, 10, true);
    amount = getChange(amount, 5, false);
    amount = getChange(amount, 2, false);
    amount = getChange(amount, 1, false);

    system("pause");

    return 0;
}

/// <summary>
/// Recibe el monto de dinero, el valor de la moneda unidad de cambio, imprime en pantalla la cantidad de unidades del cambio y retorna el remanente
/// </summary>
/// <param name="amount">Monto de dinero</param>
/// <param name="moneyValue">Valor de la unidad de cambio</param>
/// <param name="isBill">True si es billete, False si es moneda</param>
/// <returns>Remanente</returns>
unsigned short getChange(unsigned short amount, unsigned short unitChangeValue, bool isBill) {
    // Declaración de las variables
    div_t divResult;
    unsigned short bills;

    // Proceso
    divResult = div(amount, unitChangeValue);

    bills = divResult.quot; // quotient (cociente)

    Sleep(500);

    if (bills != 0) {
        cout << "\t" << bills;

        if (bills == 1) {
            if (isBill) {
                cout << " billete de S/";
            }
            else {
                cout << " moneda de S/";
            }
        }
        else {
            if (isBill) {
                cout << " billetes de S/";
            }
            else {
                cout << " monedas de S/";
            }
        }

        cout << unitChangeValue << "." << endl;
    }

    return divResult.rem; // Retorna el remanente de la división;
}