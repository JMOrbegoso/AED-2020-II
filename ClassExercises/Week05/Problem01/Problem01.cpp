#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
unsigned short requestWorkedHoursQuantity();
float requestHourlyPay();
float requestTax(bool firstTax);
float getGrossSalary(unsigned short workedHoursQuantity, float hourlyPay);
float getNetSalary(float grossSalary, float tax1, float tax2);
void showResult(const char firstMessage[], float numericValue, const char lastMessage[]);

float requestFloat(const char* message);
short requestShort(const char* message);
void requestCharArray(const char* message, char* charArray, unsigned short maxLengh);

int main()
{
    char nombre[5];
    float precio;
    short dia;

    requestCharArray("hola", nombre, 5);

    precio = requestFloat("float:");
    dia = requestShort("short:");

    cout << "El nombre es: " << nombre << endl;
    cout << "El precio es: " << precio << endl;
    cout << "El dia es: " << dia << endl;

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

void showResult(const char firstMessage[], float numericValue, const char lastMessage[]) {
    Sleep(500);
    cout << firstMessage << numericValue << lastMessage << endl;
}



float requestFloat(const char* message) {
    float requestedValue;

    cout << "\t" << message << endl;
    cin >> requestedValue;

    return requestedValue;
}

short requestShort(const char* message) {
    short requestedValue;

    cout << "\t" << message << endl;
    cin >> requestedValue;

    return requestedValue;
}

void requestCharArray(const char* message, char* charArray, unsigned short maxLengh) {
    fflush(stdin);
    cout << "\t" << message << " (max. " << maxLengh << " caracteres):" << endl;    
    cin.getline(charArray, maxLengh);
}