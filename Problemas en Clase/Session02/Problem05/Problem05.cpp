#include <iostream>

using namespace std;

int main()
{
    // Declaraci�n de variables y constantes
    float housingPolicyLawDiscount;
    float socialSecurityDiscount;
    float safeForcedStopDiscount;
    float savingsBankDiscount;
    float grossSalary; // Salario bruto
    float netSalary; // Salario neto
    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #05" << endl;
    cout << "Resuelto por el grupo #03" << endl << endl;

    cout << "\tPor favor ingrese el salario base del trabajador (S/):";
    cin >> grossSalary;

    // Proceso
    housingPolicyLawDiscount = 2 * grossSalary / 100;
    socialSecurityDiscount = 2.7 * grossSalary / 100;
    safeForcedStopDiscount = 1.5 * grossSalary / 100;
    savingsBankDiscount = 5 * grossSalary / 100;

    netSalary = grossSalary - housingPolicyLawDiscount - socialSecurityDiscount - safeForcedStopDiscount - savingsBankDiscount;

    // Salida de datos
    cout << "El trabajador recibir� un salario de S/ " << netSalary << ", luego de haber sido descontado S/ " << housingPolicyLawDiscount << " de la ley de pol�tica habitacional, S/ " << socialSecurityDiscount << " de seguro social, S/ " << safeForcedStopDiscount << " de seguro de paro forzoso, y S/ " << savingsBankDiscount << " de caja de ahorro.";

    return 0;
}