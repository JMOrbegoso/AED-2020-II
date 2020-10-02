//Una empresa paga a sus empleados adem�s del sueldo base una bonificaci�n especial por cada hijo(no
//    m�s de 3) y a la edad de los hijos.Realice un algoritmo que permita ingresar el nombre del empleado y
//    calcule el monto de la bonificaci�n y el monto total a pagar al trabajador.Si se sabe que :
//-Si el hijo tiene entre menos de 1 a�o se le da una bonificaci�n de S / . 180
//- Si el hijo tiene 1 a�o y menos de 5 la bonificaci�n es de S / . 160
//- Si el hijo tiene menos de 5 hasta 8 la bonificaci�n es de S / . 140
//- Si el hijo tiene m�s de 8 hasta 10 la bonificaci�n es de S / . 120
//- Los mayores o iguales a 10 a�os no tienen bonificaci�n
//- Si el padre tiene m�s de 3 hijos no hay bonificaci�n alguna
//Se debe reportar el nombre del empleado, los nombres y edades de los hijos y el monto de bonificaci�n y
//monto total a pagar.

#include <iostream>
#include <windows.h>

using namespace std;

//// Forward declaration: Informa al compilador que la funci�n existe
float getBonus(short childAge);

int main()
{
    // Declaraci�n de variables y constantes
    char employeeFullName[100];
    float salaryBase, netSalary;
    float bonus = 0;
    unsigned short childrensQuantity;
    short child1Age = -1, child2Age = -1, child3Age = -1;

    // Entrada de datos

    cout << "BIENVENIDO AL SISTEMA DE PAGO DE SALARIOS DE LA EMPRESA" << endl;

    cout << "\tPor favor ingrese los nombres y apellidos completos del cliente (max. 100 letras):";
    fflush(stdin);
    cin.getline(employeeFullName, 100);

    cout << "\tPor favor ingrese el salario base del empleado:";
    cin >> salaryBase;

    cout << "\tPor favor ingrese el numero de hijos del empleado:";
    cin >> childrensQuantity;

    // Proceso
    system("cls"); // Limpia la pantalla de la consola

    switch (childrensQuantity)
    {
    case 1:
        cout << "\t�Cu�l es la edad de su primer hijo?:";
        cin >> child1Age;
        break;

    case 2:
        cout << "\t�Cu�l es la edad de su primer hijo?:";
        cin >> child1Age;
        cout << "\t�Cu�l es la edad de su segundo hijo?:";
        cin >> child2Age;

        break;

    case 3:
        cout << "\t�Cu�l es la edad de su primer hijo?:";
        cin >> child1Age;
        cout << "\t�Cu�l es la edad de su segundo hijo?:";
        cin >> child2Age;
        cout << "\t�Cu�l es la edad de su tercer hijo?:";
        cin >> child3Age;

        break;

    case 0:
    default:
        break;
    }

    bonus = bonus + getBonus(child1Age);
    bonus = bonus + getBonus(child2Age);
    bonus = bonus + getBonus(child3Age);

    netSalary = salaryBase + bonus;

    // Salida de datos
    cout << "El empleado " << employeeFullName << "." << endl;
    Sleep(500);
    cout << "Con un salario base de S/" << salaryBase << endl;
    Sleep(500);
    cout << "Por tener " << childrensQuantity << " hijos" << endl;

    if (0 < childrensQuantity && childrensQuantity < 4) {
        Sleep(500);
        cout << "Con edades de: " << endl;

        if (child1Age != -1) {
            Sleep(500);
            cout << "\t" << child1Age << " a�o/s" << endl;
        }
        if (child2Age != -1) {
            Sleep(500);
            cout << "\t" << child2Age << " a�o/s" << endl;
        }
        if (child3Age != -1) {
            Sleep(500);
            cout << "\t" << child3Age << " a�o/s" << endl;
        }
    }

    Sleep(500);
    cout << "Ha recibido una bonificaci�n de S/ " << bonus << "." << endl;
    Sleep(500);
    cout << "Por lo que su salario neto es de S/" << netSalary << "." << endl;

    system("pause");

    return 0;
}

/// <summary>
/// Get the product type name and copied on the parameter char array.
/// </summary>
float getBonus(short childAge)
{
    if (0 < childAge && childAge < 1) {
        return 180;
    }
    else if (1 < childAge && childAge < 5) {
        return 160;
    }
    else if (5 < childAge && childAge < 8) {
        return 140;
    }
    else if (8 < childAge && childAge < 10) {
        return 120;
    }
    else {
        return 0;
    }
}