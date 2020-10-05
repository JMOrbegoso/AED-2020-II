#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
unsigned short requestWorkedHoursQuantity();
float requestHourlyPay();
float requestTax1();
float requestTax2();

int main()
{
    // Declaración de variables y constantes
    unsigned short workedHoursQuantity;
    float hourlyPay;
    float tax1 = 0;
    float tax2 = 0;
    float grossSalary, netSalary;

    // Entrada de datos

    cout << "CALCULADOR DE SUELDO" << endl;

    workedHoursQuantity = requestWorkedHoursQuantity();
    hourlyPay = requestHourlyPay();
    tax1 = requestTax1();
    tax2 = requestTax2();

    // Proceso
    system("cls");

    grossSalary = workedHoursQuantity * hourlyPay;
    netSalary = grossSalary - tax1 - tax2;

    // Salida de datos
    cout << "El empleado trabajó " << workedHoursQuantity << " horas." << endl;
    Sleep(500);
    cout << "Las que generaron S/ " << grossSalary << "." << endl;
    Sleep(500);
    cout << "Tuvo dos impuestos, el primero de S/ " << tax1 << " y el segundo de S/ " << tax2 << "." << endl;
    Sleep(500);
    cout << "Por lo que le corresponde un salario de S/" << netSalary << "." << endl;

    system("pause");

    return 0;
}

/// <summary>
/// Request the user to enter a worked hours quantity
/// </summary>
unsigned short requestWorkedHoursQuantity() {
    unsigned short workedHoursQuantity;

    cout << "\tPor favor la cantidad de horas trabajadas (horas):";

    cin >> workedHoursQuantity;

    return workedHoursQuantity;
}

/// <summary>
/// Request the user to enter a hourly pay value
/// </summary>
float requestHourlyPay() {
    float hourlyPay;

    cout << "\tPor favor ingrese el pago por hora (S/):";
    cin >> hourlyPay;

    return hourlyPay;
}

/// <summary>
/// Request the user to enter the first tax
/// </summary>
float requestTax1() {
    float tax;

    cout << "\tPor favor ingrese el primer impuesto (S/):";
    cin >> tax;

    return tax;
}

/// <summary>
/// Request the user to enter the second tax
/// </summary>
float requestTax2() {
    float tax;

    cout << "\tPor favor ingrese el segundo impuesto (S/):";
    cin >> tax;

    return tax;
}