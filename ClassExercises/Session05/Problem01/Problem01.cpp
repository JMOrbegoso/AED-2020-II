#include <iostream>
#include <windows.h>

using namespace std;

// forward declaration
float requestMoney();

int main()
{
    // Declaración de variables y constantes
    char fullName[100];
    unsigned short workedHoursQuantity;
    float hourlyPay;
    float tax1 = 0;
    float tax2 = 0;
    float grossSalary, netSalary;

    // Entrada de datos

    cout << "BIENVENIDO A LA LICORERÍA" << endl;

    cout << "\tPor favor ingrese el nombre y apellidos completos del trabajador (max. 100 letras):";
    fflush(stdin);
    cin.getline(fullName, 100);

    cout << "\tPor favor la cantidad de horas trabajadas (horas):";
    cin >> workedHoursQuantity;

    cout << "\tPor favor ingrese el pago por hora (S/):";
    hourlyPay = requestMoney();

    cout << "\tPor favor ingrese el primer impuesto (S/):";
    tax1 = requestMoney();

    cout << "\tPor favor ingrese el segundo impuesto (S/):";
    tax2 = requestMoney();

    // Proceso
    system("cls");

    grossSalary = workedHoursQuantity * hourlyPay;
    netSalary = grossSalary - tax1 - tax2;

    // Salida de datos
    cout << "El trabajador " << fullName << "." << endl;
    Sleep(500);
    cout << "Trabajó " << workedHoursQuantity << " horas." << endl;
    Sleep(500);
    cout << "Las que generaron S/ " << grossSalary << "." << endl;
    Sleep(500);
    cout << "Tuvo dos impuestos, el primero de S/ " << tax1 << " y el segundo de S/ " << tax2 << "." << endl;
    Sleep(500);
    cout << "Por lo que le corresponde un salario de S/" << netSalary << "." << endl;

    system("pause");

    return 0;
}

float requestMoney() {
    float moneyValue;

    cin >> moneyValue;

    return moneyValue;
}