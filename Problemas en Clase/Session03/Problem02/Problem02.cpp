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
    float lowestScore;
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

    lowestScore = score1;
    if (score1 > score2) {
        lowestScore = score2;
    }
    if (score3 > lowestScore) {
        lowestScore = score3;
    }

    average = (score1 + score2 + score3 - lowestScore) / 2;

    if (age < 20) {
        if (18 < age) {
            average = average + 1;
        }
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