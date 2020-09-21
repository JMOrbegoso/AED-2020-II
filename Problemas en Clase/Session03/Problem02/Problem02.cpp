#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    char firstName[100];
    char lastName[100];
    unsigned short age;
    float score1;
    float score2;
    float score3;
    float average;

    // Entrada de datos

    cout << "\tPor favor ingrese el nombre del alumno (max. 100 caracteres): ";
    fflush(stdin);
    cin.getline(firstName, 100);

    cout << "\tPor favor ingrese el apellido del alumno (max. 100 caracteres): ";
    fflush(stdin);
    cin.getline(lastName, 100);

    cout << "\tPor favor ingrese la edad del alumno (años):";
    cin >> age;

    cout << "\tPor favor ingrese la nota del alumno en la practica 1:";
    cin >> score1;

    cout << "\tPor favor ingrese la nota del alumno en la practica 2:";
    cin >> score2;

    cout << "\tPor favor ingrese la nota del alumno en la practica 3:";
    cin >> score3;

    // Proceso
    system("cls");

    if (score1 > score2) {
        // Nota 1 es mayor a Nota 2
        if (score2 > score3) {
            // Nota 2 es mayor a Nota 3
            // La menor nota es Nota 3
            average = (score1 + score2) / 2;
        }
        else {
            // Nota 3 es mayor a Nota 2
            // La menor nota es Nota 2
            average = (score1 + score3) / 2;
        }
    }
    else {
        // Nota 2 es mayor a Nota 1
        if (score1 > score3) {
            // Nota 1 es mayor a Nota 3
            // La menor nota es Nota 3
            average = (score1 + score2) / 2;
        }
        else {
            // Nota 3 es mayor a Nota 1
            // La menor nota es Nota 1
            average = (score2 + score3) / 2;
        }
    }

    if (age < 18) {
        average = average + 1;
    }
    else if (20 <= age) {
        if (average < 19) {
            average = average + 0.5;
        }
    }

    // Salida de datos
    cout << "Reporte del estudiante: " << firstName << " " << lastName << endl;

    Sleep(1000);

    cout << "Tiene " << age << " años." << endl;
    cout << "Obtubo " << score1 << " en su primera practica." << endl;
    cout << "Obtubo " << score2 << " en su segunda practica." << endl;
    cout << "Obtubo " << score3 << " en su tercera practica." << endl;

    Sleep(1000);

    cout << "Obtubo " << average << " en promedio." << endl;

    system("pause");

    return 0;
}