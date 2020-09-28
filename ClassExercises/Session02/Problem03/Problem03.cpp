#include <iostream>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    char workerFirstName[100];
    char workerLastName[100];

    unsigned short totalWorkedHours;
    unsigned short week1WorkedHours;
    unsigned short week2WorkedHours;
    unsigned short week3WorkedHours;
    unsigned short week4WorkedHours;
    const unsigned short hourlyPayment = 35;
    float anniversaryBonus;
    float contributionDiscount;
    float grossSalary; // Salario bruto
    float netSalary; // Salario neto
    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #03" << endl;
    cout << "Resuelto por el grupo #03" << endl << endl;

    cout << "\tPor favor ingrese el nombre del trabajador (max. 100 caracteres):";
    cin.getline(workerFirstName, 100);

    cout << "\tPor favor ingrese el apellido del trabajador (max. 100 caracteres):";
    cin.getline(workerLastName, 100);

    cout << "\tPor favor ingrese la cantidad de horas trabajadas por " << workerFirstName << " " << workerLastName << " durante la primera semana (horas):";
    cin >> week1WorkedHours;

    cout << "\tPor favor ingrese la cantidad de horas trabajadas por " << workerFirstName << " " << workerLastName << " durante la segunda semana (horas):";
    cin >> week2WorkedHours;

    cout << "\tPor favor ingrese la cantidad de horas trabajadas por " << workerFirstName << " " << workerLastName << " durante la tercera semana (horas):";
    cin >> week3WorkedHours;

    cout << "\tPor favor ingrese la cantidad de horas trabajadas por " << workerFirstName << " " << workerLastName << " durante la cuarta semana (horas):";
    cin >> week4WorkedHours;

    // Proceso
    totalWorkedHours = week1WorkedHours + week2WorkedHours + week3WorkedHours + week4WorkedHours;
    grossSalary = totalWorkedHours * hourlyPayment;
    anniversaryBonus = 18 * grossSalary / 100;
    contributionDiscount = 2.3 * grossSalary / 100;
    netSalary = grossSalary + anniversaryBonus - contributionDiscount;

    // Salida de datos
    cout << "El trabajador " << workerFirstName << " " << workerLastName << " recibira un sueldo de S/ " << netSalary << " por haber trabajado durante " << totalWorkedHours <<
        " horas durante el mes, habiendo recibido una bonificación por aniversario de S/ " << anniversaryBonus << ", y un descuento por aportes de S/ " << contributionDiscount << ".";

    return 0;
}