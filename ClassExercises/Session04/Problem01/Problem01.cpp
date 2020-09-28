#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    unsigned short age;
    float price, accumulatedTotal, amountPrize;
    const float priceRange1 = 5;
    const float priceRange2 = 7;
    const float priceRange3 = 10;
    float accumulatedRange1 = 0;
    float accumulatedRange2 = 0;
    float accumulatedRange3 = 0;
    char lol;

    // Entrada de datos
    cout << "\tPor favor la edad del cliente (años):";
    cin >> age;

    // Proceso
    system("cls");

    if (18 <= age && age < 20) {
        price = priceRange1;
        accumulatedRange1 = accumulatedRange1 + priceRange1;
    }
    else if (20 <= age && age < 30) {
        price = priceRange2;
        accumulatedRange2 = accumulatedRange2 + priceRange2;
    }
    else if (30 <= age) {
        price = priceRange3;
        accumulatedRange3 = accumulatedRange3 + priceRange3;
    }
    else {
        cout << "El cliente debe ser mayor de edad." << endl;
        price = 0;
    }

    if (price != 0) {
        cout << "El cliente deberá de pagar S/" << price << "." << endl;
    }

    accumulatedTotal = accumulatedRange1 + accumulatedRange2 + accumulatedRange3;
    amountPrize = accumulatedTotal * 75 / 100;

    // Salida de datos
    cout << "Ha recaudado S/" << accumulatedRange1 << " de los clientes el rango de 18 a 20 años." << endl;
    Sleep(1000);
    cout << "Ha recaudado S/" << accumulatedRange2 << " de los clientes el rango de 20 a 30 años." << endl;
    Sleep(1000);
    cout << "Ha recaudado S/" << accumulatedRange3 << " de los clientes mayores de 30 años." << endl;
    Sleep(1000);
    cout << "La recaudación total a sido de S/" << accumulatedTotal << "." << endl;
    Sleep(1000);
    cout << "El premio del 75% de lo recaudado es de S/" << amountPrize << "." << endl;

    system("pause");

    return 0;
}