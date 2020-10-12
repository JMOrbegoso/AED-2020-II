#include <iostream>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    char firstName[100];
    unsigned short age;
    float price;

    // Entrada de datos

    cout << "\tPor favor ingrese el nombre de la persona (max. 100 caracteres) : ";
    fflush(stdin);
    cin.getline(firstName, 100);

    cout << "\tPor favor ingrese la edad de la persona (años):";
    cin >> age;

    // Proceso
    system("cls");

    if (age < 5) {
        price = 5;
    }
    else if (age >= 5 && age < 10) {
        price = 10;
    }
    else if (age >= 10 && age < 18) {
        price = 15;
    }
    else if (age >= 18) {
        price = 20;
    }

    // Salida de datos
    cout << "El cliente " << firstName << " pagará para la entrada es de S/ " << price << "." << endl;

    system("pause");

    return 0;
}