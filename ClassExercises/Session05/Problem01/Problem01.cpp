#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
unsigned short requestWorkedHoursQuantity();
float requestHourlyPay();
float requestTax(bool firstTax);
float getGrossSalary(unsigned short workedHoursQuantity, float hourlyPay);
float getNetSalary(float grossSalary, float tax1, float tax2);
void showResults(unsigned short workedHoursQuantity, float grossSalary, float tax1, float tax2, float netSalary);

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
    tax1 = requestTax(true);
    tax2 = requestTax(false);

    // Proceso
    system("cls");

    grossSalary = getGrossSalary(workedHoursQuantity, hourlyPay);
    netSalary = getNetSalary(grossSalary, tax1, tax2);

    // Salida de datos
    showResults(workedHoursQuantity, grossSalary, tax1, tax2, netSalary);

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
/// Request the user to enter the tax
/// </summary>
/// <param name="firstTax">True if is the first Tax, or False if is the second</param>
float requestTax(bool firstTax) {
    float tax;

    if (firstTax) {
        cout << "\tPor favor ingrese el primer impuesto (S/):";
    }
    else {
        cout << "\tPor favor ingrese el segundo impuesto (S/):";
    }

    cin >> tax;

    return tax;
}

float getGrossSalary(unsigned short workedHoursQuantity, float hourlyPay) {
    return workedHoursQuantity * hourlyPay;
}

float getNetSalary(float grossSalary, float tax1, float tax2) {
    return grossSalary - tax1 - tax2;
}

void showResults(unsigned short workedHoursQuantity, float grossSalary, float tax1, float tax2, float netSalary) {
    cout << "El empleado trabajó " << workedHoursQuantity << " horas." << endl;
    Sleep(500);
    cout << "Las que generaron S/ " << grossSalary << "." << endl;
    Sleep(500);
    cout << "Tuvo dos impuestos, el primero de S/ " << tax1 << " y el segundo de S/ " << tax2 << "." << endl;
    Sleep(500);
    cout << "Por lo que le corresponde un salario de S/" << netSalary << "." << endl;
}